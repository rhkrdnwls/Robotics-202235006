# 자율주행 부트캠프 2주차: ROS2 노드 통신과 서비스

## 프로젝트 개요
- 실습 기간: 2026.11.21(토) ~ 2026.11.22(일)
- 작성자: 202235006 곽우진

---
## 1. ROS2 기본 개념

### 1.1 ROS2란
- ROS2(Robot Operating System 2)는 로봇 소프트웨어를 여러 개의 작은 프로그램으로 나누어 만들고, 이들이 서로 데이터를 주고받게 해주는 미들웨어이다.
- 1주차에서 다룬 High-Level(판단/계획) 영역에서 주로 사용한다.

### 1.2 기본 용어

| 용어 | 의미 |
|---|---|
| 노드 (Node) | ROS2에서 실행되는 하나의 프로그램 단위 |
| 토픽 (Topic) | 노드끼리 데이터를 주고받는 통로의 이름 |
| 메시지 (Message) | 토픽으로 주고받는 데이터의 형식 |
| 패키지 (Package) | 노드, 설정 파일 등을 묶어 관리하는 단위 |

### 1.3 turtlesim 실습
- turtlesim은 거북이를 움직이며 ROS2 통신을 연습하는 시뮬레이터이다.
- `turtlesim_node`가 거북이 화면을 띄우고, `turtle_teleop_key`가 키보드 입력을 토픽으로 보내 거북이를 움직인다.
- `ros2 topic echo /turtle1/pose`로 거북이의 현재 위치를 토픽에서 직접 확인할 수 있다.
- teleport 서비스를 호출하면 거북이를 원하는 위치로 즉시 옮길 수 있다.

## 2. 실습 키트 센서 테스트
- 실습 PCB에 연결된 LiDAR, 모터(바퀴), IMU 등을 테스트 코드로 동작시켜 보았다.
- 테스트 코드는 `sample_code/Arduino/` 폴더에 있으며, 1주차와 같은 방식으로 Arduino IDE에서 ESP32에 업로드한다.

---

## 3. Topic 통신: Publisher / Subscriber

### 3.1 개념
- Publisher는 토픽으로 메시지를 보내고, Subscriber는 같은 토픽을 구독해서 메시지를 받는다.
- 보내는 쪽과 받는 쪽은 토픽 이름과 메시지 타입이 모두 같아야 통신이 된다.
- 한 방향으로 계속 보내는 통신이므로 센서 데이터처럼 지속적으로 흐르는 데이터에 적합하다.

### 3.2 메시지 사용 방법
- `String` 같은 메시지 타입은 파이썬 문자열이 아니라 ROS2가 미리 정의한 객체이다.
- 객체를 먼저 생성한 뒤, 안쪽 변수(`data`)에 값을 넣어야 한다.

```python
msg = String()            # 메시지 객체 생성 (괄호 = 초기화)
msg.data = 'w'            # 안쪽 변수까지 들어가서 값 저장
self.publisher_.publish(msg)
```

### 3.3 타이머
- `create_timer(주기, 콜백)`을 사용하면 정해진 주기마다 콜백 함수가 자동으로 실행된다.
- 주기적으로 보낼 때는 타이머를, 메시지를 받았을 때 보낼 때는 Subscriber 콜백 안에서 publish한다.

### 3.4 로그
- `self.get_logger().info()`로 로그를 출력한다.
- 노드에서 무슨 일이 일어나는지 사람이 확인할 수 있어야 디버깅이 가능하다.
- 의미 없는 로그, 빠진 로그, 정보가 부족한 로그는 감점 요소이다.

---

## 4. 노드 클래스 구조

### 4.1 Node 상속
- ROS2 파이썬 노드는 `Node` 클래스를 상속해서 만든다.
- `Node`에는 토픽 통신, 타이머, 로그, 노드 등록 기능이 이미 들어 있어서, 상속하면 `self.create_publisher()`처럼 바로 사용할 수 있다.
- `super().__init__('노드이름')`으로 부모 생성자를 호출해야 노드 이름이 등록되고 노드로 동작한다.
- 클래스 하나가 노드 하나이다.

