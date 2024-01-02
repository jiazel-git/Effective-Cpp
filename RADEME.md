### 条款10：令operator=返回一个reference to *this
当看到这个条款的时候，会不会有点吃惊（平时不就是以reference返回的吗，难道还有别的返回方式？）仔细一想，是不是可以返回一个value to *this或者是一个void的呢，于是写了三个不同operator=来进行测试。  

1. 以value to *this返回：编译通过，允许连续赋值，但是会产生至少一个临时对象，造成额外的开销  
2. 以reference to *this返回，编译通过，允许连续赋值，不会产生额外开销
3. 以void返回，编译通过，不会产出额外开销，但是不允许连续赋值

### 条款11：在operator=中处理“自我赋值”

如果一个类拥有资源(指针，数据库连接、文件描述符...)，那么我们就不能再使用编译器为我们产生的赋值运算符了(当然，拷贝构造也是不能用的)，我们必须为该类设计一个赋值运算符来确保赋值操作的正确性。然而，在设计赋值运算符的过程中最基本的就是要考虑“自我赋值”这种操作。如果未考虑这种情况，而当我们进行“自我赋值”的时候，就会发生未定行为。
 
### 条款12：复制对象时勿忘其每一个成分
所谓复制对象，就是在调用拷贝构造或者拷贝赋值，对于单一对象，我们是一定会将对象的每一个成分去复制的，但是对于有继承体系的对象，在拷贝或者赋值的时候，我们或许会忘记去复制基类的成分。如果我们这样做了，那么复制则是不完全的，我们只复制了本对象，而基类却还是旧值。
### 条款13：以对象管理资源
### 条款14：在资源管理类中小心copy行为
### 条款15：在资源管理类中提供原始资源的访问
### 条款16：成对使用new和delete时要采取相同形式
### 条款17：以独立语句将newed对象置入只能指针
### 条款18：让接口容易被正确使用，不易被误用
### 条款19：设计class犹如设计type
### 条款20：宁以pass-by-reference-to-const替换pass-by-value
### 条款21：必须返回对象时，别妄想返回其reference
### 条款22：将成员变量声明为private
### 条款23：宁以non-member、non-friend替换member函数
### 条款24：若所有参数皆需类型转换，请为此采用non-member函数
### 条款25：考虑写一个不抛异常的swap函数
### 条款26：尽可能延后变量定义式的出现时间
### 条款27：尽量少做转型动作
1. const_cast:用于将对象的常量属性擦除
2. dynamic_cast:用于“安全向下转型”（基类向子类转型）
3. reinterpret_cast:执行低级转型，将pointer-to-int转为int
4. static_cast:强制转换，将non-const转为const,int转为double,将void*转为其他类型的指针，将pointer-to-base转为point-to-derived
### 条款28：避免返回handles指向对象内部成分
### 条款29：为“异常安全”努力是值得的