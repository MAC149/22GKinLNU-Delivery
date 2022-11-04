import sensor, image, time, math,lcd
from pyb import Pin, Timer
#屏幕 320*240
height = 120
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
#sensor.set_windowing(320,240))
sensor.skip_frames(time = 2000)
sensor.set_auto_gain(False) # must be turned off for color tracking
sensor.set_auto_whitebal(False) # must be turned off for color tracking
clock = time.clock()
message=000



threshold_index = 0 # 0 for red, 1 for green, 2 for blue

# Color Tracking Thresholds (L Min, L Max, A Min, A Max, B Min, B Max)
# The below thresholds track in general red/green/blue things. You may wish to tune them...
thresholds = [(30, 83, 47, 127, -128, 127), # generic_red_thresholds
              (80, 100, -63, -22, -1, 20)] # generic_green_thresholds
#(91, 100, -128, 127, -22, -4)
#(12, 58, -128, -24, 10, 58)
#(12, 58, -128, -24, 10, 58)

#################### Openmv数据处理 ###################
# 直接向arduino发送处理好的数据



def find_min(blobs):
    min_size=1000000
    for blob in blobs:
        if blob[2]*blob[3] <= min_size:
            min_blob=blob
            min_size = blob[2]*blob[3]
    return min_blob


#################### UART TO ARDUINO ###################
# 导入串口
from pyb import UART
# 串口3  [TX-P4, RX-P5]
uart = UART(3,9600,timeout_char = 50)   # 100 可改

# 串口收发数据
recv_data = ""     # 串口接收的数据 【 CM+QR|扫描二维码、CM+WL|
#global Light_flag

# 串口发送 【QR1_XXX\QR2_XXX  WL1_XXX\WL2_XXX  CT1_XXX\CT2_XXX】
#  对应 QR|任务码  WL|物料位置  CT|机械臂抓取顺序（依据QR&WL计算）
Light_flag=0

def Uart_recv():  # 串口接收数据
    global Light_flag
    if (uart.any()):   # 更新串口接收数据
        recv_data = eval(str(uart.read()))

        #print(recv_data)
        #uart.write(recv_data)
        if (recv_data !="") :
            print("Openmv has recved CMD data.")
            if ("ST" in recv_data):
                Light_flag = 1
                print("Task start!")

            if ("ED" in recv_data):
                Light_flag = 0
                print("Task End!")





# 主循环
while(True):
    clock.tick()
    img = sensor.snapshot()
    Uart_recv() # 串口接收（接收arduino发送的指令）
    while(Light_flag):
        clock.tick()
        light = Timer(2, freq=50000).channel(1, Timer.PWM, pin=Pin("P6"))
        light.pulse_width_percent(100) # 控制亮度 0~100
        img = sensor.snapshot()
        #for r in img.find_blobs([thresholds[0]],roi=[0,140,320,100],pixels_threshold=200, area_threshold=200, merge=True):
            ## These values depend on the blob not being circular - otherwise they will be shaky.
            ## These values are stable all the time.
            #img.draw_rectangle(r.rect())
            #img.draw_cross(r.cx(), r.cy())
            ## Note - the blob rotation is unique to 0-180 only.
            #img.draw_keypoints([(r.cx(), r.cy(), int(math.degrees(r.rotation())))], size=20)
            ##print(clock.fps())
            #uart.write("RED")
            #print("RED LIGHT!")

        for g in img.find_blobs([thresholds[1]],roi=[50,20,220,140], pixels_threshold=10, area_threshold=10, merge=True):
            # These values depend on the blob not being circular - otherwise they will be shaky.
            # These values are stable all the time.
            img.draw_rectangle(g.rect())
            img.draw_cross(g.cx(), g.cy())
            # Note - the blob rotation is unique to 0-180 only.
            img.draw_keypoints([(g.cx(), g.cy(), int(math.degrees(g.rotation())))], size=20)
            #print(clock.fps())
            uart.write("GREENb\r\n")
            #time.sleep(1000)
            print("GREEN LIGHT!")
            #time.sleep_ms(4000)
            Light_flag=0