```python
class Publisher(Node):
    def __init__(self):
        super().__init__('publisher')
```

### 4.2 노드 실행 흐름

| 코드 | 의미 |
|---|---|
| `rclpy.init()` | ROS2 통신 시작 |
| `node = Publisher()` | 노드 객체 생성 |
| `rclpy.spin(node)` | 노드를 유지하며 콜백 처리 (Ctrl + C까지 반복) |
| `node.destroy_node()` | 노드 정리 |
| `rclpy.shutdown()` | ROS2 종료 |

---

## 5. 패키지와 빌드

### 5.1 워크스페이스 구조

```
colcon_ws/
├── src/        # 패키지를 만드는 곳
├── build/      # 빌드 결과물 (자동 생성)
├── install/    # 실행에 필요한 파일 (자동 생성)
└── log/        # 빌드 기록 (자동 생성)
```

### 5.2 빌드 순서
- 패키지 생성은 `src` 폴더에서 한다.
- 빌드(`colcon build`)는 워크스페이스 최상위에서 한다.
- 빌드 후 `source install/setup.bash`를 해야 현재 터미널이 새 패키지를 인식한다.

### 5.3 패키지 설정 파일

| 파일 | 역할 |
|---|---|
| `setup.py` | `entry_points`에 실행 이름을 등록한다. `ros2 run`에서 이 이름을 사용한다 |
| `package.xml` | 패키지 정보와 의존성을 적는다. 여기 적은 패키지만 import할 수 있다 |

---

## 6. Launch 파일

### 6.1 개념
- 여러 노드를 명령어 한 줄로 실행하기 위한 파일이다.
- 노드를 터미널마다 하나씩 `ros2 run`으로 실행하는 번거로움을 줄여준다.

### 6.2 작성 규칙
- 패키지 안에 `launch` 폴더를 만들고 그 안에 작성한다.
- 런치 파일은 파이썬 파일이며, 이름은 `이름.launch.py` 형식으로 짓는다.
  - ROS1에서 확장자가 `.launch`였던 것을 이어받는 의미가 있다.
  - 일반 노드 파일(`.py`)과 구분하기 위해서이다.
- XML로도 작성할 수 있지만, 조건문과 반복문을 쓸 수 있는 파이썬을 더 선호한다.
- 함수 이름 `generate_launch_description`은 고정이며, `LaunchDescription([...])`을 반환한다.
- `RegisterEventHandler`와 `OnProcessStart`로 노드의 실행 순서를 정할 수 있다.

### 6.3 setup.py 등록
빌드할 때 런치 파일이 `install` 폴더로 복사되도록 `data_files`에 추가한다.

```python
('share/' + package_name + '/launch', ['launch/런치파일.launch.py']),
```

- 튜플의 첫 번째는 복사할 위치, 두 번째는 복사할 파일 목록이다.

### 6.4 run과 launch 비교

| 명령어 | 실행 대상 |
|---|---|
| `ros2 run 패키지 실행이름` | 노드 하나 |
| `ros2 launch 패키지 런치파일.launch.py` | 런치 파일에 적힌 여러 노드 |

---

## 7. Service와 Action

### 7.1 Service
- 요청(Request)을 보내면 응답(Response)을 한 번 받는 통신이다.
- 노드가 서버(Server)와 클라이언트(Client)로 나뉜다.
- 서버가 먼저 실행되어 서비스를 준비하고 있어야 클라이언트가 요청할 수 있다.
- 상태 조회, 값 초기화, 계산 요청처럼 바로 끝나는 작업에 사용한다.
- 예: turtlesim의 reset, kill, spawn, teleport

