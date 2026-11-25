# Robotics-202235006
# 자율주행 부트캠프 1주차
## 프로젝트 개요
- 실습 기간: 2026.11.14(토) ~ 2026.11.15(일)
- 작성자: 202235006 곽우진

---

## 1. 로봇 구동 시스템: High-Level / Low-Level

### 1.1 개념
- High-Level(고수준): "어디로 갈지" 판단하는 일이다. 연산량이 많고, 주기가 느리고 일정하지 않아도 된다.
- Low-Level(저수준): "모터를 지금 얼마나 돌릴지" 직접 제어하는 일이다. 연산은 가볍지만 짧고 일정한 주기로 즉각 반응해야 한다.

### 1.2 High-Level Decision-Making
- 센서 데이터 처리 및 주변 환경 인식 (Perception)
- Localization / Mapping / SLAM
- Path Planning 및 Navigation
- 카메라, LiDAR 같은 대용량 센서 데이터 처리
- ROS2 기반 여러 노드 실행
- 높은 연산 성능과 메모리가 필요하다.

### 1.3 Low-Level Control
- 센서 데이터 수집 및 전처리 (IMU, 초음파 등)
- 짧고 일정한 주기로 제어한다. 즉각적으로 반응해서 모터에 명령을 보내야 하기 때문이다.
- 메모리가 매우 제한적이다. (바이트~킬로바이트 수준)

### 1.4 분리하는 이유
- 고수준은 많은 연산량이 필요하다.
- 저수준은 빠르고 일정한 제어 주기가 필요하다.
- 역할을 나누면 각 하드웨어의 장점을 모두 살릴 수 있다.

## 2. Linux와 CLI

### 2.1 로보틱스에서 Linux를 쓰는 이유
- 높은 개발 자유도
- 강력한 패키지 관리
- ROS2 생태계
- 광범위한 활용

→ 로보틱스에서 Linux는 필수이다.

### 2.2 터미널 프롬프트 읽는 법

```
user_name@host_name:~/parent_directory/current_directory$
```

| 기호 | 의미 |
|---|---|
| `user_name` | 현재 로그인한 사용자 |
| `@` | 사용자와 컴퓨터를 구분 |
| `host_name` | 현재 접속한 컴퓨터 이름 |
| `~` | 홈 디렉토리 (`~` = `$HOME` = `/home/사용자이름`) |
| `/` | 폴더와 폴더 구분 |
| `$` | 일반 사용자 권한 (관리자 root는 `#`) |

절대 경로와 상대 경로
- `/`로 시작하면 절대 경로이다. 최상위 root(`/`)부터 찾아간다. (`/opt/arduino-ide`)
- `/` 없이 시작하면 상대 경로이다. 현재 위치부터 찾아간다. (`folder1/folder2`)

### 2.3 기본 명령어

| 명령어 | 뜻 | 설명 / 예시 |
|---|---|---|
| `pwd` | print working directory | 현재 위치를 절대 경로로 출력 |
| `ls` | list | 파일 목록 출력 |
| `cd` | change directory | 폴더 이동. `cd ..`은 상위 폴더로 이동 |
| `mkdir` | make directory | 폴더 생성 |
| `touch` | | 빈 파일 생성 |
| `cp` | copy | 파일 복사. `cp test.py ./test.py.backup` |
| `mv` | move | 이동 또는 이름 변경 |
| `rm` | remove | 파일 삭제. `rm -r`은 폴더와 안의 내용 전부 삭제 |
| `echo` | | 입력한 내용을 그대로 출력 |
| `ping` | | 네트워크 상대가 응답하는지 확인 |
| `sudo` | | 관리자 권한으로 실행 |
| `sudo apt update` | | 새 버전 목록을 받아옴 (강사님 비유: 중국집 새 메뉴판 받아오기) |
| `sudo apt upgrade` | | 받아온 목록을 기준으로 실제 패키지를 최신 버전으로 업그레이드 |
| `sudo apt install 패키지` | | 패키지 설치 |

## 3. 임베디드 시스템 기초

### 3.1 임베디드 시스템이란
- 특정 기능을 수행하도록 설계된 시스템이다.
- 센서와 액추에이터(모터 등)에 직접 연결되어 물리적 환경과 상호작용한다.
- 자동차 제어 시스템, 산업용 로봇, IoT 기기, 의료기기 등에 활용된다.
- 연산량이 낮고 자원(CPU, 메모리)이 제한적이지만, 실시간 처리와 제어에 적합하다.

