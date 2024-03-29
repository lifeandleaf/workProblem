## 计算机网络

### TCP、UDP

[TCP&UDP](./TCP%26UDP.md)

### 1、OSI七层协议模型

它将计算机⽹络体系结构划分为7层。

### 2、分层结构

从下至上：物理层、数据链路层、⽹络层、传输层、会话层、表示层、应⽤层。

### 3、各层功能

- 物理层        
简单的说，物理层（Physical Layer）确保原始的数据可在各种物理媒体上传输。在这⼀层上⾯规定了激活，维持，关闭通信端点之间的机械性，电⽓特性，功能特性，为上层协议提供了⼀个传输数据的物理媒体，这⼀层传输的是bit流。

- 数据链路层        
数据链路层（Data Link Layer）在不可靠的物理介质上提供可靠的传输。该层的作⽤包括：物理地址寻址、数据的成帧、流量控制、数据的检错、重发等。这⼀层中将bit流封装成frame帧。

- 网络层        
⽹络层（Network Layer）负责对⼦⽹间的数据包进⾏路由选择。此外，⽹络层还可以实现拥塞控制、⽹际互连等功能。在这⼀层，数据的单位称为数据包（packet）。

- 传输层        
传输层是第⼀个端到端，即主机到主机的层次。传输层负责将上层数据分段并提供端到端的、可靠的或不可靠的传输。此外，传输层还要处理端到端的差错控制和流量控制问题。在这⼀层，数据的单位称为数据段（segment）。

- 会话层        
这⼀层管理主机之间的会话进程，即负责建⽴、管理、终⽌进程之间的会话。会话层还利⽤在数据中插⼊校验点来实现数据的同步，访问验证和会话管理在内的建⽴和维护应⽤之间通信的机制。如服务器验证⽤户登录便是由会话层完成的。使通信会话在通信失效时从校验点继续恢复通信。⽐如说建⽴会话，如session认证、断点续传。

- 表示层        
这⼀层主要解决⽤户信息的语法表示问题。它将欲交换的数据从适合于某⼀⽤户的抽象语法，转换为适合于OSI系统内部使⽤的传送语法。即提供格式化的表示和转换数据服务。数据的压缩和解压缩，加密和解密等⼯作都由表示层负责。⽐如说图像、视频编码解，数据加密。

- 应用层        
这⼀层为操作系统或⽹络应⽤程序提供访问⽹络服务的接⼝。

### 4、各层传输协议、传输单元、主要功能性设备比较

|名称|传输协议|传输单元|主要功能设备/接口|
|:-:|:-:|:-:|:-:|
|物理层|IEEE 802.1A、IEEE 802.2|bit-flow⽐特流|光纤，双绞线，中继器，集线器，⽹线接⼝|
|数据链路层|ARP、MAC、 FDDI、Ethernet、Arpanet、PPP、PDN|frame帧|⽹桥、⼆层交换机|
|网络层|IP、ICMP、ARP、RARP|数据包（packet）|路由器、三层交换机|
|传输层|TCP、UDP|Segment/Datagram|四层交换机|
|会话层|SMTP、DNS|报⽂|-|
|表示层|Telnet、SNMP|报⽂|-|
|应用层|FTP、TFTP、Telnet、HTTP、DNS|报⽂|-|

### 5、描述TCP头部

- 序号（32bit）：传输⽅向上字节流的字节编号。初始时序号会被设置⼀个随机的初始值（ISN），之后每次发送数据时，序号值 = ISN + 数据在整个字节流中的偏移。假设A -> B且ISN = 1024，第⼀段数据512字节已经到B，则第⼆段数据发送时序号为1024 + 512。⽤于解决⽹络包乱序问题。
- 确认号（32bit）：接收⽅对发送⽅TCP报⽂段的响应，其值是收到的序号值 + 1。
- ⾸部⻓（4bit）：标识⾸部有多少个4字节 * ⾸部⻓，最⼤为15，即60字节。
- 标志位（6bit）：
    - URG：标志紧急指针是否有效。
    - ACK：标志确认号是否有效（确认报⽂段）。⽤于解决丢包问题。
    - PSH：提示接收端⽴即从缓冲读⾛数据。
    - RST：表示要求对⽅᯿新建⽴连接（复位报⽂段）。
    - SYN：表示请求建⽴⼀个连接（连接报⽂段）。
    - FIN：表示关闭连接（断开报⽂段）。
