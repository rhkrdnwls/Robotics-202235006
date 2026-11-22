import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from std.msgs.msg import int
import time

class Processor(Node):
    def __init__(self):
        super().__init__('processor')
        self.x = 0
        self.y = 0


        self.subscription_ = self.create_subscription(String, '/demo_publisher', self.callback, 10)
        self.subscription_


        self.publisher_ = self.create_publisher(String, '/demo_processor', 10)
        self.start_time = time.time()
        self.timer = self.create_timer(1.0, self.publish_message)

    def publish_message(self):
        elapsed = int(time.time() - self.start_time)
        msg = String()
        msg.data = f"Processor: {elapsed}"
        self.publisher_.publish(msg)
        self.get_logger().info(f'listener <-- "{msg.data}"')


    def callback(self, msg):
        if(msg == "w"):
            self.x += 1
            self.y += 0
        elif(msg == "a"):
            self.x -= 1
            self.y += 0
        elif(msg == "s"):
            self.x += 0
            self.y -= 1
        elif(msg== "d"):
            self.x += 1
            self.y += 0
        else:
            return

        


def main():
    rclpy.init()
    node = Processor()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