### 3.2 MCU란
- Micro Controller Unit의 약자로, 저수준 연산을 담당하는 작은 컴퓨터 칩이다.
- MCU가 하는 일은 0과 1을 조작해서 전기를 내보내거나(출력) 전기를 느끼는(입력) 것이다.

### 3.3 기초 용어 지도

| 분류 | 용어 |
|---|---|
| 전기적 기초 | Voltage, Current, VCC, GND |
| 신호의 종류 | Analog, Digital |
| 디지털 신호 해석 | High, Low, Logic Level |
| MCU 입출력 | GPIO, Input/Output |
| 디지털 출력 응용 | PWM, Duty Cycle, Frequency |
| 아날로그 입출력 | ADC / DAC |
| 외부 장치 통신 | UART, I2C, SPI |

---

## 4. 전기 기초: 전압·전류·저항과 옴의 법칙 (V = IR)

### 4.1 전압·전류·저항

| 기호 | 이름 | 단위 | 의미 | 물 비유 |
|---|---|---|---|---|
| V | 전압 (Voltage) | 볼트 V | 전하를 밀어주는 힘, 두 지점의 전기적 높이 차이 | 수압, 물탱크 높이 차 |
| I | 전류 (Current) | 암페어 A | 1초 동안 흐르는 전하의 양 | 흐르는 물의 양 |
| R | 저항 (Resistance) | 옴 Ω | 전류의 흐름을 방해하는 정도 | 관의 가늘기 |

### 4.2 옴의 법칙

$$V = I \times R$$

- 저항에 전류 I가 흐르면 저항 양 끝에 IR만큼 전압이 걸린다. (전압 강하)

### 4.3 VCC와 GND
- GND(Ground, 접지)는 회로의 기준점인 0V이다. 해발 고도의 "해수면" 역할을 한다.
- VCC는 회로에 공급되는 전원 전압(5V, 3.3V 등)이다. "5V"는 GND보다 5V 높다는 뜻이다.
- 전류는 높은 전압(+)에서 낮은 전압(−)으로 흐른다.
- 보통 빨강은 VCC(+), 검정은 GND(−)로 구분한다.

### 4.4 전류의 위험성
- 위험도를 결정하는 것은 전류의 양이다.
- 과전류는 전자 부품을 태우고 고장 낸다. 역전류도 마찬가지로 위험하다.
- 따라서 회로에서는 저항을 사용해 전류를 제어한다.

---

## 5. MCU 핀 구성

### 5.1 개발 보드 핀 구성 (WeMos D1 R32 / ESP32)

| 핀 | 역할 |
|---|---|
| 5V, 3V3, GND | 센서·모터 등 외부 부품에 전원을 공급 |
| VIN | USB 대신 외부 전원(배터리 등)을 보드로 넣는 핀 |
| DIGITAL | `digitalWrite` / `digitalRead`에 쓰는 일반 디지털 핀 |
| ANALOG | `analogRead`에 쓰는 ADC 핀 |

### 5.2 아두이노 코드 구조

```cpp
void setup() {             // 전원이 켜지면 한 번만 실행되는 초기 설정
}

void loop() {              // 전원이 꺼질 때까지 무한 반복 (슈퍼 루프)
}
```

## 6. 디지털 입력: 버튼, 풀다운/풀업

### 6.1 핀은 "전압 센서"
핀은 전압을 감지하는 센서이다. 입력 핀은 그 지점의 전압이 HIGH(로직 레벨 근처, 5V 또는 3.3V)인지 LOW(0V 근처)인지만 판단한다.

### 6.2 풀다운 / 풀업

| | 풀다운 | 풀업 |
|---|---|---|
| 저항 연결 | 핀 ↔ GND | 핀 ↔ VCC |
| 기본 상태 | LOW | HIGH |
| 눌렀을 때 | HIGH | LOW |

---

## 7. 시리얼 통신