- 窗⼝（16bit）：接收窗⼝。⽤于告知对⽅（发送⽅）本⽅的缓冲还能接收多少字节数据。⽤于解决流控。
- 校验和（16bit）：接收端⽤CRC检验整个报⽂段有⽆损坏。

### 6、TCP三次握手

三次握⼿过程？
- 第⼀次：客户端发含SYN位，SEQ_NUM = S的包到服务器。（客 -> SYN_SEND）
- 第⼆次：服务器发含ACK，SYN位且ACK_NUM = S + 1，SEQ_NUM = P的包到客户机。（服 ->
SYN_RECV）
- 第三次：客户机发送含ACK位，ACK_NUM = P + 1的包到服务器。（客 -> ESTABLISH，服 ->
ESTABLISH）

四次挥手过程
- 第⼀次：客户机发含FIN位，SEQ = Q的包到服务器。（客 -> FIN_WAIT_1）
- 第⼆次：服务器发送含ACK且ACK_NUM = Q + 1的包到服务器。（服 -> CLOSE_WAIT，客 ->
FIN_WAIT_2）        
**此处有等待**
- 第三次：服务器发送含FIN且SEQ_NUM = R的包到客户机。（服 -> LAST_ACK，客 -> TIME_WAIT）     
**此处有等待**
- 第四次：客户机发送最后⼀个含有ACK位且ACK_NUM = R + 1的包到客户机。（服 -> CLOSED）

为什么握手是三次，挥手是四次
- 对于握⼿：握⼿只需要确认双⽅通信时的初始化序号，保证通信不会乱序。（第三次握⼿必要性：假设
服务端的确认丢失，连接并未断开，客户机超时᯿发连接请求，这样服务器会对同⼀个客户机保持多个
连接，造成资源浪费。）
- 对于挥⼿：TCP是双⼯的，所以发送⽅和接收⽅都需要FIN和ACK。只不过有⼀⽅是被动的，所以看上去
就成了4次挥⼿。

TCP连接状态
- CLOSED：初始状态。
- LISTEN：服务器处于监听状态。
- SYN_SEND：客户端socket执⾏CONNECT连接，发送SYN包，进⼊此状态。
- SYN_RECV：服务端收到SYN包并发送服务端SYN包，进⼊此状态。
- ESTABLISH：表示连接建⽴。客户端发送了最后⼀个ACK包后进⼊此状态，服务端接收到ACK包后进⼊此状态。
- FIN_WAIT_1：终⽌连接的⼀⽅（通常是客户机）发送了FIN报⽂后进⼊。等待对⽅FIN。
- CLOSE_WAIT：（假设服务器）接收到客户机FIN包之后等待关闭的阶段。在接收到对⽅的FIN包之后，⾃然是需要⽴即回复ACK包的，表示已经知道断开请求。但是本⽅是否⽴即断开连接（发送FIN包）取决于是否还有数据需要发送给客户端，若有，则在发送FIN包之前均为此状态。
- FIN_WAIT_2：此时是半连接状态，即有⼀⽅要求关闭连接，等待另⼀⽅关闭。客户端接收到服务器的ACK包，但并没有⽴即接收到服务端的FIN包，进⼊FIN_WAIT_2状态。
- LAST_ACK：服务端发动最后的FIN包，等待最后的客户端ACK响应，进⼊此状态。
- TIME_WAIT：客户端收到服务端的FIN包，并⽴即发出ACK包做最后的确认，在此之后的2MSL时间称为TIME_WAIT状态。