### 7.2 Action
- 오래 걸리는 작업에 사용하는 통신이다. (예: 목적지까지 이동)
- 목표(Goal)를 보내면 진행 중에 피드백(Feedback)을 계속 받고, 끝나면 결과(Result)를 받는다.
- 진행 중에 취소할 수 있다.
- 이동이 중심인 자율주행에서 많이 사용한다.

### 7.3 통신 방식 비교

| | Topic | Service | Action |
|---|---|---|---|
| 방향 | 한 방향, 계속 전송 | 요청 → 응답 1회 | 목표 → 피드백 → 결과 |
| 역할 | Publisher / Subscriber | Client / Server | Client / Server |
| 적합한 작업 | 센서 데이터 전송 | 바로 끝나는 작업 | 오래 걸리는 작업 |
| 취소 | 해당 없음 | 불가 | 가능 |
| 정의 파일 | `.msg` | `.srv` | `.action` |

---

## 8. 커스텀 인터페이스

### 8.1 개념
- `String`, `Int32MultiArray` 같은 기본 타입 대신, 프로젝트에 맞는 메시지와 서비스를 직접 정의할 수 있다.
- 한 번 만들어 두면 다른 패키지에서도 재사용할 수 있다.

### 8.2 msg, srv, action 파일

| 파일 | 칸 수 | 구조 | 사용하는 통신 |
|---|---|---|---|
| `.msg` | 1 | 데이터 | Topic |
| `.srv` | 2 | 요청 `---` 응답 | Service |
| `.action` | 3 | 목표 `---` 결과 `---` 피드백 | Action |

- `.srv`와 `.action`은 `.msg`로 만든 타입을 부품처럼 가져다 쓸 수 있다.
- 파일 이름은 파스칼 케이스(`AddTwoInts`, `RobotPose`)로 짓는다.

### 8.3 인터페이스 패키지
- 메시지와 서비스 정의만 모아두는 `custom_interfaces` 패키지를 따로 만들었다. 이 패키지에는 코드가 없다.
- `.msg`, `.srv` 파일은 빌드할 때 파이썬과 C++ 코드로 자동 변환되며, 이 변환 도구가 CMake 기반이므로 `ament_cmake`로 패키지를 만든다.

| 파일 | 수정 내용 |
|---|---|
| `custom_interfaces/CMakeLists.txt` | 패키지 이름과 변환할 `.msg`, `.srv` 파일 목록 작성 |
| `custom_interfaces/package.xml` | 인터페이스 생성에 필요한 의존성 세 줄 추가 |
| `2_srvmsg/package.xml` | `<depend>custom_interfaces</depend>` 추가 (import하기 위해) |

### 8.4 값에 접근하는 방법
- 메시지 안에 다른 메시지가 들어 있으면, 점(`.`)으로 한 단계씩 들어가야 실제 값이 나온다.
- 해당 칸의 타입이 숫자이면 거기서 끝이고, 메시지이면 그 메시지 안으로 한 번 더 들어간다.

```
request.current_pose.x
   │         │        └── 실제 값 (float64)
   │         └─────────── RobotPose 메시지
   └───────────────────── 요청 전체
```

---

## 9. Service 코드 구조

### 9.1 서버

| 코드 | 의미 |
|---|---|
| `create_service(타입, 이름, 콜백)` | 서비스를 열고 요청을 기다린다 |
| `callback(self, request, response)` | 요청이 오면 실행된다. `request`는 받은 요청, `response`는 채워서 돌려줄 응답이다 |
| `return response` | 채운 응답을 클라이언트에게 돌려준다 |

### 9.2 클라이언트

