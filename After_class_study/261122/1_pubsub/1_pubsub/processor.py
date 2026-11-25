import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from std.msgs.msg import Int32MultiArray
# int32MultiArray: 32비트 정수 여러 개를 한 번에 담는 타입 ([x, y] 두 값을 보내야 해서 사용)
import time

class Processor(Node):
    # 받기 보내기 둘 다 하는 노드
    def __init__(self):
        super().__init__('processor') # 노드 이름 processor
        # self.x, self.y 로봇의 현재 위치 시작점은 (0,0)
        self.x = 0
        self.y = 0


        self.subscription_ = self.create_subscription(String, '/direction', self.callback, 10)
        # 메시지 도착할 때마다 콜백이 자동으로 불린다.


        self.publisher_ = self.create_publisher(String, '/position', 10)
        # /diretion을 받는 순간에만 position으로 보내면 되니 타이머를 설정해 그 시간마다 보낼 이유 없다.
        self.get_logger().info(f'Processor 시작: 현재 위치 ({self.x}, {self.y})')

    def publish_message(self):
        elapsed = int(time.time() - self.start_time)
        msg = String()
        msg.data = f"Processor: {elapsed}"
        self.publisher_.publish(msg)
        self.get_logger().info(f'listener <-- "{msg.data}"')


    def callback(self, msg):
        # 방향 받아 계산
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
        out.data = [self.x, self.y]
        self.publish_.publish(out) # 계산한 위치를 토픽 /position으로 실제로 보낸다.
        self.get_logger().info(f'Recevied "{key}" --> 위치 ({self.x}, {self.y}) 전송')

        


def main():
    rclpy.init()
    node = Processor()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
