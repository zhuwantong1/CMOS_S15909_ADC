代码中的变量比较多，还要好好管理一下。如果使用滨松自己带的板子，那么定时器12是可以不用捕获的。
	如果上位机既可以支持发送命令，又可以看图像就很好调试了。
	
可以使用json文件进行积分时间设置和平均次数设置，一定要有个默认值，否则程序容易出bug卡死。
温度获取还没搞。
	不知道为什么当没有光照时，会有2500左右的dn值。这个可以通过旋转VR5和VR2来调节

	/*

	{
    	"command": "get_temperature"
    }

    {
    	"command": "get_dev_info"
    }
    {
    	"command": "get_min_integration_time"
    }
    {
    	"command": "get_max_integration_time"
    }
    {
    	"command":"set_integration_time",
    	"integration_time": 3
    }
    {
      "command": "set_average_number",
      "average_number": 50
    }
    {
      "command": "set_pixel_segment",
      "pixel_segment": {
        "pixel_segment_1": 50,
        "pixel_segment_2": 462
      }
    }
    {
        "command": "set_mul_max",
        "mul_max": 3
    }
    {
      "command": "set_dma_open"
    }
    {
      "command": "set_dma_close"
    }
55 AA 00 00 1D 7B 22 63 6F 6D 6D 61 6E 64 22 3A 22 67 65 74 5F 74 65 6D 70 65 72 61 74 75 72 65 22 7D B9 D0
55 AA 00 00 1A 7B 22 63 6F 6D 6D 61 6E 64 22 3A 22 67 65 74 5F 64 65 76 5F 69 6E 66 6F 22 7D 2E 5E
55 AA 00 00 26 7B 22 63 6F 6D 6D 61 6E 64 22 3A 22 67 65 74 5F 6D 69 6E 5F 69 6E 74 65 67 72 61 74 69 6F 6E 5F 74 69 6D 65 22 7D 64 93
55 AA 00 00 26 7B 22 63 6F 6D 6D 61 6E 64 22 3A 22 67 65 74 5F 6D 61 78 5F 69 6E 74 65 67 72 61 74 69 6F 6E 5F 74 69 6D 65 22 7D 99 89
55 AA 00 00 37 7B 22 63 6F 6D 6D 61 6E 64 22 3A 22 73 65 74 5F 69 6E 74 65 67 72 61 74 69 6F 6E 5F 74 69 6D 65 22 2C 22 69 6E 74 65 67 72 61 74 69 6F 6E 5F 74 69 6D 65 22 3A 33 7D 21 AE
55 AA 00 00 5C 7B 22 63 6F 6D 6D 61 6E 64 22 3A 22 73 65 74 5F 70 69 78 65 6C 5F 73 65 67 6D 65 6E 74 22 2C 22 70 69 78 65 6C 5F 73 65 67 6D 65 6E 74 22 3A 7B 22 70 69 78 65 6C 5F 73 65 67 6D 65 6E 74 5F 31 22 3A 35 30 2C 22 70 69 78 65 6C 5F 73 65 67 6D 65 6E 74 5F 32 22 3A 34 36 32 7D 7D 91 E3
55 AA 00 00 34 7B 22 63 6F 6D 6D 61 6E 64 22 3A 22 73 65 74 5F 61 76 65 72 61 67 65 5F 6E 75 6D 62 65 72 22 2C 22 61 76 65 72 61 67 65 5F 6E 75 6D 62 65 72 22 3A 35 30 7D AF C2
55 AA 00 00 25 7B 22 63 6F 6D 6D 61 6E 64 22 3A 22 73 65 74 5F 6D 75 6C 5F 6D 61 78 22 2C 22 6D 75 6C 5F 6D 61 78 22 3A 33 7D 89 2E






	*/