| 코드 | 의미 |
|---|---|
| `create_client(타입, 이름)` | 서버와 같은 타입, 같은 이름으로 클라이언트를 만든다 |
| `wait_for_service(timeout_sec=1.0)` | 서버가 켜질 때까지 기다린다 |
| `타입.Request()` | 빈 요청 객체를 만든다 (`---` 위쪽) |
| `call_async(req)` | 요청을 비동기로 보낸다 |
| `future` | 아직 도착하지 않은 응답을 담는 객체이다 |
| `spin_until_future_complete` | 응답이 올 때까지만 기다린다 |
| `future.result()` | 도착한 응답을 꺼낸다 |
| `sys.argv` | 터미널에서 입력한 인자 목록이다. 0번은 실행 파일 이름이므로 1번부터 사용한다 |

### 9.3 요청과 응답의 흐름

| srv 칸 | 채우는 쪽 | 읽는 쪽 |
|---|---|---|
| `---` 위 (요청) | 클라이언트 | 서버 |
| `---` 아래 (응답) | 서버 | 클라이언트 |

---

## 10. 로봇 이동 계산

### 10.1 개념
로봇이 현재 위치 (x, y)에서 θ 방향을 바라보고 distance만큼 직진했을 때의 도착 위치를 계산한다.

```
new_x     = x + distance × cos(θ)
new_y     = y + distance × sin(θ)
new_theta = θ          (직진이므로 방향은 그대로)
```

- 이동 거리를 x 방향 성분과 y 방향 성분으로 나누면 각각 distance × cos θ, distance × sin θ가 된다.

### 10.2 각도 단위
- 파이썬의 `math.cos()`, `math.sin()`은 라디안을 입력으로 받는다.
- 각도를 도(°) 단위로 입력받는 경우 `math.radians()`로 변환한 뒤 계산해야 한다.

---

## 11. 주요 명령어와 함수

### 11.1 ROS2 명령어

| 명령어 | 설명 |
|---|---|
| `ros2 run 패키지 실행이름` | 노드 하나 실행 |
| `ros2 launch 패키지 런치파일` | 런치 파일 실행 |
| `ros2 node list` | 실행 중인 노드 목록 |
| `ros2 topic list` | 현재 토픽 목록 |
| `ros2 topic echo 토픽이름` | 토픽으로 오가는 메시지 출력 |
| `colcon build` | 워크스페이스 빌드 |
| `source install/setup.bash` | 빌드한 패키지를 터미널에 등록 |

- 명령어 뒤에서 Tab을 두 번 누르면 입력할 수 있는 이름 목록이 나온다.

### 11.2 rclpy 주요 함수

| 함수 | 설명 |
|---|---|
| `create_publisher(타입, 토픽, 큐크기)` | 토픽으로 보내는 Publisher 생성 |
| `create_subscription(타입, 토픽, 콜백, 큐크기)` | 토픽을 받는 Subscriber 생성 |
| `create_timer(주기, 콜백)` | 주기마다 콜백 실행 |
| `create_service(타입, 이름, 콜백)` | 서비스 서버 생성 |
| `create_client(타입, 이름)` | 서비스 클라이언트 생성 |
| `get_logger().info()` / `.warn()` | 로그 출력 |

---

## 12. 파일 구조

```
Robotics-202235006/
├── 261121_202235006/                 # 1일차 (11/21)
│   ├── 1_pubsub/                     # talker / listener 패키지
│   ├── sample_code/
│   │   ├── Arduino/                  # buzzer, imu, lidar, motor, servo 테스트
│   │   ├── Latex/
│   │   └── ROS/1/                    # talker, listener 샘플
│   ├── Ros2Info.png
│   ├── TurtleTeleport.png
│   ├── ros2topicpose.png
│   └── tuetleEmpty.png
└── 261122_202235006/                 # 2일차 (11/22)
    └── colcon_ws/
        └── src/
            ├── 1_pubsub/
            │   ├── 1_pubsub/
            │   │   ├── talker.py
            │   │   ├── listener.py
            │   │   ├── publisher.py
            │   │   ├── processor.py
            │   │   └── subscriber.py
            │   ├── launch/
            │   ├── package.xml
            │   └── setup.py
            ├── 2_srvmsg/
            │   ├── 2_srvmsg/
            │   │   ├── add_ints_server.py
            │   │   ├── add_ints_client.py
            │   │   ├── move_robot_server.py
            │   │   └── move_robot_client.py
            │   ├── package.xml
            │   └── setup.py
            └── custom_interfaces/
                ├── msg/
                │   ├── Num.msg
                │   └── RobotPose.msg
                ├── srv/
                │   ├── AddTwoInts.srv
                │   └── MoveRobot.srv
                ├── CMakeLists.txt
                └── package.xml
```

