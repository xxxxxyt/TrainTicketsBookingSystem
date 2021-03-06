# 开发手册

## 模版文件相关规范

1. 文件名与类名相同与规范相同
2. 规范代码风格: 
	1. 除常量全大写外其余均按大小驼峰命名法(小写开头)
	2. 二元运算符两侧加空格
	3. 大括号与函数头同行
3. 使用sjtu名字空间
4. 使用头文件保护符号

*myClass.hpp*
```cpp
#ifndef SJTU_MYCLASS_HPP
#define SJTU_MYCLASS_HPP
namespace sjtu {

class myClass {
private:
public:
};

}
#endif
```

## Git管理相关规范

1. 所有代码相关的工作均在 dev 中完成
2. 代码文件保存在 source 文件夹中
3. source/ 文件夹下的直接文件应"保证"已经全部完成并被调试好
4. 每个人都请分别在 source/ 中创建一个名为 dev-myClass 的文件夹, 完成代码前在里面工作
5. 完成后请转移 myClass.hpp 到 source/ 下并删除该文件夹
6. 若需要调试则建立一 source/debug-myClass 文件夹, 请复制文件到文件夹中而非剪切
7. 调试完毕后无需删除文件夹 将文件夹名改为 "debug-myClass done" 即可, 但请尽量删除里面的可运行文件(如".exe", 比较占空间)

## 调试相关规范

1. 通用的错误类模版保存在 exceptions.hpp 中, 需要 include
2. 若其中不包含你所需要的特殊错误类, 则自行在 myClass 中继承 exception 类声明内嵌类 myExcepiton
3. 输出信息遵循以下格式

```
member_name1: value1
member_name2:
    value211 value212 ...
    value221 ...
```


```cpp
class myClass {
    class myException : public exception {
    public:
        myException() : exception(
	    "myException",
	    "description"
	    ) {}
    };
};
```

