import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class Publisher(Node):
    # Node를 상속해야 한다.
    # Node는 ROS2가 미리 만들어둔 클래스 이걸 상속해야 create_publisher 같은 걸 사용이 가능하다.
    def __init__(self):
        super().__init__('publisher')
        self.publisher_ = self.create_publisher(String, '/direction', 10)
        # direction은 토픽 이름, 받는 쪽(Processor)도 똑같은 이름을 사용해야 통신이 된다.
        self.timer = self.create_timer(0.1, self.publish_message)
        # 0.1초마다 publish_message를 실행한다.
        # ()를 붙이지 않아서 지금 실행 x
        self.get_logger().info('Publisher 시작: w, s, a, d')
        # 터미널에 info() 로그 찍는다

    def publish_message(self):
        key = input('Direction (w, a, s, d): ').strip().lower()
        # input으로 키보드 입력

        msg = String() # 메시지 객체 생성
        # 괄호 -> 객체 생성을 의미한다.
        msg.data = key
        # 객체 안의 실제 변수 data에 값을 넣는다.
        self.publisher_.publish(msg)
        # 토픽 /direction으로 보낸다.
        self.get_logger().info(f'Publishing: "{msg.data}"')

def main():
    rclpy.init() # 통신 시작 준비
    node = Publisher() # 노드 객체 생성 -> __init__ 실행
    rclpy.spin(node) # 노드 계속 살리면서 타이머, 구독 콜백 처리하는 무한 루프
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()