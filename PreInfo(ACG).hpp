#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define iv inline void
using namespace std;
using namespace __gnu_pbds;
iv moveto(int a,int b) //列 行 
{
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen={short(a),short(b)};
	SetConsoleCursorPosition(hConsole,coordScreen);
}
iv mouse(int a)
{
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle,&CursorInfo);
	CursorInfo.bVisible=a;
	SetConsoleCursorInfo(handle,&CursorInfo);
}
inline int ran(int l,int r)
{
	return rand()%(r-l+1)+l;
}
bool found(vector<string> &t,string a)
{
	vector<string>::iterator it=find(t.begin(),t.end(),a);
    if(it!=t.end()) return true;
    else return false;
}
int founds(vector<string> &t,string a)
{
	for(int i=0;i<t.size();i++)
		if(t[i]==a)
			return i;
}
void SetColor(short x);
#define Set SetColor(7)
iv print(string a){for(int i=0;i<a.size();i++){putchar(a[i]);}}
iv red(string u){SetColor(12);print(u);Set;}
iv blue(string u){SetColor(9);print(u);Set;}
iv green(string u){SetColor(10);print(u);Set;}
iv yellow(string u){SetColor(14);print(u);Set;}
iv cyan(string u){SetColor(11);print(u);Set;}
iv purple(string u){SetColor(13);print(u);Set;}
iv white(string u){SetColor(15);print(u);Set;}
iv grey(string u){SetColor(8);print(u);Set;}
iv putspace(int t){for(int i=1;i<=t;i++) putchar(' ');}
template <typename T>
inline string change(T a){stringstream ss;string s;ss.clear();ss.str("");ss<<a;ss>>s;return s;} 
template <typename T>
inline int change2(T a){stringstream ss;int s;ss.clear();ss.str("");ss<<a;ss>>s;return s;}
struct card{
	string name;
	int cost,effect;
	vector<string> speffect; 
	card(string name_,int cost_,int effect_):
		name(name_),cost(cost_),effect(effect_){} 
	card():name(""),cost(0),effect(0){}
};
card thethrowcard(card t)
{
	t.cost=-1;
	return t;
}
struct skill{
	string name;
	int mana,active,effect;
	void set_up(string name_,int mana_,int active_,int effect_)
	{
		name=name_,mana=mana_,active=active_,effect=effect_;
	}
};
struct buff{
	string name;
	int tim;
	void set_up(string name_,int tim_)
	{
		name=name_,tim=tim_;
	}
};
int foundbuff(vector<buff> *t,string s)
{
	for(int i=0;i<(t->size());i++)
		if((*t)[i].name==s)
			return i;
	return -1;
}
int foundskill(vector<skill> *t,string s)
{
	for(int i=0;i<(t->size());i++)
		if((*t)[i].name==s)
			return i+1;
	return 0;
}
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ENTER 13
bool upc(char c){if(c=='W' or c=='w' or c==UP) return true;return false;}
bool downc(char c){if(c=='S' or c=='s' or c==DOWN) return true;return false;}
bool leftc(char c){if(c=='A' or c=='a' or c==LEFT) return true;return false;}
bool rightc(char c){if(c=='D' or c=='d' or c==RIGHT) return true;return false;}
bool surec(char c){if(c==SPACE or c==ENTER) return true;return false;}
bool usec(char c){if(c=='Z' or c=='z' or c=='+') return true;return false;}
bool magicc(char c){if(c=='X' or c=='x' or c=='-') return true;return false;}
//qwq
vector<card> cardheap,recardheap;
vector<card> handcard1,handcard2;
vector<skill> skills1,skills2,simpleskills1,simpleskills2;
vector<buff> buff1,buff2,buffclear;
string soul1,soul2;
int cost1,cost2,costmax1,costmax2;
int mana1,mana2,manamax1,manamax2;
int handcardmax1,handcardmax2;
int trunk1,trunk2,sekiroblood1,sekiroblood2,bloodsure1,bloodsure2;
int clocks=0,clocksum=0;
int tim=0,twelveam=0,timrate=0;
int turn;
int server_mode;
//qwq
string explanation[114];skill theskill[514];
string skillexplanation[114];
string soullist[114];int soullong,cardlong;
string soulexplanation[514];
string cardname[1919];
vector<skill> soulskill[114];
gp_hash_table<string,string> speffectexplanation;
string cardsyst[19],cardsystexplanation[19];
int cardsystlong;
bool thecardsyst[19];
string gamemodename[19],gamemodeexplanation[19];int gamemodelong;
int normalcost[114];
iv setcad(int cad0,string cad1,int cad2)
{
	cardname[cad0]=cad1,normalcost[cad0]=cad2;
}
iv init()
{
	srand(time(NULL));
	mouse(0);
	cardlong=51;
	setcad(1,"惩罚",1);
	setcad(2,"附带弃置",2);
	setcad(3,"埋伏",1);
	setcad(4,"微小法力",1);
	setcad(5,"合作共赢",1);
	setcad(6,"中等法力",2);
	setcad(7,"意志摧毁",2);
	setcad(8,"天道轮回",1);
	setcad(9,"终极惩戒",2);
	setcad(10,"魔幻把戏",1);
	setcad(11,"可持久化",1);
	setcad(12,"1919810",1);
	setcad(13,"一心同体",2);
	setcad(14,"万心同体",1);
	setcad(15,"赞美太阳",2);
	setcad(16,"时间流逝",1);
	setcad(17,"绯红之王",1);
	setcad(18,"公平竞争",2);
	setcad(19,"变本加厉",2);
	setcad(20,"浪人的恩赐",1);
	setcad(21,"术士的恩赐",1);
	setcad(22,"法师的恩赐",2);
	setcad(23,"战士的恩赐",2);
	setcad(24,"地精的恩赐",1);
	setcad(25,"恶魔的恩赐",2);
	setcad(26,"牧师的恩赐",1);
	setcad(27,"鱼人的恩赐",1);
	setcad(28,"随缘的恩赐",1);
	setcad(29,"俄罗斯转盘",2);
	setcad(30,"埋伏II",3);
	setcad(31,"忍杀",1);
	setcad(32,"刚躯糖",2);
	setcad(33,"绝技·苇名十字斩",2);
	setcad(34,"绝技·不死斩",2);
	setcad(35,"画地为牢",1);
	setcad(36,"绝技·巨型忍者突刺",2);
	setcad(37,"苇名无心流",1);
	setcad(38,"秘传·飞渡漩涡云",1);
	setcad(39,"秘传·不死斩",2);
	setcad(40,"秘传·巨型忍者落杀",2);
	setcad(41,"巴之雷",1);
	setcad(42,"雷电奉还",1);
	setcad(43,"秘传·樱舞",1);
	setcad(44,"绝技·飞渡浮舟",1);
	setcad(45,"秘传·一心",3);
	setcad(46,"龙胤露滴",1);
	setcad(47,"一字斩",1);
	setcad(48,"一字斩·二连",1);
	setcad(49,"秘传·龙闪",2);
	setcad(50,"OBJECTION",1);
	setcad(51,"昏睡红茶",1);
	//qwq
	//牌面 
	explanation[1]="令对手从牌堆顶摸一张牌";
	explanation[2]="（打出此牌后）随机弃掉自己手牌中另一张牌";
	explanation[3]="向牌堆顶加入一张【阻碍】";
	explanation[4]="+20■";
	explanation[5]="（打出此牌后）双方都随机弃掉一张手牌";
	explanation[6]="+50■";
	explanation[7]="对方-20■";
	explanation[8]="将弃牌堆顶的牌加入对方手牌";
	explanation[9]="将手牌中所有的【惩罚】一同无消耗打出";
	explanation[10]="将手牌中所有◆>2的牌◆-1";
	explanation[11]="获得两回合的【持久】效果（每回合初额外+1◆）"; 
	explanation[12]="哼啊啊啊啊啊（随机触发一种有效果的牌的效果）";
	explanation[13]="将你手牌中所有的【一心同体】弃置";
	explanation[14]="把手牌里一张不是【一心同体】的牌变成【一心同体】";
	explanation[15]="增加 12AM 的概率 10%";
	explanation[16]="时间切换到下一个阶段";
	explanation[17]="随机调整时间";
	explanation[18]="（打出此牌后）手牌多的一方弃一张牌";
	explanation[19]="（打出此牌后）手牌多的一方摸一张牌";
	explanation[20]="你的随机一张无【浪人的恩赐】手牌得到【浪人的恩赐】";
	explanation[21]="你的随机两张无【术士的恩赐】手牌得到【术士的恩赐】";
	explanation[22]="你的随机两张无【法师的恩赐】手牌得到【法师的恩赐】";
	explanation[23]="你的随机一张无【战士的恩赐】手牌得到【战士的恩赐】";
	explanation[24]="你的随机两张无【地精的恩赐】手牌得到【地精的恩赐】";
	explanation[25]="你的随机两张无【恶魔的恩赐】手牌得到【恶魔的恩赐】";
	explanation[26]="你的随机一张无【牧师的恩赐】手牌得到【牧师的恩赐】";
	explanation[27]="你的所有无恩赐效果手牌得到【鱼人的恩赐】";
	explanation[28]="随机使用一张恩赐牌";
	explanation[29]="50%向对方手牌里加入一张【俄罗斯转盘】，否则清空自己的■";
	explanation[30]="把牌堆顶的牌◆+2";
	explanation[31]="在对方失衡时直接击杀对方，否则无效果";
	explanation[32]="减少30点躯干值，获得2回合【刚躯】buff：因得牌增加的躯干值减少三分之一";
	explanation[33]="（打出此牌后）对方增加 双方手牌数量差*6 的躯干值";
	explanation[34]="对方增加 (100-对方躯干值)/2 的躯干值";
	explanation[35]="对方获得1回合【画地为牢】buff：自己的回合只能主动打出至多两张牌";
	explanation[36]="将牌堆顶的牌费用+1并令对方摸一张牌";
	explanation[37]="将你手牌中的所有绝技升级为相应的秘传";
	explanation[38]="获得9层【飞渡漩涡云】buff：出牌恢复5点躯干值，且对手增加5点躯干值";
	explanation[39]="对方增加 (100-对方躯干值)*2/3 的躯干值";
	explanation[40]="将牌堆顶的牌费用+1并令对方摸两张牌";
	explanation[41]="使对方获得【雷电】buff：回合结束时若有【雷电】buff则其消失并摸两张牌";
	explanation[42]="若自己有【雷电】buff，将其传递给对手";
	explanation[43]="令对手从牌堆顶摸一张牌同时施展【雷电奉还】";
	explanation[44]="获得5层【飞渡浮舟】buff：出牌恢复5点躯干值（每出一张消耗一层）";
	explanation[45]="（打出此牌后）若对手手牌数量少于自己，则令其摸双方手牌差张牌";
	explanation[46]="解锁自己的起死回生之力";
	explanation[47]="对方增加 10 点躯干值，自己恢复 5 点躯干值";
	explanation[48]="对方增加 15 点躯干值，自己恢复 10 点躯干值";
	explanation[49]="削减对方 50 点魔法，多余的点数等量增加至对方的躯干值";
	explanation[50]="交换双方buff（不包括觉醒、愤怒、法师的恩赐、恶魔的恩赐）";
	explanation[51]="若回合结束时当你的手牌中【昏睡红茶】数量>1则摸一张牌";
	//qwq
	theskill[1].set_up("自由意志",40,1,1);
	theskill[2].set_up("命运指针",70,1,2);
	theskill[3].set_up("顶峰爆裂",0,0,3);
	theskill[4].set_up("混沌重组",50,1,4);
	theskill[5].set_up("两极分化",0,0,5);
	theskill[6].set_up("强行转化",40,1,6);
	theskill[7].set_up("这是l，这是r",0,0,7);
	theskill[8].set_up("这些边我不加",0,0,8);
	theskill[9].set_up("并查集查询",70,1,9);
	theskill[10].set_up("不稳定存在",0,0,10);
	theskill[11].set_up("不明所以",0,0,11); 
	theskill[12].set_up("徘徊",60,1,12);
	theskill[13].set_up("燃烧怒火",70,1,13);
	theskill[14].set_up("底线",0,0,14);
	theskill[15].set_up("偿还",0,0,15);
	theskill[16].set_up("坠落",80,1,16);
	theskill[17].set_up("庇护",0,0,17);
	theskill[18].set_up("祈祷",60,1,18); 
	theskill[19].set_up("觉醒",10,1,19);
	theskill[20].set_up("缥缈",0,0,20);
	theskill[21].set_up("沉睡",50,1,21);
	theskill[22].set_up("臭气弹",40,1,22);
	theskill[23].set_up("昏睡红茶",0,0,23);
	theskill[24].set_up("证言",0,1,24);
	//qwq
	skillexplanation[1]="将牌堆顶的牌的费用化为0并加入手牌";
	skillexplanation[2]="将自己的随机一张牌给予对方";
	skillexplanation[3]="在回合末时若有且仅有一张费用最大的牌则将其弃置";
	skillexplanation[4]="将双方的手牌混在一起随机重组（手牌数不变）";
	skillexplanation[5]="回合开始时抽到◆为偶数的牌则弃置重摸"; 
	skillexplanation[6]="+1◆";
	skillexplanation[7]="回合初60%你的一张无此效果的手牌得到【加边！加边！加边！】";
	skillexplanation[8]="回合初你没有带【加边！加边！加边！】的牌则+1◆";
	skillexplanation[9]="弃置你所有带有【加边！加边！加边！】的牌";
	skillexplanation[10]="游戏开始时费用上限-1，每回合开始时多摸一张牌，并+1◆";
	skillexplanation[11]="每回合初得到的◆为1~3";
	skillexplanation[12]="将手牌中费用最大的一张牌与对手手牌中费用最小的一张牌交换";
	skillexplanation[13]="获得3回合【愤怒】buff：因对方手牌效果获得的手牌被弃置";
	skillexplanation[14]="初始时手牌上限-2";
	skillexplanation[15]="因超过手牌上限而被弃掉的牌50%概率交给对手";
	skillexplanation[16]="手牌上限-1（最低为3，若已为3效果转为◆+2）";
	skillexplanation[17]="你的回合开始摸牌时如果摸到◆>3的牌则将其弃置";
	skillexplanation[18]="对方随机一张手牌◆+1";
	skillexplanation[19]="每使用一次费用+10,使用后永久获得1回合【觉醒】buff，然后使用任意技能时有【觉醒】层数*10%返还魔法";
	skillexplanation[20]="回合初的摸牌变为从牌堆顶摸一张牌给对手再从对手手牌中摸一张牌";
	skillexplanation[21]="使对方获得1回合【沉睡】buff：打出手牌后有35%概率结束回合";
	skillexplanation[22]="往对手手牌里加入1张【昏睡红茶】";
	skillexplanation[23]="这张牌费用为1◆，效果为若回合结束时当你的手牌中【昏睡红茶】数量>1则摸一张牌";
	skillexplanation[24]="提交一张牌作为证物打出";
	//qwq
	soullong=11;
	soullist[1]="自由";
	soulskill[1].push_back(theskill[1]);
	soulskill[1].push_back(theskill[2]);
	soulexplanation[1]="综合型较强，但魔法耗值高                  版 本 之 母";    
	soullist[2]="混沌";
	soulskill[2].push_back(theskill[3]);
	soulskill[2].push_back(theskill[4]);
	soulskill[2].push_back(theskill[10]);
	soulexplanation[2]="需要技巧性出牌，发动被动弃置费用大的牌    版 本 之 屑";
	soullist[3]="暴戾";
	soulskill[3].push_back(theskill[5]);
	soulskill[3].push_back(theskill[6]);
	soulskill[3].push_back(theskill[13]);
	soulexplanation[3]="积累费用，稳健进攻，还可防守              无 能 狂 怒";
	soullist[4]="谔谔";
	soulskill[4].push_back(theskill[7]);
	soulskill[4].push_back(theskill[8]);
	soulskill[4].push_back(theskill[9]);
	soulexplanation[4]="蓄势待发，后期快速清理手牌                加 边 加 边";
	soullist[5]="迷惘";
	soulskill[5].push_back(theskill[11]);
	soulskill[5].push_back(theskill[12]);
	soulexplanation[5]="快速积攒费用，同时说不定能摸到好牌        乒 乓 球 手";      
	soullist[6]="冷静";
	soulskill[6].push_back(theskill[14]);
	soulskill[6].push_back(theskill[15]);
	soulskill[6].push_back(theskill[16]);
	soulexplanation[6]="逐渐降低自己的限度，反击敌人              毫 无 底 线";
	soullist[7]="虔诚";
	soulskill[7].push_back(theskill[17]);
	soulskill[7].push_back(theskill[18]);
	soulskill[7].push_back(theskill[19]); 
	soulexplanation[7]="自战斗中觉醒，逐渐强大                    祈 求 厄 运";
	soullist[8]="幻想";
	soulskill[8].push_back(theskill[20]);
	soulskill[8].push_back(theskill[21]);
	soulexplanation[8]="在缥缈的虚无中战斗着                      睡 觉 狂 魔";
	soullist[9]="恶臭";
	soulskill[9].push_back(theskill[22]);
	soulskill[9].push_back(theskill[23]);
	soulexplanation[9]="哼，哼啊啊啊啊啊啊啊啊啊啊啊啊            野 兽 先 辈";
	soullist[10]="希望"; 
	soulexplanation[10]="自行搭配不同角色点主动技能和被动技能      缝 合 怪 物";
	soullist[11]="rand"; 
	soulexplanation[11]="？？？                                    任 您 选 择";
	//qwq
	speffectexplanation["加边！加边！加边！"]="使用【并查集查询】时此牌将被弃置";
	speffectexplanation["浪人的恩赐"]="当你拥有恩赐的手牌总数>3时这张牌将被弃置";
	speffectexplanation["术士的恩赐"]="打出这张牌时+15■";
	speffectexplanation["法师的恩赐"]="回合开始时有带有【法师的恩赐】的手牌数量*10%的概率+1◆";
	speffectexplanation["战士的恩赐"]="受到【惩罚】时免疫效果且你的这张牌的【战士的恩赐】消失";
	speffectexplanation["地精的恩赐"]="使【地精的恩赐】buff加2回合，【地精的恩赐】为3回合时转化为1◆";
	speffectexplanation["恶魔的恩赐"]="回合开始时有带有【恶魔的恩赐】的手牌数量*10%的概率弃一张牌";
	speffectexplanation["牧师的恩赐"]="当你的所有手牌都带有【牧师的恩赐】时直接获胜";
	speffectexplanation["鱼人的恩赐"]="打出这张牌时+5■";
	//qwq
	cardsystlong=4;
	cardsyst[1]="基础套牌";
	cardsyst[2]="时间套牌";
	cardsyst[3]="恩赐套牌";
	cardsyst[4]="只狼套牌";
	//qwq
	cardsystexplanation[1]="最为基础的牌型";
	cardsystexplanation[2]="需要打开时间模式才能打开";
	cardsystexplanation[3]="来自 CARD-GAME 各职业人物的恩赐";
	cardsystexplanation[4]="需要进入 娱乐模式：只狼 才可打开";
	//qwq
	thecardsyst[1]=thecardsyst[2]=thecardsyst[3]=1;
	//qwq
	gamemodelong=3;
	gamemodename[1]="经典模式";
	gamemodename[2]="娱乐模式：计时";
	gamemodename[3]="竞技模式：只狼";
	gamemodename[4]="娱乐模式：逆转裁判"; 
	//qwq
	gamemodeexplanation[1]="最经典的游戏模式";
	gamemodeexplanation[2]="每回合开局多摸1张牌，在20回合后手牌数量少的人获胜";
	gamemodeexplanation[3]="每得到一张手牌便增加躯干值，躯干值充满将被对方忍杀";
	gamemodeexplanation[4]="在战斗过程中对对手打出的牌提出异议，逆转战局";
}
//qwq
void wolf()
{
	printf("请仔细阅读游戏规则:\n\n");
	printf("1.只狼模式下双方存在满格为100的躯干值，躯干值充满时将失去平衡\n\n");
	printf("2.每得到一张手牌则增加 手牌费用*6 的躯干值\n\n");
	printf("3.每回合初（摸牌前）减少 20*(手牌上限-手牌数量)/手牌数量的躯干值\n\n");
	printf("4.只狼套牌里存在一些牌可以对躯干值造成影响\n\n");
	printf("5.如果手牌打完不会直接胜利，而是再摸一张牌并且对方增加 20 躯干值\n\n");
	printf("6.当对方失衡时可使用【忍杀】击杀对方\n  若此时对方拥有未被封印（呈现红色）的起死回生之力将复活并且躯干值回到0，同时起死回生之力少去一点被封印（呈现灰色）");
	printf("\n  用【忍杀】击杀对方可以回复自己的 20 点躯干值并解锁自己的起死回生之力\n\n");
	printf("7.回合结束时若手牌数等于手牌上限则增加 10 点躯干值\n\n");
	printf("8.按下空格或者Enter继续");
}
//qwq
//From PreInfo.h
void SetColor(short x)
{
  if(x>=0 && x<=15)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
  else
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
//qwq
void Shake(int power,int time){
	int shake_time = 25;
    int shake_distance = power;
    RECT rect;
    HWND window = NULL, oldwindow = NULL;
    int x, y, width, height;
    int i;
    for (i = 0; i < time; i++) {
        window = GetForegroundWindow();
        if (window != oldwindow) {
            GetWindowRect(window, &rect);
            x = rect.left;
            y = rect.top;
            width = rect.right - x;
            height = rect.bottom - y;
            oldwindow = window;
        }
        MoveWindow(window, x - shake_distance, y, width, height, TRUE); 
        Sleep(shake_time); 
        MoveWindow(window, x - shake_distance, y - shake_distance, width, height, TRUE);
        Sleep(shake_time);
        MoveWindow(window, x, y - shake_distance, width, height, TRUE);
        Sleep(shake_time);
        MoveWindow(window, x, y, width, height, TRUE);
        Sleep(shake_time);
    }
    return;
}
//为临时更新传递的实现请勿删除本行
