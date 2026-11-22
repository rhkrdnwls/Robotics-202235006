from custom_interfaces.srv import MoveRobot
import rclpy
from rclpy.node import Node
import math

class MoveRobotServer:
    def __init__(self):
        super().__init__('srv_server')

        self.srv = self.create_service(MoveRobot, '/move_robot', self.srv_callback)
        self.get_logger().info('robot Server Ready.')

    def srv_callback(self, request, response):
        response.result_pose.x = request.current_pose.x + request.distance * math.cos(request.distance)
        response.result_pose.y= request.current_pose.y + request.distance * math.sin(request.distance)
        response.result_pose.theta = request.current_pose.theta + request.distance
        response.success = True
    
        
        self.get_logger().info(f'Incoming request\nx: {request.current_pose.x}, y: {request.current_pose.y}. theta: {request.current_pose.theta}, distance: {request.distance}')
        self.get_logger().info(f'Sending back response\nx: [{response.result_pose.x}, y: {response.resultpose.y}, theta:{response.resultpose.theta}, boolean:{response.success}]')
        
        return response

def main():
    rclpy.init()
    node = MoveRobotServer()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