### 7.1 직렬 vs 병렬
- 직렬(Serial) 통신은 선 하나로 데이터를 한 비트씩 순서대로 보낸다. 문자 `A`도 실제로는 ASCII 코드(0x41 = 01000001)를 비트 단위로 하나씩 전송한다.
- 병렬(Parallel) 통신은 선 여러 개로 여러 비트를 동시에 보낸다.
- USB(Universal Serial Bus)는 범용 직렬 통신의 버스(데이터가 오가는 통로)로, USB도 직렬 통신이다.
- MCU의 기본 시리얼 통신 방식을 UART라고 한다.

---

### 7.2 Baud Rate
- Baud rate는 1초에 보내는 비트 수(bit/s)로, 시리얼 통신의 속도이다.
- 보내는 쪽(MCU)과 받는 쪽(컴퓨터)의 baud rate가 반드시 같아야 한다.
- baud rate가 다르면 데이터가 중간에 빠지거나 잘못 해석되어 시리얼 모니터에 글자가 깨져서 나온다.
- 보통 9600 또는 115200을 사용.


## 8. 감지 및 Bouncing

### 8.1 누르는 순간 감지하기
버튼을 한 번 누를 때마다 LED를 켜고 끄는(토글) 동작을 만들려면, 버튼 신호가 바뀌는 순간을 감지해야 한다.

- Rising Edge: LOW → HIGH로 올라가는 순간 (풀다운 기준, 누르는 순간)
- Falling Edge: HIGH → LOW로 내려가는 순간 (떼는 순간)

이전 상태(previous)를 저장해두고 현재 상태(current)와 비교하는 방식으로 감지한다.

### 8.2 바운싱 (Bouncing)
- 이상적인 버튼은 누르는 순간 LOW → HIGH로 바로 바뀐다.
- 실제 버튼은 내부 금속 접점이 붙는 순간 튕기면서, 전압이 HIGH와 LOW 사이를 여러 번 오간다. 이 현상을 바운싱이라고 한다.
- 바운싱이 생기면 버튼을 한 번 눌렀는데도 엣지가 여러 번 감지되어, 토글 동작에서 LED가 여러 번 켜졌다 꺼질 수 있다.

```
이상적인 신호:   LOW ____|▔▔▔▔▔▔▔▔ HIGH
실제 신호:      LOW ____|▔|_|▔|_|▔▔▔▔▔ HIGH  ← 튕기는 구간
```

### 8.3 디바운싱 (Debouncing)
- 바운싱으로 생긴 짧은 신호 변화를 무시하는 처리이다.
- 엣지를 감지한 뒤 일정 시간(수십 ms) 동안 들어오는 변화는 무시하는 방식으로 구현할 수 있다.
- Tinkercad 시뮬레이션에서는 바운싱이 발생하지 않지만, 실제 하드웨어에서는 반드시 고려해야 한다.

## 9. 아날로그 입력: 가변저항과 ADC

### 9.1 아날로그 vs 디지털
- 아날로그는 연속적인 값이다. (현실 세계의 전압, 소리(dB), 온도 등)
- 디지털은 0과 1, 또는 정해진 단계로 이산화된 값이다.
- MCU는 연속적인 값을 그대로 표현하거나 읽을 수 없으므로 변환이 필요하다.

### 9.2 ADC (Analog-to-Digital Converter)
- 연속적인 아날로그 전압을 일정한 칸으로 쪼개서 정수로 바꿔주는 장치이다.
- 해상도(비트 수)에 따라 칸의 개수가 정해진다.

| 해상도 | 범위 |
|---|---|
| 8비트 | 0 ~ 255 (2⁸ − 1) |
| 10비트 | 0 ~ 1023 (2¹⁰ − 1) |
| 12비트 | 0 ~ 4095 (2¹² − 1) |

---

## 10. PWM과 Duty Cycle

### 10.1 LED 밝기 조절
LED 밝기는 전압을 바꾸는 방식이 아니라 디지털 방식(PWM)으로 조절한다.

### 10.2 Duty Cycle
Duty Cycle은 한 주기 중 켜져 있는(HIGH) 시간의 비율이다.

```
Duty 25%:  ▔|____|▔|____|      → 어두움
Duty 50%:  ▔▔|__|▔▔|__|        → 중간 밝기
Duty 100%: ▔▔▔▔▔▔▔▔▔▔          → 최대 밝기 (계속 켜짐)
```

- Frequency(주파수): 1초에 반복되는 주기의 수 (Hz)

## 11. LiDAR
- 레이저로 거리를 측정하는 센서이다. 회전하면서 레이저를 쏘아 주변 360° 거리를 측정한다.

