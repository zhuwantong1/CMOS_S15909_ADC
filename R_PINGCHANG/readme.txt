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
	不知道为什么当没有光照时，会有2500左右的dn值。