解释FIN_WAIT_2，CLOSE_WAIT状态和TIME_WAIT状态？
- FIN_WAIT_2：
    - 半关闭状态。
    - 发送断开请求⼀⽅还有接收数据能⼒，但已经没有发送数据能⼒。
- CLOSE_WAIT状态：
    - 被动关闭连接⼀⽅接收到FIN包会⽴即回应ACK包表示已接收到断开请求。
    - 被动关闭连接⼀⽅如果还有剩余数据要发送就会进⼊CLOSED_WAIT状态。
- TIME_WAIT状态：
    - ⼜叫2MSL等待状态。
    - 如果客户端直接进⼊CLOSED状态，如果服务端没有接收到最后⼀次ACK包会在超时之后᯿新再发FIN包，此时因为客户端已经CLOSED，所以服务端就不会收到ACK⽽是收到RST。所以TIME_WAIT状态⽬的是防⽌最后⼀次握⼿数据没有到达对⽅⽽触发᯿传FIN准备的。
    - 在2MSL时间内，同⼀个socket不能再被使⽤，否则有可能会和旧连接数据混淆（如果新连接和旧连接的socket相同的话）。

解释RTO，RTT和超时重传
- 超时重传：发送端发送报⽂后若⻓时间未收到确认的报⽂则需要重发该报⽂。可能有以下⼏种情况：
    - 发送的数据没能到达接收端，所以对⽅没有响应。
    - 接收端接收到数据，但是ACK报⽂在返回过程中丢失。
    - 接收端拒绝或丢弃数据。
- RTO：从上⼀次发送数据，因为⻓期没有收到ACK响应，到下⼀次重发之间的时间。就是重传间隔。
    - 通常每次重传RTO是前⼀次重传间隔的两倍，计量单位通常是RTT。例：1RTT，2RTT，4RTT，8RTT......
    - 重传次数到达上限之后停⽌重传。
- RTT：数据从发送到接收到对⽅响应之间的时间间隔，即数据报在⽹络中⼀个往返⽤时。⼤⼩不稳定。
- ⽬的是接收⽅通过TCP头窗⼝字段告知发送⽅本⽅可接收的最⼤数据量，⽤以解决发送速率过快导致接收⽅不能接收的问题。所以流ᰁ控制是点对点控制。
- TCP是双⼯协议，双⽅可以同时通信，所以发送⽅接收⽅各⾃维护⼀个发送窗和接收窗。
    - 发送窗：⽤来限制发送⽅可以发送的数据⼤⼩，其中发送窗⼝的⼤⼩由接收端返回的TCP报⽂段中窗⼝字段来控制，接收⽅通过此字段告知发送⽅⾃⼰的缓冲（受系统、硬件等限制）⼤⼩。
    - 接收窗：⽤来标记可以接收的数据⼤⼩。
- TCP是流数据，发送出去的数据流可以被分为以下四部分：已发送且被确认部分 | 已发送未被确认部分 | 未发送但可发送部分 | 不可发送部分，其中发送窗 = 已发送未确认部分 + 未发但可发送部分。接收到的数据流可分为：已接收 | 未接收但准备接收 | 未接收不准备接收。接收窗 = 未接收但准备接收部分。
- 发送窗内数据只有当接收到接收端某段发送数据的ACK响应时才移动发送窗，左边缘紧贴刚被确认的数据。接收窗也只有接收到数据且最左侧连续时才移动接收窗⼝。
- 拥塞控制原理？
    - 拥塞控制⽬的是防⽌数据被过多注⽹络中导致⽹络资源（路由器、交换机等）过载。因为拥塞控制涉及⽹络链路全局，所以属于全局控制。控制拥塞使⽤拥塞窗⼝。
    - TCP拥塞控制算法：
        - 慢开始 & 拥塞避免：先试探⽹络拥塞程度再逐渐增⼤拥塞窗口。每次收到确认后拥塞窗⼝翻倍，直到达到阀值ssthresh，这部分是慢开始过程。达到阀值后每次以⼀个MSS为单位增⻓拥塞窗⼝⼤⼩，当发⽣拥塞（超时未收到确认），将阀值减为原先⼀半，继续执⾏线性增加，这个过程为拥塞避免。
        - 快速重传 & 快速恢复：略。
        - 最终拥塞窗⼝会收敛于稳定值。

