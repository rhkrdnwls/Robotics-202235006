import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/edu42/robot_navigation/colcon_ws/install/1_pubsub'
