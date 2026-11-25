import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32MultiArray

class Subscriber(Node):
    def __init__(self):
        super().__init__('subscriber')
        self.subscription_ = self.create_subscription(Int32MultiArray, '/position', self.callback, 10)
        self.get_logger().info('Subscriber 시작: 위치를 기다리는 중')

    def callback(self, msg):
        x, y = msg.data
        self.get_logger().info(f'Current Robot pos: "({x}, {y})"')

def main():
    rclpy.init()
    node = Subscriber()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
