* **itrvision**:工作空间
	* **doc**:项目文档
	* **itrbase**:基础库项目
		* **platform**:平台支持
			+ typedef:数据类型
			+ macrodef:快捷宏
				- 直接地址操作
				- 位操作
				- 位判断
			+ basicmath:基本数学
				- 绝对值
				- 平方
				- 立方
				- 最大
				- 最小
				- 符号
				- 限值
				- 范围
			+ debugsupport:调试支持
				- 断言
				- 日志
			+ memoryoperation:内存操作
				- 附加内存申请
				- 数据复制
				- 数据对比
				- 数据交换
				- 数据清除
		* **encoding**:编码算法
			+ crc:CRC编码算法
				- CRC16
				- CRC32
			+ tea:tea加密算法
				- XXTEA
			+ md5:MD5编码算法
				- MD5
			+ gzip:gzip格式读写
				- 压缩
				- 解压
			+ xml[xxx]:xml格式读写
				- 解析
				- 生成
		* **container**:数据容器
			+ cyclequeue:循环队列
				- 插入
				- 取出
				- 读取
		* **math**:数学运算
			+ calculate:批量计算
				- 定点/浮点加法
				- 定点/浮点减法
				- 定点/浮点乘法
				- 定点/浮点除法
				- 定点/浮点偏移
				- 定点/浮点缩放
				- 定点/浮点归一
				- 定点/浮点绝对值
				- 定点/浮点异号
				- 定点/浮点加和
				- 定点/浮点积和
			+ matrix:矩阵计算
				- 生成
				- 点乘
				- 数乘
				- 求逆
				- 加减
				- 转置
			+ numerical:数值计算
				- sin
				- cos
				- sincos
				- tan
				- asin
				- acos
				- atan
				- atan2
				- sqrt
				- invsqrt
				- exp
				- log
				- log10
				- pow
				- floor
				- mod
			+ statistics:统计计算
				- 定点/浮点Max
				- 定点/浮点Min
				- 定点/浮点Median
				- 定点/浮点Average
				- 定点/浮点RMS
				- 定点/浮点STD
			+ geometry:几何类型
				- distance2D:二维距离
				- point2D:二维点
				- point3D:三维点
				- rectangleF:浮点矩形
				- rectangleS:定点矩形
	* **itrvision**:视觉库项目
		* **image**:图像数据类型
			+ colorGray:灰度色彩类型(S16*1)
			+ colorARGB:彩色色彩类型(U8*4)
			+ image:通用图像容器
			+ iformat:通用格式接口
		* **format**:格式支持
			+ formatyuv:YUV格式
			+ formatbmp:BMP格式
			+ formatjpg:JPG格式
			+ formatpng:PNG格式
		* **operation**:图像操作(单色,彩色)
			+ draw:绘图
			+ fill:填充
			+ pick:提取
			+ zoom:缩放
			+ rotate:旋转
		* **process**:图像处理
			+ convolute:卷积
			+ split:二值化
			+ infect:染色
			+ gaussian:高斯分布生成
		* **feature**:图像特征
			+ surf:SURF加速稳健特征
			+ fast:FAST加速区域特征
			+ hessian:汉森特征值
		* **match**:图像匹配
			+ opticalflowlk:LK光流法
		* **area**:图像区域
			+ humoments:Hu不变矩

尚未规划
----------
* 流
* 内存池
* 系统
	* 文件操作
	* 多线程
* 网络
	* TCP
	* UDP
* 算法
	* EKF
	* 粒子滤波
	* 机器学习

附注
----------
```
文件夹名称前使用*标示大纲级别
文件名前使用+标示大纲级别
文件内容前使用-标示大纲级别
文件夹名称使用**符合加粗
```
