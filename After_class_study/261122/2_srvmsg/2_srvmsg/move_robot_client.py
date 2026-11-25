import sys
import rclpy
from rclpy.node import Node
from custom_interfaces.srv import MoveRobot


class MoveRobotClient(Node):
    def __init__(self):
        super().__init__('move_robot_client')
        self.cli = self.create_client(MoveRobot, '/move_robot')
        
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for service...')
            
        self.req = MoveRobot.Request()
        # 요청 상자 미리 만든다.

    def send_request(self, x, y, theta, distance):
        # 요청 채워서 보낸다.
        self.req.current_pose.x = float(x)
        self.req.current_pose.y = float(y)
        self.req.current_pose.theta = float(theta)
        self.req.distance = float(distance)

        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)

        return self.future.result()

def main():
    rclpy.init()
    client = MoveRobotClient()
    response = client.send_request(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
    client.get_logger().info(
        f'Result -> x: {response.result_pose.x:.3f}, y: {response.result_pose.y:.3f}, '
        f'theta: {response.result_pose.theta}, success: {response.success}')

    client.destroy_node()
    rclpy.shutdown()