## 思路图解
[![思路图解](https://github.com/xxxxxyt/TrainTicketsBookingSystem/blob/master/TrainMind.png "思路图解")](https://github.com/xxxxxyt/TrainTicketsBookingSystem/blob/master/TrainMind.png "思路图解")

## 文件汇总
| file name | description |
|:---:|:----:|
| system.hpp | 订票系统 |
| train.hpp | 车次 |
| plan.hpp | 运行计划 |
| station.hpp | 车站 |
| ticket.hpp | 车票 |
| user.hpp | 管理员或用户 |
| vector.hpp | vector容器 |
| map.hpp | map容器 |
| list.hpp | list容器 |
| log.hpp | 系统日志 |
| getPath.hpp | 提取路径 |
| rwFile.hpp | 读写文件 |

## 类接口

### 第9周

注意:
1. 加粗的method暂缓实现
2. 若xxx不存在 throw no_such_xxx();
3. 若xxx已存在 throw existed_xxx();
4. 错误类若在exceptions.hpp中没有则需要自己定义为内嵌类
2. 可能有一些细节错误, 有觉得不对劲的地方请及时反馈!

#### user

用户类, 保存用户信息及已订车票列表

| return type | method | description |
|:----------:|:---------------:|:----------:|
| / | user() | 默认构造 |
| / | user(const std::string &_id, const std::string &_name, const std::string &_password = "000000") | 构造函数 |
| / | user(const user &other) | 拷贝构造 |
| user & | operator=(const user &other) | 赋值函数 |
| const std::string & | getId() const | 返回用户id |
| const std::string & | getName() const | 返回用户名 |
| const std::string & | getPassword() const | 返回用户密码 |
| list< ticket> & | getTicketList()  | 返回车票列表 |
| const ticket & | getTicket(const std::string &ticketId) const | 返回用户所订的某张车票 若该用户未订此车票 |
| void | modifyName(const std::string &newName) | 修改用户名 |
| void | modifyPassword(const std::string &newPassword) | 修改用户密码 |
| void | orderTicket(const ticket &tk) | 订票 若该票已存在于用户已订票清单 |
| void | disorderTicket(const std::string &ticketId, int number) | 退票 若该用户未订此车票 |

注意:
1. 已订车票清单用list存储

#### system

订票系统类, 系统功能的主要承担者

| return type | method | description |
|:----------:|:---------------:|:----------:|
| / | train() | 默认构造 |
| const std::string & | getPassword() const | 返回系统密码 |
| map< std::string, train> & | getTrainList() | 返回车次列表 |
| train & | getTrain(const std::string &trainId) | 返回编号为trainId的车次 |
| map< std::string, user> & | getUserList() | 返回用户列表 |
| user & | getUser(const std::string &userId) | 返回用户id为userId的用户 |
| void | modifyPassword(const std::string &newPassword) | 修改系统密码 |
| void | inserTrain(const train &tr) | 添加车次 |
| void | deleteTrain(const std::string &trainId) | 删除车次 |
| void | insertUser(const user &us) | 添加用户 |
| void | deleteUser(const std::string &userId) | 删除用户 |
| bool | loginAsAdmin(const std::string &_password) const | 作为管理员登录 判断密码是否正确 |
| void | initialize() | 初始化系统 包括重置系统密码 |
| void | importTrain(std::ifstream &file) | 从file导入车次信息 |
| list< std::string> & | query(const std::string &departStation, const std::string &stopStation) | 查询从某站到某站的车次 |
| double | getTicketPrice(const std::string &departStation, const std::string &stopStation, const train &_train, const int &type) const | 查询票价 |
| const ticket & | orderTicket(user &us, plan &pl, const std::string &departStation, const std::string &stopStation, int type, int number) | 订票 |
| void | disorderTicket(user &us, const std::string &ticketId, int number) | 退票 |
| bool | loginAsUser(const std::string &userId, const std::string &userPassword) | 作为用户登录 判断密码是否正确 |
| user & | signUpUser(const std::string &userId, const std::string &userPassword, const std::string &userName) | 注册用户 |
| void | importTrain(std::ifstream &file) | 导入车次 |
| void | work(std::ifstream &file) | 解析文件内容并执行相应命令 |
| void | writeOutLog(std::ostream &os) | 向os写出系统日志 |
| friend std::ifstream & | operator>>(std::ifstream &file, list &obj) | 从file读入数据 |
| friend std::ofstream & | operator<<(std::ofstream &file, const list &obj) | 向file写入数据 |

注意:
1. 函数尚不完全, 还需更新!
2. 订票时要求生成一唯一的8位车票id, 可用字符: 'A'-'Z', '0'-'9'
3. 车次列表要求用map存储, < string trainId, train tr>
4. 用户列表要求用map存储, < string userId, user us>

#### train

车次类, 保存车次信息, 运行线路车站信息及运行计划信息

| return type | method | description |
|:----------:|:---------------:|:----------:|
| / | train() | 默认构造 |
| / | train(const std::string &_id) | 构造函数 |
| / | train(const train &other) | 拷贝构造 |
| train & | operator=(const train &other) | 赋值函数 |
| const std::string & | getId() | 返回车次编号 |
| vector< station> & | getStationList() | 返回车站列表 |
| station & | getStation(int index) | 返回运行线路上的第index个车站 |
| int | getStationId(const std::string &stationName) | 返回站名为stationName的车站在该车次中的的序号 |
| map< std::string, plan> & | getPlanList() | 返回运行计划列表 |
| plan & | getPlan(const std::string &startDate) | 返回始发日期为startDate的运行计划 |
| void | pushStation(const station &st) | 添加站点到运行线路末尾 若该站点信息不合法 throw invalid_station(); |
| void | popStation() | 删除运行线路末尾的站点 |
| void | insertPlan(const plan &pl) | 添加运行计划 |
| void | deletePlan(const timer &startTime) | 删除运行计划 |

注意:
1. 运行线路上的车站从0开始编号, 即起点站对于当前车次来说是第0个车站
2. 车站列表要求使用vector< station st>存储

### 第8周

#### station

车站类, train的一个"内嵌类", 某个具体车次运行路线中的某个车站
如A次列车和与其不同B次列车均会经过的上海站, 在这里认为是不同的

| return type | method | description |
|:----------:|:---------------:|:----------:|
| / | station() | 默认构造 |
| / | station(const std::string &_name, const std::string &_train, const std::string &_stopTime, const std::string &_departTime, int _length, int _price[]) |  构造函数 |
| / | station(const station &other) | 拷贝构造 |
| station & | operator=(const station &other) | 赋值 |
| const std::string & | getName() const | 返回该车站的名字 |
| int | getId() const | 返回该车站的编号 |
| const std::string & | getTrain() const | 返回所属的车次 |
| const std::string & | getStopTime() const | 返回在该车次从出发到停靠在该站的时间差 |
| const std::string & | getDepartTime() const | 返回该车次从出发到离开该站的时间差 |
| int | getLength() const | 返回该车次从出发到停靠在该站的行驶里程数 |
| int | getPrice(int type) const | 返回该车次的type类型座位从出发到该站的票价 其中type=1,2,3分别表示一等座,二等座,三等座 |
| void | modifyPrice(int type, int newPrice) | 修改票价 |

#### plan

目前读入写出尚待增加, 请暂缓调用!
运行计划类, train的一个"内嵌类", 由所属车次与始发时间唯一确定

| return type | method | description |
|:----------:|:---------------:|:----------:|
| / | plan() | 默认构造 |
| / | plan(const std::string &_train, const std::string &_startDate, int stationNumber, bool _status) | 构造函数 |
| / | plan(const plan &other) | 拷贝构造 |
| plan & | operator=(const &other) | 赋值 |
| const std::string & | getTrain() const | 返回所属的车次 |
| const std::string & | getStartDate() const | 返回始发日期 |
| int | getStationNumber() const | 返回所属车次包含的车站总数 |
| bool | getStatus() const | 返回发售状态 |
| int | getLeftTickets(int type, int u, int v) const | 返回从该车次uth站点到vth站点type类型座位剩余票数 特殊地若传入不合法则返回0 |
| void | orderTicket(int type, int u, int v, int number) | 订票 修改余票信息 |
| void | disorderTicket(int type, int u, int v, int number) | 退票 修改余票信息 |
| void | modifyStartDate(const std::string &newStartDate) | 修改始发日期 |
| void | modifyStatus(bool newStatus) | 修改售票状态 |

注意:
1. 所有修改均需要检查发售状态为 false
2. 订票后记得修改余票信息
3. 余票信息的修改与查询要求用树状数组实现
4. 修改余票信息操作前需检验是否合法, 若不合法则 throw invalid_order_operation();

#### ticket

车票类, 记录一张车票的相关信息

| return type | method | description |
|:----------:|:---------------:|:----------:|
| / | ticket() | 默认构造 |
| / | ticket(const std::string &_id, const std::string &_train, const std::string &_startDate, const std::string &_userId, const std::string &_userName, const std::string &_departStation, const std::string &_stopStation, const std::string &_departTime, const std::string &_stopTime, int _type, int _price, int _number) | 构造函数 |
| / | ticket(const ticket &other) | 拷贝构造 |
| ticket & | operator=(const ticket &other) | 赋值 |
| const std::string & | getId() | 返回车票id |
| const std::string & | getTrain() const | 返回所属车次 |
| const std::string & | getStartDate() const | 返回始发日期 |
| const std::string & | getUserId() const | 返回用户id |
| const std::string & | getUserName() const | 返回用户名 |
| const std::string & | getDepartStation() const | 返回起点站 |
| const std::string & | getStopStation() const | 返回终点站 |
| const std::string & | getStartTime() const | 返回始发日期 |
| const std::string & | getDepartTime() const | 返回出发时间 |
| const std::string & | getStopTime() const | 返回到达时间 |
| int | getType() const | 返回座位类型 |
| int | getPrice() const | 返回票价 |
| int | getNumber() const | 返回车票数 |

### 第7周

#### list

list容器, 基本同STLite标准要求

#### map

map容器, 基本同STLite标准要求

#### log

系统日志类, 针对系统日志文件进行操作

| return type | method | description |
|:----------:|:---------------:|:----------:|
| / | log() | 默认构造 |
| void | open(const std::string &_fileName) | 打开_fileName且不清除内容 |
| void | close() | 关闭文件且不清除内容 |
| void | clear() | 清除文件内容 |
| friend std::ostream & | operator<<(std::ostream &os, log &lg) | 输出日志内容 |
| void | add(const std::string &str) | 向日志末尾新行添加语句str |

注意:
1. 文件打开失败时会 throw no_such_file();

#### vector

vector容器, 基本同STLite标准要求

## 模版函数

#### rwFile

二进制下从/向文件读/写变量

| return type | method |
|:----------:|:---------------:|
| void | readIn(std::ifstream &file, T &x) |
| void | writeOut(std::ofstream &file, const T &x) |

注意:
1. 已经对std::string做出了重载; 基本类型(如 int)并未做出过重载
2. 以上所有类型都需要对其进行重载
3. 在从文件读入数据到某容器的实例时, 若其非空 throw container_is_not_empty();

#### getPath

提取某运行程序所在文件夹路径

| return type | method |
|:----------:|:---------------:|
| std::string | getPath(const std::string &fileName) |

使用方法:
```cpp
#include <string>
#include "getPath.hpp"

int main(int argc, char *argv[]) {
	std::string fileName = sjtu::getPath(argv[0]) + "fileName";
	// 假若该程序路径为 D:\ab\test.exe 则 fileName 为 "D:\ab\fileName" 即同目录下文件
}
```
