{
  "command":1,
  "temperature": 1,
  "pn": 1,
  "sn": 1,
  "production_date": 1,
  "manufacturer": 1,
  "device_pixel_length": 1,
  "Set_Integration_Time":30,
  "Average_Number":50
}
代码中的变量比较多，还要好好管理一下。如果使用滨松自己带的板子，那么定时器12是可以不用捕获的。
	如果上位机既可以支持发送命令，又可以看图像就很好调试了。
	
可以使用json文件进行积分时间设置和平均次数设置，一定要有个默认值，否则程序容易出bug卡死。
温度获取还没搞。
	不知道为什么当没有光照时，会有2500左右的dn值。这个可以通过旋转VR5和VR2来调节

	/*
        {
          "command": 1,
          "temperature": 1,
          "pn": 1,
          "sn": 1,
          "production_date": 1,
          "manufacturer": 1,
          "min_in_time": 1,
          "max_in_time": 1,
          "device_pixel_length": 1,
          "set_integration_time": 16,
          "average_number": 50,
          "segment_1": 50,
          "segment_2": 462,
          "mul_max": 1
        }
	*/
55 AA 00 00 E1 7B 22 63 6F 6D 6D 61 6E 64 22 3A 31 2C 22 74 65 6D 70 65 72 61 74 75 72 65 22 3A 31 2C 22 70 6E 22 3A 31 2C 22 73 6E 22 3A 31 2C 22 70 72 6F 64 75 63 74 69 6F 6E 5F 64 61 74 65 22 3A 31 2C 22 6D 61 6E 75 66 61 63 74 75 72 65 72 22 3A 31 2C 22 6D 69 6E 5F 69 6E 5F 74 69 6D 65 22 3A 31 2C 22 6D 61 78 5F 69 6E 5F 74 69 6D 65 22 3A 31 2C 22 64 65 76 69 63 65 5F 70 69 78 65 6C 5F 6C 65 6E 67 74 68 22 3A 31 2C 22 73 65 74 5F 69 6E 74 65 67 72 61 74 69 6F 6E 5F 74 69 6D 65 22 3A 31 36 2C 22 61 76 65 72 61 67 65 5F 6E 75 6D 62 65 72 22 3A 35 30 2C 22 73 65 67 6D 65 6E 74 5F 31 22 3A 35 30 2C 22 73 65 67 6D 65 6E 74 5F 32 22 3A 34 36 32 2C 22 6D 75 6C 5F 6D 61 78 22 3A 31 7D F8 11