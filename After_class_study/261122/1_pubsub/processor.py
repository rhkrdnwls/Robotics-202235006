import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from std.msgs.msg import Int32MultiArray
import time

class Processor(Node):
    def __init__(self):
        super().__init__('processor')
        self.x = 0
        self.y = 0


        self.subscription_ = self.create_subscription(String, '/direction', self.callback, 10)


        self.publisher_ = self.create_publisher(String, '/position', 10)
        self.get_logger().info(f'Processor 시작: 현재 위치 ({self.x}, {self.y})')

    def publish_message(self):
        elapsed = int(time.time() - self.start_time)
        msg = String()
        msg.data = f"Processor: {elapsed}"
        self.publisher_.publish(msg)
        self.get_logger().info(f'listener <-- "{msg.data}"')


    def callback(self, msg):
        key = msg.data
        if(key == "w"):
            self.x += 1
            self.y += 0
        elif(key == "a"):
            self.x -= 1
            self.y += 0
        elif(key == "s"):
            self.x += 0
            self.y -= 1
        elif(key== "d"):
            self.x += 1
            self.y += 0
        else:
            return
        out = Int32MultiArray()
        out.data [self.x, self.y]
        self.publish_.publish(out)
        self.get_logger().info(f'Recevied "{key}" --> 위치 ({self.x}, {self.y}) 전송')

        


def main():
    rclpy.init()
    node = Processor()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