### 12.1 2일차 주요 파일

| 파일 | 설명 |
|---|---|
| `publisher.py` | 키보드로 w, a, s, d를 입력받아 토픽으로 보낸다 |
| `processor.py` | 방향을 받아 로봇 위치를 계산하고 [x, y]를 보낸다 |
| `subscriber.py` | 계산된 위치를 받아 출력한다 |
| `launch/` | 노드 여러 개를 한 번에 실행하는 런치 파일 |
| `add_ints_server.py` / `add_ints_client.py` | 두 정수를 더하는 서비스 서버 / 클라이언트 |
| `move_robot_server.py` / `move_robot_client.py` | 로봇 이동 위치를 계산하는 서비스 서버 / 클라이언트 |
| `Num.msg` | 정수 하나(`int64 my_num`)를 담는 메시지 |
| `RobotPose.msg` | 로봇 자세(`float64 x, y, theta`)를 담는 메시지 |
| `AddTwoInts.srv` | 요청: `Num a, b` / 응답: `Num sum` |
| `MoveRobot.srv` | 요청: `RobotPose current_pose, float64 distance` / 응답: `RobotPose result_pose, bool success` |

---

## 13. 개발 환경 및 의존성

| 항목 | 내용 |
|---|---|
| OS | Ubuntu (수업 실습 PC 환경) |
| 미들웨어 | ROS2 (수업 실습 PC 환경) |
| 빌드 도구 | colcon |
| 언어 | Python 3 |
| ROS2 패키지 | rclpy, std_msgs, turtlesim, rosidl_default_generators |
| IDE | VS Code, Arduino IDE 2.x |

---

## 14. 실행 방법

### 14.1 레포 다운로드와 빌드

```bash
git clone https://github.com/rhkrdnwls/Robotics-202235006.git
cd Robotics-202235006/261122_202235006/colcon_ws
rm -rf build install log  
colcon build
source install/setup.bash
```

- 새 터미널을 열 때마다 `source install/setup.bash`를 먼저 실행한다.

### 14.2 turtlesim (1일차)

```bash
ros2 run turtlesim turtlesim_node      # 터미널 1
ros2 run turtlesim turtle_teleop_key   # 터미널 2
```

### 14.3 Topic: 로봇 위치 계산 (2일차)

```bash
ros2 run 1_pubsub subscriber    # 터미널 1
ros2 run 1_pubsub processor     # 터미널 2
ros2 run 1_pubsub publisher     # 터미널 3: w, a, s, d 입력
```

런치 파일로 실행:

```bash
ros2 launch 1_pubsub 런치파일.launch.py
```

### 14.4 Service: 두 수 더하기

```bash
ros2 run 2_srvmsg add_ints_server          # 터미널 1
ros2 run 2_srvmsg add_ints_client 2 7      # 터미널 2: 결과 9
```

### 14.5 Service: 로봇 이동

```bash
ros2 run 2_srvmsg move_robot_server                   # 터미널 1
ros2 run 2_srvmsg move_robot_client 1.2 0.8 30 1.2    # 터미널 2: x y theta(도) distance
```

---

## 15. 진행 과정

### 15.1 1일차
1. ROS2 기본 개념 학습
2. turtlesim으로 토픽과 서비스 확인
3. ROS2 패키지 생성 및 talker / listener 실행
4. 실습 키트의 LiDAR, 모터 등 센서 테스트