---

## 12. Tinkercad 실습 정리

### 12.1 5V와 GND
전압은 두 지점 사이의 "차이"이다. 높이를 재려면 해수면 같은 기준이 필요하듯, 전기에도 기준점이 필요하다.

| | 5V | GND |
|---|---|---|
| 전압 | 5V (높은 쪽) | 0V (기준, 낮은 쪽) |
| 역할 | 전류가 나오는 쪽 | 전류가 돌아오는 쪽 |
| 극성 | + (양극) | − (음극) |
| 물 비유 | 높은 곳의 물탱크 | 물이 흘러 내려가는 바닥 |
| 선 색 | 빨간색 | 검은색 |

### 12.2 브레드보드 +/− 줄 (전원 레일)
- 브레드보드 양쪽 가장자리에 빨간 선(+)과 파란 선(−) 줄이 있다.
- 한 줄의 구멍들은 가로로 전부 연결되어 있다.
- 아두이노 5V를 + 줄에, GND를 − 줄에 한 번만 연결하면 그 줄 어디서든 전원을 꺼내 쓸 수 있다. (멀티탭 역할)

---

## 13. 아두이노 주요 함수

### 13.1 기본 구조

| 함수 | 설명 |
|---|---|
| `setup()` | 전원이 켜지면 한 번만 실행. 핀 설정, 통신 시작 등 초기 설정 |
| `loop()` | 전원이 꺼질 때까지 계속 반복 실행 (슈퍼 루프) |
| `delay(ms)` | 지정한 시간(ms)만큼 대기. `delay(1000)` = 1초 |

### 13.2 핀 설정

| 함수 | 설명 | 예시 |
|---|---|---|
| `pinMode(핀, 모드)` | 핀을 입력 또는 출력으로 설정 | `pinMode(2, INPUT);` / `pinMode(7, OUTPUT);` |

- INPUT: 입력 (버튼 등)
- OUTPUT: 출력 (LED 등)
- INPUT_PULLUP: 내부 풀업 저항을 사용하는 입력 (안 누르면 HIGH, 누르면 LOW)
- 아날로그 입력(analogRead)은 pinMode 설정이 필요 없다.

### 13.3 디지털 입출력

| 함수 | 설명 | 값 | 예시 |
|---|---|---|---|
| `digitalWrite(핀, 값)` | 핀에 HIGH 또는 LOW 출력 | HIGH(1) / LOW(0) | `digitalWrite(7, HIGH);` |
| `digitalRead(핀)` | 핀의 상태를 읽음 | HIGH(1) / LOW(0) | `int state = digitalRead(2);` |

- digitalWrite: HIGH이면 핀에서 전압이 나가고(LED 켜짐), LOW이면 0V가 된다(LED 꺼짐).
- digitalRead: 핀 전압이 높으면 HIGH, 낮으면 LOW를 반환한다.
- HIGH, LOW는 미리 정의된 정수 상수이므로 결과를 int로 받는다.

### 13.4 아날로그 입출력

| 함수 | 설명 | 값 범위 | 예시 |
|---|---|---|---|
| `analogRead(핀)` | 아날로그 전압을 ADC로 읽어 정수로 변환 | 아두이노 0~1023 (10비트), ESP32 0~4095 (12비트) | `int value = analogRead(A2);` |
| `analogWrite(핀, 값)` | PWM으로 출력 (LED 밝기 조절 등) | 0~255 (8비트) | `analogWrite(9, 128);` |

- analogWrite는 이름과 달리 실제로는 PWM 방식(빠르게 켰다 껐다)으로 동작한다.
- 0은 항상 꺼짐, 128은 약 50% duty, 255는 항상 켜짐이다.
- PWM은 `~` 표시가 있는 핀에서만 사용할 수 있다.

### 13.5 값 변환

| 함수 | 설명 | 예시 |
|---|---|---|
| `map(값, 입력최소, 입력최대, 출력최소, 출력최대)` | 한 범위의 값을 다른 범위로 비례 변환 | `map(value, 0, 1023, 0, 255)` |

- analogRead(0~1023) 값을 analogWrite(0~255)에 넣을 때 사용한다.
- 서보 각도로 변환할 때: `map(value, 0, 4095, 0, 180)`

### 13.6 시리얼 통신

