# 这是sjtu2024级程序设计大作业
## 我们组的扫雷程序分工可以参考成功案例https://github.com/xiaoxi666/mines_sweeper,大体由如下部分组成
### cellitem.h 和 cellitem.cpp 类文件：每个格子元素item，包含状态等
### configdialog.h 和 configdialog.cpp 类文件：游戏配置操作
### fielddata.h 和 fielddata.cpp 类文件：底层数据 // 以上三部分是逻辑部分
### main.cpp 程序入口  //
### mainwindow.h 和 mainwindow.cpp 类文件：主窗口操作（统一调用及设置数据，维护视图，设置场景等）
### mainwindow.ui 图形文件：主窗口图元描述
### minesweepscene.h 和 minesweepscene.cpp 类文件：场景布置 // 这些是ui界面
### res.qrc 资源文件：描述加载的文件（本项目是一些图片）
### sweep_minesV1.pro qt项目文件，包含一些项目相关设置
### sweep_minesV1.pro.user 用户设置，这个文件可以删掉，再次编译时会自动生成
### imgs.pptx 游戏中用到的图片原件，去除透明背景k可以利用ps处理 