### 15.2 2일차
1. Publisher / Subscriber 복습
2. Publisher, Processor, Subscriber 노드 3개로 로봇 위치 계산 실습
3. Launch 파일 작성
4. Service와 Action 개념 학습
5. 커스텀 메시지(`Num`)와 서비스(`AddTwoInts`) 작성, 두 수 더하기 서비스 실행
6. 커스텀 메시지(`RobotPose`)와 서비스(`MoveRobot`) 작성, 로봇 이동 서비스 구현

---

## 16. 결과 분석


### 16.1 실습 결과

| 실습 | 결과 |
|---|---|
| turtlesim | 성공 |
| talker / listener | 성공 |
| 센서 테스트 (LiDAR, 모터 등) | 성공 |
| Publisher / Processor / Subscriber | 수업 시간 내 미완성 |
| Launch 파일 | 성공 |
| 두 수 더하기 서비스 | 성공 |
| 로봇 이동 서비스 | 수업 시간 내 미완성 |

### 16.2 문제점과 원인

| 문제 | 원인 | 해결 / 보완 |
|---|---|---|
| 노드 실행 시 바로 에러 발생 | 클래스에서 `Node` 상속(`class 이름(Node):`)을 빠뜨렸다 | 모든 노드 클래스가 `Node`를 상속하도록 수정했다 |
| Processor에서 방향을 인식하지 못함 | `msg == "w"`처럼 메시지 객체를 문자열과 직접 비교했다 | 실제 값이 들어 있는 `msg.data`로 비교하도록 수정했다 |
| Subscriber가 메시지를 받지 못함 | Processor가 보내는 토픽 이름과 Subscriber가 구독하는 토픽 이름이 달랐다 | 토픽 이름과 메시지 타입을 양쪽에서 같게 맞췄다 |
| 계산한 위치가 전달되지 않음 | Processor가 위치를 계산만 하고 publish하지 않았다 | 콜백에서 계산 후 `Int32MultiArray`로 publish하도록 수정했다 |
| 메시지 import 에러 | `std.msgs`, `int`처럼 잘못된 모듈과 타입 이름을 썼다 | `from std_msgs.msg import Int32MultiArray`로 수정했다 |
| 로봇 이동 결과가 맞지 않음 | cos, sin에 각도 대신 거리를 넣었고, 각도에 거리를 더했다 | 각도를 라디안으로 변환해 cos, sin에 넣고, 각도는 그대로 두도록 수정했다 |
| 응답 값을 출력할 때 에러 | 응답에 없는 요청 칸 이름(`current_pose`, `distance`)과 오타(`resultpose`)를 사용했다 | 응답 칸 이름(`result_pose`, `success`)으로 수정했다 |

### 16.3 보완할 점
- Publisher, Subscriber, Processor 코드와 로봇 이동 서비스 코드를 수업 시간 안에 완성하지 못했다. 파이썬 클래스 구조와 ROS2 노드 구조에 익숙하지 않았던 것이 원인이며, 수업 이후 오류를 수정했다.
- 메시지 안에 메시지가 들어 있는 구조(`request.current_pose.x`)를 이해하지 못해 값을 잘못 꺼내는 실수가 있었다. 코드를 작성하기 전에 `.msg`, `.srv` 파일을 먼저 확인해야 한다.
- 보내는 노드와 받는 노드의 토픽 이름, 서비스 이름, 메시지 타입을 항상 함께 확인해야 한다.
- 삼각함수를 사용할 때는 각도 단위(도, 라디안)를 확인해야 한다.
- 빌드 결과물(`build/`, `install/`, `log/`)이 GitHub에 함께 올라가 다른 컴퓨터에서 받을 때 경로 길이 문제가 발생했다. `.gitignore`로 빌드 결과물을 제외해야 한다.
- 2주차에는 노드 통신과 서비스까지 진행했으며, 실제 주행은 이후 실습에서 진행한다.