| 함수 | 설명 | 예시 |
|---|---|---|
| `Serial.begin(속도)` | 시리얼 통신 시작, baud rate 설정 | `Serial.begin(115200);` |
| `Serial.print(값)` | 줄바꿈 없이 출력 | `Serial.print(value);` |
| `Serial.println(값)` | 출력 후 줄바꿈 | `Serial.println("pressed");` |

- 시리얼 모니터의 baud rate를 코드와 같게 맞춰야 글자가 깨지지 않는다.

### 13.7 상수 정의

| 방법 | 예시 | 특징 |
|---|---|---|
| `const int` | `const int ledPin = 7;` | 변하지 않는 정수 변수 |
| `#define` | `#define BUZZER_PIN 5` | 매크로. 세미콜론(;)과 `=`를 쓰지 않음 |

### 13.8 서보 모터 (ESP32Servo 라이브러리)

| 코드 | 설명 |
|---|---|
| `#include <ESP32Servo.h>` | 서보 라이브러리 불러오기 |
| `Servo myServo;` | 서보 객체 생성 |
| `myServo.attach(핀);` | 서보를 핀에 연결 (setup에서) |
| `myServo.write(각도);` | 서보를 해당 각도(0~180)로 이동 |

---

## 14. 실습 부품

### 14.1 LED (Light Emitting Diode, 발광 다이오드)
- 전류가 흐르면 빛을 내는 부품이다.
- 방향(극성)이 있다.
  - 긴 다리: + (애노드, Anode) → 디지털 핀 / 저항 쪽
  - 짧은 다리: − (캐소드, Cathode) → GND 쪽
  - 반대로 연결하면 켜지지 않는다.
- 저항과 직렬로 연결해서 사용한다.

### 14.2 저항 (Resistor)
- 전류의 흐름을 막아 전류의 양을 조절하는 부품이다.
- 방향(극성)이 없다.

| 저항값 | 사용한 곳 | 역할 |
|---|---|---|
| 220Ω | LED와 직렬 | 전류 제한 (LED 보호) |
| 10kΩ | 버튼 입력 핀과 GND 사이 | 풀다운 저항 (안 눌렀을 때 LOW로 고정) |

- 220Ω: (5V − 2V) / 220Ω ≈ 14mA로, LED에 적당한 전류가 흐른다.
- 10kΩ: 5V / 10kΩ = 0.5mA로, 버튼을 눌러도 아주 작은 전류만 흘러 쇼트가 발생하지 않는다.

### 14.3 푸시 버튼 (Push Button)
- 누르면 연결되고, 떼면 끊어지는 부품이다.
- 다리가 4개이고, 내부는 사다리 타기 구조이다.
  - 마주 보는 다리끼리는 항상 연결되어 있다.
  - 누르면 양쪽 다리 쌍이 연결된다.

### 14.4 가변저항 (Potentiometer, 포텐셔미터)
- 돌리면 저항값이 바뀌는 저항이다.
- 다리가 3개이다.

| 다리 | 연결 |
|---|---|
| 왼쪽 | GND |
| 가운데 | 아날로그 핀 (출력) |
| 오른쪽 | VCC (5V / 3.3V) |

- 돌리면 저항값이 바뀌고, 가운데 핀의 전압이 0V ~ VCC 사이에서 연속적으로 변한다.
- MCU는 전류가 아니라 전압을 측정하므로, 이 전압 변화를 analogRead로 읽는다.
- 읽은 값의 범위는 아두이노 0~1023, ESP32 0~4095이다.

## 15. 파일 구조

```
Robotics_202235006/
├── README.md
├── 261114_202235006/          # 1일차 (11/14)
│   ├── legPin.png
│   └── legPinCode.txt
└── 261115_202235006/          # 2일차 (11/15)
    ├── Button.png
    ├── Button.txt
    ├── ButtonLed.png
    ├── ButtonLed.txt
    ├── PotentiometerLed.png
    ├── PotentiometerLed.txt
    ├── Buzzer.txt
    ├── readvalue.txt
    ├── movepantozeroto180.txt
    └── PotentiometerPan.txt
```

### 15.1 1일차 (261114)

| 파일 | 환경 | 설명 |
|---|---|---|
| `legPin.png` | Tinkercad | LED 점멸 회로 스크린샷 |
| `legPinCode.txt` | Tinkercad | LED를 일정 간격으로 켜고 끄는 코드 |

