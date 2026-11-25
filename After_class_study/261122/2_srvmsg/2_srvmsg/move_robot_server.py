from custom_interfaces.srv import MoveRobot
import rclpy
from rclpy.node import Node
import math

class MoveRobotServer(Node):
    def __init__(self):
        super().__init__('move_robot_server')

        self.srv = self.create_service(MoveRobot, '/move_robot', self.srv_callback)
        self.get_logger().info('Robot Server Ready.')

    def srv_callback(self, request, response):
        x = request.current_pose.x
        y = request.current_pose.y
        theta = request.current_pose.theta 
        distance = request.distance

        # 바라보는 방향(theta)으로 distance만큼 직진
        rad = math.radians(theta)            # cos, sin은 라디안을 받으므로 변환
        response.result_pose.x = x + distance * math.cos(rad)
        response.result_pose.y = y + distance * math.sin(rad)
        response.result_pose.theta = theta  # 방향은 그대로
        response.success = True
    
        
        self.get_logger().info(
            f'Incoming request  -> x: {x}, y: {y}, theta: {theta}, distance: {distance}')
        self.get_logger().info(
            f'Sending response  -> x: {response.result_pose.x:.3f}, '
            f'y: {response.result_pose.y:.3f}, theta: {response.result_pose.theta}, '
            f'success: {response.success}')

        return response

def main():
    rclpy.init()
    node = MoveRobotServer()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
