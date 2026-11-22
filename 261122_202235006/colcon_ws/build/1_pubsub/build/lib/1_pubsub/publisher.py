import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import time

class Publisher:
    def __init__(self):
        super().__init__('publisher')
        self.publisher_ = self.create_publisher(String, '/demo_publisher', 10)
        self.start_time = time.time()
        self.timer = self.create_timer(1.0, self.publish_message)

    def publish_message(self):
        msg = String()
        msg.data = input("Direction (w, s, a, d)")
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: "{msg.data}"')

def main():
    rclpy.init()
    node = Publisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()