### 15.2 2일차 (261115)

| 파일 | 환경 | 설명 |
|---|---|---|
| `Button.png` | Tinkercad | 버튼 입력 회로 스크린샷 |
| `Button.txt` | Tinkercad | 풀다운 버튼 입력을 읽어 시리얼로 출력하는 코드 |
| `ButtonLed.png` | Tinkercad | 버튼으로 LED를 제어하는 회로 스크린샷 |
| `ButtonLed.txt` | Tinkercad | 버튼을 누르면 LED가 켜지는 코드 |
| `PotentiometerLed.png` | Tinkercad | 가변저항으로 LED 밝기를 조절하는 회로 스크린샷 |
| `PotentiometerLed.txt` | Tinkercad | 가변저항 값을 map으로 변환해 LED 밝기를 조절하는 코드 (PWM) |
| `Buzzer.txt` | ESP32 | 피에조 버저로 소리를 내는 코드 |
| `readvalue.txt` | ESP32 | 가변저항 값(0~4095)을 읽어 시리얼로 출력하는 코드 |
| `movepantozeroto180.txt` | ESP32 | 서보 모터를 0°~180° 사이로 왕복시키는 코드 (Servo Sweep) |
| `PotentiometerPan.txt` | ESP32 | 가변저항 값으로 서보 모터 각도를 제어하는 코드 |

- 폴더 이름은 `실습날짜_학번` 형식이다.
- 코드는 `.txt` 파일로 저장되어 있으며, 실행 방법은 17장을 참고한다.


## 16. 개발 환경 및 의존성

| 항목 | 내용 |
|---|---|
| OS | Ubuntu (수업 실습 PC 환경) |
| IDE | Arduino IDE 2.x (AppImage) |
| 보드 패키지 | esp32 by Espressif Systems 3.x 이상 |
| 라이브러리 | ESP32Servo 3.x 이상 |
| 시뮬레이터 | Tinkercad Circuits (웹) |

| 하드웨어 | 내용 |
|---|---|
| 보드 | ESP32 (WeMos D1 R32) |
| 실습 PCB | 가변저항, 피에조 버저 내장 |
| 서보 모터 | SG90 |
| 기타 | 점퍼 와이어, USB 케이블 |

---

## 17. 실행 방법

### 17.1 레포 다운로드
```bash
git clone https://github.com/rhkrdnwls/Robotics_202235006.git
cd Robotics_202235006
```

### 17.2 Tinkercad 실습
대상 파일: `legPinCode.txt`, `Button.txt`, `ButtonLed.txt`, `PotentiometerLed.txt`

1. Tinkercad Circuits에서 새 회로를 만든다.
2. 같은 이름의 `.png` 파일(예: `Button.txt` → `Button.png`)을 보고 부품을 배치하고 연결한다.
3. Code → Text를 선택하고 해당 `.txt` 파일 내용을 붙여 넣는다.
4. Start Simulation을 누르고, 필요하면 Serial Monitor를 연다.

### 17.3 Arduino IDE 설치 (Ubuntu)
```bash
sudo mkdir -p /opt/arduino-ide
# Arduino IDE AppImage를 다운받아 /opt/arduino-ide 에 넣는다
sudo chmod +x /opt/arduino-ide/<AppImage 파일>
/opt/arduino-ide/<AppImage 파일> --no-sandbox
```

### 17.4 시리얼 포트 권한 설정
```bash
sudo usermod -aG dialout $USER   # 설정 후 재부팅
ls -l /dev/ttyUSB*               # ESP32 연결 확인
```

### 17.5 ESP32 업로드
대상 파일: `Buzzer.txt`, `readvalue.txt`, `movepantozeroto180.txt`, `PotentiometerPan.txt`

1. Tools → Board → Boards Manager에서 `esp32` (Espressif Systems)를 설치한다.
2. Tools → Manage Libraries에서 `ESP32Servo`를 설치한다.
3. Board는 `WEMOS D1 R32`, Port는 `/dev/ttyUSB0`을 선택한다.
4. File → New Sketch로 새 스케치를 만들고, 해당 `.txt` 파일 내용을 붙여 넣는다.
5. Upload(→)를 누른다.
6. 시리얼 출력이 있는 코드는 Serial Monitor의 baud rate를 115200으로 맞춘다.

