import sys
import rclpy
from rclpy.node import Node
from custom_interfaces.srv import MoveRobot


class MoveRobotClient:
    def __init__(self):
        super().__init__('srv_client')
        self.cli = self.create_client(MoveRobot, '/move_robot')
        
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for service...')
            
        self.req = MoveRobot.Request()

    def send_request(self, a, b, c, d):
        self.req.current_pose.x = float(a)
        self.req.current_pose.y = float(b)
        self.req.current_pose.theta = float(c)
        self.req.distance = float(d)
        
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        
        return self.future.result()

def main():
    rclpy.init()
    client = MoveRobotClient()
    response = client.send_request(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
    client.get_logger().info(f'{response.currentpose.x, response.currentpose.y, response.currentpose.theta, response.distance}')
    client.destroy_node()
    rclpy.shutdown()