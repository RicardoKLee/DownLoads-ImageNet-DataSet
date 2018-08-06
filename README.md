需要输入五个参数：
参数一：你的谷歌浏览器所在路径
        此程序需要谷歌浏览器的支持（其他浏览器尚未测试）。
		如：C:\Users\admin\AppData\Local\Google\Chrome\Application\chrome.exe
参数二：你下载的ImageNet文件所在的位置
        程序会在启动时浏览此路径中的文件，然后下载其中没有的文件
		因此，如果你给的文件夹中没有下载过ImageNet的数据，则会从新下载ImageNet的所有文件
		并且此文件夹需要包含一个写有ImageNet需要下载的资源名的文件，名为：ImageNetKeys.txt
		如：D:\ImageNet
参数三：你需要并行下载的文件数量
        此参数视你的宽带大小酌情而定。
		如：5
参数四：你的ImageNet的账户名
        前置条件是你注册过ImageNet
		如：Tom
参数五  你的ImageNet密钥
        前置条件是你注册过ImageNet并且获得下载数据库的允许
工作原理请访问：https://blog.csdn.net/qq_24864285/article/details/79137514