- 업로드 중 연결 에러가 나면, 보드의 버튼을 누르고 있다가 업로드가 시작되면 뗀다. (부트 모드)
- 서보 실습(`movepantozeroto180.txt`, `PotentiometerPan.txt`)은 서보를 점퍼 와이어로 따로 연결한다. (갈색 GND, 빨강 5V, 노랑 GPIO 14)
- `PotentiometerPan.txt`는 PCB의 가변저항과 ESP32를 39번 핀, 3.3V, GND 세 선으로 연결해야 한다.

## 18. 진행 과정

### 18.1 1일차
1. Linux CLI 기본 명령어 실습
2. 작업 폴더 구성 및 GitHub 연동
3. 임베디드 기초 용어 학습
4. Tinkercad에서 LED 점멸 회로 구성 (`legPinCode.txt`)

### 18.2 2일차
Tinkercad
1. 풀다운 저항으로 버튼 입력을 읽고 시리얼로 출력 (`Button.txt`)
2. 버튼을 누르면 LED가 켜지는 회로 구성 (`ButtonLed.txt`)
3. 가변저항 값을 읽어 LED 밝기 조절 (`PotentiometerLed.txt`)

ESP32
1. Arduino IDE 설치 및 시리얼 포트 권한 설정
2. 피에조 버저 소리 출력 (`Buzzer.txt`)
3. 가변저항 값 읽기 (`readvalue.txt`)
4. 서보 모터 0°~180° 왕복 (`movepantozeroto180.txt`)
5. 가변저항으로 서보 각도 제어 (`PotentiometerPan.txt`)
6. 차체에 모터 4개 조립

---

## 19. 결과 분석

### 19.1 실습 결과

| 실습 | 파일 | 결과 |
|---|---|---|
| LED 점멸 | `legPinCode.txt` | 성공 |
| 버튼 입력 읽기 | `Button.txt` | 성공 |
| 버튼으로 LED 제어 | `ButtonLed.txt` | 성공 |
| 가변저항으로 LED 밝기 조절 | `PotentiometerLed.txt` | 성공 |
| 버저 | `Buzzer.txt` | 성공 |
| 가변저항 값 읽기 | `readvalue.txt` | 성공 |
| 서보 왕복 | `movepantozeroto180.txt` | 성공 |
| 가변저항으로 서보 제어 | `PotentiometerPan.txt` | 성공 |

### 19.2 문제점과 원인

| 문제 | 원인 | 해결 / 보완 |
|---|---|---|
| 서보가 180°에서 0°로 돌아오지 않음 | 0°에서 180°로 가는 코드만 작성하고, 180°에서 0°로 돌아오는 코드는 작성하지 않았다 | 감소(decrement)하는 for 문을 추가해 해결했다 |
| Tinkercad에서 LED에 불이 나는 표시가 뜸 | LED 극성(+/−)을 반대로 연결했고, 저항이 LED와 제대로 직렬로 연결되지 않아 과전류가 흐름 | LED 긴 다리(+)를 저항을 거쳐 디지털 핀에, 짧은 다리(−)를 GND에 연결했다. 신호선과 GND선의 색을 구분했다 |
| 시리얼 모니터 글자 깨짐 | 코드와 시리얼 모니터의 baud rate가 다름 | 시리얼 모니터를 115200으로 맞췄다 |

### 19.3 보완할 점
- 회로를 연결하기 전에 LED의 극성을 먼저 확인해야 한다. 긴 다리(+)는 저항을 거쳐 디지털 핀에, 짧은 다리(−)는 GND에 연결한다. Tinkercad에서는 LED 다리에 마우스를 올리면 Anode/Cathode를 확인할 수 있다.
- 선 색을 역할별로 구분해야 한다. VCC는 빨강, GND는 검정, 신호선은 다른 색으로 연결하면 잘못된 연결을 쉽게 찾을 수 있다.
- 시뮬레이션을 실행하기 전에 전류가 VCC(또는 핀) → 저항 → LED → GND 순서로 흐르는지 경로를 따라가며 확인해야 한다.
- 실제 하드웨어에서 같은 실수를 하면 LED나 보드 핀이 손상될 수 있으므로, Tinkercad로 회로를 먼저 검증한 뒤 실제 부품으로 옮기는 것이 안전하다.