### 7、如何区分流量控制和拥塞控制

- 流量控制属于通信双⽅协商；拥塞控制涉及通信链路全局。
- 流量控制需要通信双⽅各维护⼀个发送窗、⼀个接收窗，对任意⼀⽅，接收窗⼤⼩由⾃身决定，发送窗⼤⼩由接收⽅响应的TCP报⽂段中窗⼝值确定；拥塞控制的拥塞窗⼝⼤⼩变化由试探性发送⼀定数据ᰁ数据探查⽹络状况后⽽⾃适应调整。
- 实际最终发送窗⼝ = min{流控发送窗⼝，拥塞窗⼝}。

### 8、TCP如何提供可靠数据传输的

- 建⽴连接（标志位）：通信前确认通信实体存在。
- 序号机制（序号、确认号）：确保了数据是按序、完整到达。
- 数据校验（校验和）：CRC校验全部数据。
- 超时重传（定时器）：保证因链路故障未能到达数据能够被多次重发。
- 窗⼝机制（窗⼝）：提供流量控制，避免过量发送。
- 拥塞控制：同上。

### 9、TCP socket交互流程

- 服务器
    - 创建socket-> int socket(int domain, int type, int protocol);
        - domain：协议域，决定了socket的地址类型，IPV4位AF_INET.
        - type：指定socket类型，SOCK_STREAM为TCP连接。
        - protocol：指定协议。IPPROTO_TCP表示TCP协议，为0时⾃动选择type默认协议。
    - 绑定socket和端⼝号 -> int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
        - sockfd：socket返回的套接字描述符，类似于⽂件描述符fd。
        - addr：有个sockaddr类型数据的指针，指向的是被绑定结构变量。
        ```cpp
        // IPv4的sockaddr地址结构
        struct sockaddr_in {
            sa_family_t sin_family; // 协议类型，AF_INET
            in_port_t sin_port; // 端⼝号
            struct in_addr sin_addr; // IP地址
        };
        struct in_addr {
            uint32_t s_addr;
        }
        ```
        - addrlen：地址长度
    - 监听端⼝号 -> int listen(int sockfd, int backlog);
        - sockfd：要监听的socket描述字。
        - backlog：socket可以排队的最⼤连接数。
    - 接收⽤户请求 -> int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
        - sockfd：服务器socket描述字。
        - addr：指向地址结构指针。
        - addrlen：协议地址⻓度。
        - 注：⼀旦accept某个客户机请求成功将返回⼀个全新的描述符⽤于标识具体客户的TCP连接。
    - 从socket中读取字符 -> ssize_t read(int fd, void *buf, size_t count);
        - fd：连接描述字。
        - buf：缓冲区buf。
        - count：缓冲区⻓度。
        - 注：⼤于0表示读取的字节数，返回0表示⽂件读取结束，⼩于0表示发⽣错误。
    - 关闭socket -> int close(int fd);
        - fd：accept返回的连接描述字，每个连接有⼀个，⽣命周期为连接周期。
        - 注：sockfd是监听描述字，⼀个服务器只有⼀个，⽤于监听是否有连接；fd是连接描述字，⽤于每个连接的操作。
- 客户机：
    - 创建socket -> int socket(int domain, int type, int protocol);
    - 连接指定计算机 -> int connect(int sockfd, struct sockaddr* addr, socklen_t addrlen);
        - sockfd客户端的sock描述字。
        - addr：服务器的地址。
        - addrlen：socket地址⻓度。
    - 向socket写⼊信息 -> ssize_t write(int fd, const void *buf, size_t count);
        - fd、buf、count：同read中意义。
        - ⼤于0表示写了部分或全部数据，⼩于0表示出错。
    - 关闭oscket -> int close(int fd);
        - fd：同服务器端fd。
