#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<conio.h>
#include<assert.h>
#include<tchar.h>
#include"Socket(ACG).hpp"
#define iv inline void
#define REP(x) for(int i=1;i<=x;i++)
#define G 0
using namespace std;
using namespace __gnu_pbds;
string version="2.0.4";
iv printhandcard(int choose);
iv title();
iv cardsystem();
iv addhandcard(vector<card> *t,card t2,int *handcardmax,vector<buff> *thebuff);
iv init_server();
iv maingame();
iv update_code();
iv recheck();
bool visskill[114];
int firsthand=3;
int timemode=1;
int gamemode=1;
bool foundfavour(card a)
{
	if(found(a.speffect,"���˵Ķ���") or found(a.speffect,"��ʿ�Ķ���") or found(a.speffect,"��ʦ�Ķ���") or found(a.speffect,"սʿ�Ķ���") or found(a.speffect,"��ħ�Ķ���") or found(a.speffect,"�ؾ��Ķ���") or found(a.speffect,"��ʦ�Ķ���") or found(a.speffect,"���˵Ķ���")) return true;
	else return false;
}
iv addfavour(card &a,string favour)
{
	if(found(a.speffect,"���˵Ķ���")) a.speffect[founds(a.speffect,"���˵Ķ���")]=favour;
	else if(found(a.speffect,"��ʿ�Ķ���")) a.speffect[founds(a.speffect,"��ʿ�Ķ���")]=favour;
	else if(found(a.speffect,"��ʦ�Ķ���")) a.speffect[founds(a.speffect,"��ʦ�Ķ���")]=favour;
	else if(found(a.speffect,"սʿ�Ķ���")) a.speffect[founds(a.speffect,"սʿ�Ķ���")]=favour;
	else if(found(a.speffect,"��ħ�Ķ���")) a.speffect[founds(a.speffect,"��ħ�Ķ���")]=favour;
	else if(found(a.speffect,"�ؾ��Ķ���")) a.speffect[founds(a.speffect,"�ؾ��Ķ���")]=favour;
	else if(found(a.speffect,"��ʦ�Ķ���")) a.speffect[founds(a.speffect,"��ʦ�Ķ���")]=favour;
	else if(found(a.speffect,"���˵Ķ���")) a.speffect[founds(a.speffect,"���˵Ķ���")]=favour;
	else a.speffect.push_back(favour); 
}
iv addcard(int kind,card t) //���ƶ������ 
{
	if(cardheap.size()==0)
	{
		cardheap.push_back(t);
		return;
	}
	if(kind==1) //�������λ�� 
	{
		int s=ran(0,cardheap.size());
		if(s==cardheap.size()) cardheap.push_back(t);
		else cardheap.insert(cardheap.begin()+s,t);
	}
	if(kind==2) //�����ƶѶ� 
		cardheap.insert(cardheap.begin(),t);
}
iv dealcard() //����
{
	cardheap.clear();
	if(thecardsyst[1])
	{
		REP(21) addcard(1,card("�ͷ�",1,1));
		REP(6) addcard(1,card("��������",2,2));
		REP(4) addcard(1,card("���",1,3));
		REP(5) addcard(1,card("΢С����",1,4));
		REP(4) addcard(1,card("������Ӯ",1,5)); 
		REP(5) addcard(1,card("�еȷ���",2,6));
		REP(5) addcard(1,card("��־�ݻ�",2,7));
		REP(7) addcard(1,card("����ֻ�",1,8));
		REP(3) addcard(1,card("�ռ��ͽ�",2,9));
		REP(4) addcard(1,card("ħ�ð�Ϸ",1,10));
		REP(5) addcard(1,card("�ɳ־û�",1,11));
		REP(3) addcard(1,card("1919810",1,12));
		REP(9) addcard(1,card("һ��ͬ��",2,13));
		REP(4) addcard(1,card("����ͬ��",1,14));
		REP(4) addcard(1,card("��ƽ����",2,18));
		REP(5) addcard(1,card("�䱾����",2,19));
		REP(3) addcard(1,card("����˹ת��",2,29));
		REP(2) addcard(1,card("���II",3,30));
		REP(4) addcard(1,card("����Ϊ��",1,35));
		REP(3) addcard(1,card("OBJECTION",2,50));
		addcard(1,card("�谭",3,0));	
	}
	if(thecardsyst[2])
	{
		REP(6) addcard(1,card("����̫��",2,15));
		REP(8) addcard(1,card("ʱ������",1,16));
		REP(4) addcard(1,card("糺�֮��",1,17));
	}
	if(thecardsyst[3])
	{
		REP(2) addcard(1,card("���˵Ķ���",1,20));
		REP(2) addcard(1,card("��ʿ�Ķ���",1,21));
		REP(2) addcard(1,card("��ʦ�Ķ���",2,22));
		REP(3) addcard(1,card("սʿ�Ķ���",2,23));
		REP(3) addcard(1,card("�ؾ��Ķ���",1,24));
		REP(2) addcard(1,card("��ħ�Ķ���",2,25));
		REP(2) addcard(1,card("��ʦ�Ķ���",1,26));
		REP(1) addcard(1,card("���˵Ķ���",1,27));	
		REP(1) addcard(1,card("��Ե�Ķ���",1,28));	
	}
	if(thecardsyst[4])
	{
		REP(8) addcard(1,card("��ɱ",1,31));
		REP(6) addcard(1,card("������",2,32));
		REP(4) addcard(1,card("������έ��ʮ��ն",2,33));
		REP(4) addcard(1,card("����������ն",2,34));
		REP(4) addcard(1,card("��������������ͻ��",2,36));
		REP(4) addcard(1,card("έ��������",1,37));
		REP(3) addcard(1,card("��֮��",1,41));
		REP(2) addcard(1,card("�׵�",1,42));
		REP(2) addcard(1,card("�ش���ӣ��",1,43));
		REP(3) addcard(1,card("�������ɶɸ���",1,44));
		addcard(1,card("��ط¶��",1,46));
		REP(3) addcard(1,card("һ��ն",1,47));
		REP(3) addcard(1,card("һ��ն������",1,48));
		REP(2) addcard(1,card("�ش�������",2,49));
	}
}
card drawcard() //���� 
{
	if(cardheap.size()==0) dealcard();
	card t=cardheap[0];
	cardheap.erase(cardheap.begin());
	return t;
}
iv startgame() //��ʼ��Ϸ 
{
	if(server_mode==1 or server_mode==3)
	{
		dealcard();
		cost1=cost2=0;
		costmax1=costmax2=5;
		mana1=mana2=manamax1=manamax2=100;
		handcardmax1=handcardmax2=10;
		if(foundskill(&skills1,"����")) handcardmax1-=2;
		if(foundskill(&skills2,"����")) handcardmax2-=2;
		if(firsthand!=3) turn=firsthand;
		else turn=ran(1,2);
		if(turn==1) cost2++;
		else cost1++;
		if(timemode) tim=ran(1,4);
		REP(4) addhandcard(&handcard1,drawcard(),&handcardmax1,&buff1);
		REP(4) addhandcard(&handcard2,drawcard(),&handcardmax2,&buff2);
		if(foundskill(&skills1,"���ȶ�����")) costmax1--;
		if(foundskill(&skills2,"���ȶ�����")) costmax2--;
		trunk1=trunk2=0;sekiroblood1=sekiroblood2=3;bloodsure1=bloodsure2=1;
		if(server_mode==1) send_situation();
	}
	if(server_mode==2)
		recv_situation();
}
vector<card> *cardmine,*cardhis;
int *costmine,*costmaxmine,*costhis,*costmaxhis,*manamine,*manahis,*manamaxmine,*manamaxhis;
int *handcardmaxmine,*handcardmaxhis;
vector<skill> *skillsmine,*simpleskillsmine;
string *soulmine,*soulhis;
vector<buff> *buffmine,*buffhis;
int Choose=1,sure_to_use=0,sure_to_magic=0,sure_to_end=0;
int handkind=1;
int provemode=1; 
bool proving=0;
iv printground()
{
	//system("cls");
	if(gamemode==2)
	{
		moveto(0,0);
		print("ʣ��غ�����  ");
		moveto(12,0);print(change(20-clocks));
	}
	if(timemode)
	{
		moveto(18,0);print(string(50,' '));
		moveto(18+tim%2,0);
		if(tim==1) cyan("6AM | �غϿ�ʼʱ������1��");
		if(tim==2) red("12AM | �����ʱ��"+change(twelveam*10)+"%���ʻ��1��");
		if(tim==3) yellow("6PM | �غϿ�ʼʱ����1����");
		if(tim==4) grey("12PM | ������Ч��");
	}
	moveto(6,2);print("#1");
	moveto(14,2);cyan(change(cost1)+"/"+change(costmax1));
	moveto(24,2);REP(costmax1) cyan("��");
	moveto(24,2);REP(cost1) cyan("��");
	moveto(6,3);print(soul1);
	moveto(14,3);print("       ");
	moveto(14,3);blue(change(mana1)+"/"+change(manamax1));
	moveto(24,3);REP(manamax1/20) blue("��");
	moveto(24,3);REP(mana1/20) blue("��");
	moveto(14,4);print("     ");
	moveto(14,4);print(change(handcard1.size())+"/"+change(handcardmax1));
	if(gamemode==3)
	{
		moveto(40,2);print("            ");moveto(40,2);
		if(bloodsure1==1) REP(sekiroblood1) red("��");
		else REP(sekiroblood1) grey("��");
		moveto(6,4);print("       ");
		moveto(6,4);
		if(trunk1==100) red("ʧ��");else yellow(change(trunk1)+"/100");	
		moveto(40,3);
		REP(3) red("��");REP(14) yellow("��");REP(3) red("��");
		moveto(60-trunk1/10*2,3);REP(trunk1/10*2) yellow("��");
		if(trunk1>=80) moveto(44,3),red("��"),moveto(74,3),red("��");
		if(trunk1>=90) moveto(42,3),red("��"),moveto(76,3),red("��");
		if(trunk1>=100) moveto(40,3),red("��"),moveto(78,3),red("��");
	}
	if(gamemode==4 and server_mode==1)
	{
		moveto(6,8);print("       ");
		moveto(6,8);
		if(provemode==2) blue("֤����");
	}
	moveto(24,4);print(string(100,' '));moveto(24,4);
	for(int i=0;i<buff1.size();i++)
	{
		if(i) print(" | ");
		if(buff1[i].name=="�־�") cyan("�־� "+change(buff1[i].tim));
		if(buff1[i].name=="��ʦ�Ķ���") blue("��ʦ�Ķ���");
		if(buff1[i].name=="��ħ�Ķ���") purple("��ħ�Ķ���");
		if(buff1[i].name=="�ؾ��Ķ���") green("�ؾ��Ķ��� "+change(buff1[i].tim)); 
		if(buff1[i].name=="��ŭ") red("��ŭ "+change(buff1[i].tim));
		if(buff1[i].name=="����") yellow("���� "+change(buff1[i].tim));
		if(buff1[i].name=="����Ϊ��") grey("����Ϊ�� "+change(buff1[i].tim));
		if(buff1[i].name=="��˯") blue("��˯ "+change(buff1[i].tim));
		if(buff1[i].name=="����") yellow("���� "+change(buff1[i].tim));
		if(buff1[i].name=="�׵�") yellow("�׵�"); 
		if(buff1[i].name=="�ɶɸ���") cyan("�ɶɸ��� "+change(buff1[i].tim));
		if(buff1[i].name=="�ɶ�������") cyan("�ɶ������� "+change(buff1[i].tim));
	}
	//qwq 
	moveto(6,6);print("#2");
	moveto(14,6);cyan(change(cost2)+"/"+change(costmax2));
	moveto(24,6);REP(costmax2) cyan("��");
	moveto(24,6);REP(cost2) cyan("��");
	moveto(6,7);print(soul2);
	moveto(14,7);print("       ");
	moveto(14,7);blue(change(mana2)+"/"+change(manamax2));
	moveto(24,7);REP(manamax2/20) blue("��");
	moveto(24,7);REP(mana2/20) blue("��");
	moveto(14,8);print("     ");
	moveto(14,8);print(change(handcard2.size())+"/"+change(handcardmax2));
	if(gamemode==3)
	{
		moveto(40,6);print("            ");moveto(40,6);
		if(bloodsure2==1) REP(sekiroblood2) red("��");
		else REP(sekiroblood2) grey("��");
		moveto(6,8);print("       ");
		moveto(6,8);
		if(trunk2==100) red("ʧ��");else yellow(change(trunk2)+"/100");	
		moveto(40,7);
		REP(3) red("��");REP(14) yellow("��");REP(3) red("��");
		moveto(60-trunk2/10*2,7);REP(trunk2/10*2) yellow("��");
		if(trunk2>=80) moveto(44,7),red("��"),moveto(74,7),red("��");
		if(trunk2>=90) moveto(42,7),red("��"),moveto(76,7),red("��");
		if(trunk2>=100) moveto(40,7),red("��"),moveto(78,7),red("��");
	}
	if(gamemode==4 and server_mode==2)
	{
		moveto(6,8);print("       ");
		moveto(6,8);
		if(provemode==2) blue("֤����");
	}
	moveto(24,8);print(string(100,' '));moveto(24,8);
	for(int i=0;i<buff2.size();i++)
	{
		if(i) print(" | ");
		if(buff2[i].name=="�־�") cyan("�־� "+change(buff2[i].tim));
		if(buff2[i].name=="��ʦ�Ķ���") blue("��ʦ�Ķ���");
		if(buff2[i].name=="��ħ�Ķ���") purple("��ħ�Ķ���");
		if(buff2[i].name=="�ؾ��Ķ���") green("�ؾ��Ķ��� "+change(buff2[i].tim)); 
		if(buff2[i].name=="��ŭ") red("��ŭ "+change(buff2[i].tim));
		if(buff2[i].name=="����") yellow("���� "+change(buff2[i].tim));
		if(buff2[i].name=="����Ϊ��") grey("����Ϊ�� "+change(buff2[i].tim));
		if(buff2[i].name=="��˯") blue("��˯ "+change(buff2[i].tim));
		if(buff2[i].name=="����") yellow("���� "+change(buff2[i].tim));
		if(buff2[i].name=="�׵�") yellow("�׵�"); 
		if(buff2[i].name=="�ɶɸ���") cyan("�ɶɸ��� "+change(buff2[i].tim));
		if(buff2[i].name=="�ɶ�������") cyan("�ɶ������� "+change(buff2[i].tim));
	}
	//qwq
	moveto(0,11);print("P"+change(turn));
	moveto(8,11);print("#");
	if(!proving)
	{
		moveto(12,11);
		if(turn==server_mode or server_mode==3) 
		{
			if(handkind==1) cyan("��");
			if(handkind==2) blue("��");	
			printhandcard(Choose);
		}
		else
			red("��");
	}
}
int otherlist[114],cardsum=0,skillsum=0;
card othercardlist[114];
skill otherskilllist[114];
iv UI_other()
{
	int p1=0,p2=0;
	for(int i=1;i<=cardsum+skillsum;i++)
	{
		moveto(8,11+i);print(change(i));
		moveto(12,11+i);
		if(otherlist[i]==1)
		{
			p1++;
			cyan(change(othercardlist[p1].cost));
			moveto(15,11+i);cyan("["+othercardlist[p1].name+"]");
			if(gamemode==3) moveto(38,11+i);
			else moveto(30,11+i);
			for(int j=0;j<othercardlist[p1].speffect.size();j++)
			{
				string oo=othercardlist[p1].speffect[j];
				if(oo=="��ħ�Ķ���2") purple("[��ħ�Ķ���]");
				else if(oo=="��Ч" or oo=="ʧЧ") purple("["+oo+"]");
				else cyan("["+oo+"]");
			}
		}
		else
		{
			p2++;
			blue(change(otherskilllist[p2].mana));
			moveto(15,11+i);blue("["+otherskilllist[p2].name+"]");
		}
	}
	if(cardsum+skillsum!=0)
	{
		moveto(10,24);print(string(100,' '));
		moveto(10,25);print(string(80,' '));
		moveto(10,26);print(string(80,' '));
		if(otherlist[cardsum+skillsum]==1)
		{
			if(othercardlist[cardsum].effect)
			{
				moveto(10,24);print(explanation[othercardlist[cardsum].effect]);
				int pon=0;
				for(int i=0;i<(othercardlist[cardsum].speffect.size());i++)
				{
					string oo=othercardlist[cardsum].speffect[i];
					if(oo!="��ħ�Ķ���2" and oo!="��Ч" and oo!="ʧЧ")
					{
						moveto(10,25+pon);
						print("["+(othercardlist[cardsum].speffect[i])+"]:"+speffectexplanation[othercardlist[cardsum].speffect[i]]);
						pon++;
					}
				}
			}
		}
		else
		{
			moveto(10,24);
			print(skillexplanation[otherskilllist[skillsum].effect]);
		}
	}
}
iv printhandcard(int choose)
{
	if(handkind==1)
	{
		for(int i=0;i<(cardmine->size());i++)
		{
			moveto(6,12+i);printf("  ");
			moveto(8,12+i);printf("  ");moveto(8,12+i);print(change(i+1));
			moveto(12,12+i);if((*cardmine)[i].cost<=*costmine)cyan(change((*cardmine)[i].cost));else blue(change((*cardmine)[i].cost));
			moveto(15,12+i);print(string(70,' '));
			moveto(15,12+i);print("["+(*cardmine)[i].name+"]");
			if(gamemode==3) moveto(38,12+i);
			else moveto(30,12+i);
			for(int j=0;j<(*cardmine)[i].speffect.size();j++)
				print("["+(*cardmine)[i].speffect[j]+"]");
		}
		moveto(6,11+choose);
		if(sure_to_use) print("��");
		else print("��");
		moveto(8,11+choose);green(change(choose));
		moveto(12,11+choose);green(change((*cardmine)[choose-1].cost));
		moveto(15,11+choose);green("["+(*cardmine)[choose-1].name+"]");
		if(gamemode==3) moveto(38,11+choose);
		else moveto(30,11+choose);
		for(int j=0;j<(*cardmine)[choose-1].speffect.size();j++)
			green("["+(*cardmine)[choose-1].speffect[j]+"]");
		//qwq
		moveto(10,24);print(string(80,' '));
		moveto(10,24);
		if((*cardmine)[choose-1].effect) print(explanation[(*cardmine)[choose-1].effect]);
		moveto(10,23);print(string(80,' '));moveto(10,23);
		if((*cardmine)[choose-1].effect==8)
		{
			if(recardheap.size()==0) print("��ǰ���ƶ�û���ƣ�ʹ��������û���κ�Ч��");
			else print("��ǰ�ƶѶ�����Ϊ��"+recardheap[recardheap.size()-1].name+"��");
		}
		moveto(10,25);print(string(80,' '));moveto(10,26);print(string(80,' '));
		for(int i=0;i<((*cardmine)[choose-1].speffect.size());i++)
		{
			moveto(10,25+i);
			print("["+((*cardmine)[choose-1].speffect[i])+"]:"+speffectexplanation[(*cardmine)[choose-1].speffect[i]]);
		}
	}
	if(handkind==2)
	{
		for(int i=0;i<(simpleskillsmine->size());i++)
		{
			moveto(6,12+i);printf("  ");
			moveto(8,12+i);printf("  ");moveto(8,12+i);
			if(visskill[i]) red(change(i+1));else print(change(i+1));
			moveto(12,12+i);
			if(visskill[i]) red(change((*simpleskillsmine)[i].mana));
			else blue(change((*simpleskillsmine)[i].mana));
			moveto(15,12+i);print(string(15,' '));
			moveto(15,12+i);
			if(visskill[i]) red("["+(*simpleskillsmine)[i].name+"]");
			else print("["+(*simpleskillsmine)[i].name+"]");
		}
		moveto(6,11+choose);
		if(sure_to_use) print("��");
		else print("��");
		moveto(8,11+choose);green(change(choose));
		moveto(12,11+choose);green(change((*simpleskillsmine)[choose-1].mana));
		moveto(15,11+choose);green("["+(*simpleskillsmine)[choose-1].name+"]");
		//qwq
		moveto(10,24);print(string(80,' '));
		moveto(10,24);
		if((*simpleskillsmine)[choose-1].effect) print(skillexplanation[(*simpleskillsmine)[choose-1].effect]);
	}
}
iv choosechanged(int lastchoose,int choose)
{
	if(handkind==1)
	{
		moveto(6,11+lastchoose);print("  "+change(lastchoose));
		moveto(12,11+lastchoose);if((*cardmine)[lastchoose-1].cost<=*costmine) cyan(change((*cardmine)[lastchoose-1].cost));else blue(change((*cardmine)[lastchoose-1].cost));
		moveto(15,11+lastchoose);print("["+(*cardmine)[lastchoose-1].name+"]");
		if(gamemode==3) moveto(38,11+lastchoose);
		else moveto(30,11+lastchoose);
		for(int j=0;j<(*cardmine)[lastchoose-1].speffect.size();j++)
			print("["+(*cardmine)[lastchoose-1].speffect[j]+"]");
		//qwq
		moveto(6,11+choose);
		if(sure_to_use) print("��");
		else print("��");
		moveto(8,11+choose);green(change(choose));
		moveto(12,11+choose);green(change((*cardmine)[choose-1].cost));
		moveto(15,11+choose);green("["+(*cardmine)[choose-1].name+"]");
		if(gamemode==3) moveto(38,11+choose);
		else moveto(30,11+choose);
		for(int j=0;j<(*cardmine)[choose-1].speffect.size();j++)
			green("["+(*cardmine)[choose-1].speffect[j]+"]");
		//qwq	
		moveto(10,24);print(string(85,' '));
		moveto(10,24);
		if((*cardmine)[choose-1].effect) print(explanation[(*cardmine)[choose-1].effect]);
		moveto(10,23);print(string(80,' '));moveto(10,23);
		if((*cardmine)[choose-1].effect==8)
		{
			if(recardheap.size()==0) print("��ǰ���ƶ�û���ƣ�ʹ��������û���κ�Ч��");
			else print("��ǰ�ƶѶ�����Ϊ��"+recardheap[recardheap.size()-1].name+"��");
		}
		moveto(10,25);print(string(85,' '));moveto(10,26);print(string(85,' '));
		for(int i=0;i<((*cardmine)[choose-1].speffect.size());i++)
		{
			moveto(10,25+i);
			print("["+((*cardmine)[choose-1].speffect[i])+"]:"+speffectexplanation[(*cardmine)[choose-1].speffect[i]]);
		}
	}
	if(handkind==2)
	{
		moveto(6,11+lastchoose);if(visskill[lastchoose-1]) red("  "+change(lastchoose));else print("  "+change(lastchoose));
		moveto(12,11+lastchoose);if(visskill[lastchoose-1]) red(change((*simpleskillsmine)[lastchoose-1].mana));else blue(change((*simpleskillsmine)[lastchoose-1].mana));
		moveto(15,11+lastchoose);if(visskill[lastchoose-1]) red("["+(*simpleskillsmine)[lastchoose-1].name+"]");else print("["+(*simpleskillsmine)[lastchoose-1].name+"]");
		//qwq
		moveto(6,11+choose);
		if(sure_to_use) print("��");
		else print("��");
		moveto(8,11+choose);green(change(choose));
		moveto(12,11+choose);green(change((*simpleskillsmine)[choose-1].mana));
		moveto(15,11+choose);green("["+(*simpleskillsmine)[choose-1].name+"]");
		//qwq
		moveto(10,24);print(string(100,' '));
		moveto(10,24);
		if((*simpleskillsmine)[choose-1].effect) print(skillexplanation[(*simpleskillsmine)[choose-1].effect]);
	}
}
iv win_screen(int kind)
{
	system("cls");
	if(kind==4) red("����Է��İ汾��ͬ���޷���������\n�볢������ʱ���´���ѡ���н��и���");
	else if(kind==3) cyan("�ⳡ��Ϸ�Ľ����ƽ��");
	else 
	{
		if(server_mode==3)
			green("P"+change(kind)+"����˱�����Ϸ��ʤ��������");
		else
		{
			if(kind==server_mode) green("�����˱�����Ϸ��ʤ��������");
			else red("������˶Է�����");	
		}
	}
	if(server_mode!=3) closesocket(Client);
	Sleep(3000);
	while(_kbhit()) getch();
	maingame();
}
iv win()
{
	if(handcard1.size()==0 and handcard2.size()==0 and gamemode!=3)
	{
		if(server_mode<3)
		{
			send_string2("Win");
			send_int2(3);	
		}
		win_screen(3);
	}
	if(handcard1.size()==0)
	{
		if(gamemode==3)
		{
			trunk2=min(trunk2+20,100);
			addhandcard(&handcard1,drawcard(),&handcardmax1,&buffclear);
			return;
		}
		if(server_mode<3)
		{
			send_string2("Win");
			send_int2(1);	
		}
		win_screen(1);
	}
	if(handcard2.size()==0)
	{
		if(gamemode==3)
		{
			trunk1=min(trunk1+20,100);
			addhandcard(&handcard2,drawcard(),&handcardmax2,&buffclear);
			return;
		}
		if(server_mode<3)
		{
			send_string2("Win");
			send_int2(2);
		}
		win_screen(2);
	}
}
iv throwcard(vector<card> *t,int pos)
{
	if(t->size()==0)
		return;
	moveto(5,11+(t->size()));print(string(70,' '));
	recardheap.push_back((*t)[pos-1]);
	t->erase(t->begin()+pos-1);
	if((t->size())==0)
		win();
}
iv increasecost(int *cos,int *cosmax,int delta)
{
	if(*cos+delta>*cosmax) *cos=*cosmax;
	else if(*cos+delta<0) *cos=0;
	else *cos+=delta;
}
iv increasemana(int *man,int *manmax,int delta)
{
	if(*man+delta>*manmax) *man=*manmax;
	else if(*man+delta<0) *man=0;
	else *man+=delta;
}
iv update_trunk(vector<card> *t,card t2)
{
	if(gamemode==3)
	{
		if(t==&handcard1)
		{
			if(foundbuff(&buff1,"����")!=-1) trunk1+=t2.cost*4;
			else trunk1+=t2.cost*6;
		}
		else
		{
			if(foundbuff(&buff2,"����")!=-1) trunk2+=t2.cost*4;
			else trunk2+=t2.cost*6;
		}
		if(trunk1>100) trunk1=100;
		if(trunk2>100) trunk2=100;
	}
}
iv addhandcard(vector<card> *t,card t2,int *handcardmax,vector<buff> *thebuff)  
{
	t->push_back(t2);
	if(handcard1.size()>handcardmax1 and foundskill(&skills1,"����"))
	{
		update_trunk(t,t2);
		if(ran(1,2)==1)
		{
			t->erase(t->begin()+t->size()-1);
			if(turn==1)
			{
				send_a_skill(theskill[15]);	
				send_a_card(thethrowcard(t2));
			}
			addhandcard(&handcard2,t2,&handcardmax2,&buff2);
		}
		else throwcard(t,t->size()); 
	}
	else if(handcard2.size()>handcardmax2 and foundskill(&skills2,"����"))
	{
		update_trunk(t,t2);
		if(ran(1,2)==1)
		{
			t->erase(t->begin()+t->size()-1);	
			if(turn==2)
			{
				send_a_skill(theskill[15]);
				send_a_card(thethrowcard(t2));
			}	
			addhandcard(&handcard1,t2,&handcardmax1,&buff1);
		}
		else throwcard(t,t->size()); 
	}
	else if(t->size()>*handcardmax)
	{
		update_trunk(t,t2);
		throwcard(t,t->size());
	}
	else if(foundbuff(thebuff,"��ŭ")!=-1)	
		throwcard(t,t->size());
	else if(gamemode==3)
		update_trunk(t,t2);
}
iv usecard(card t,int pos)
{
	int prob=0;
	card g=t;
	if(t.effect==29)
	{
		prob=ran(1,2);
		if(prob==1) g.speffect.push_back("��Ч");
		else g.speffect.push_back("ʧЧ"); 
	}
	send_a_card(g);
	if(found(t.speffect,"�ؾ��Ķ���"))
	{
		if(foundbuff(buffmine,"�ؾ��Ķ���")==-1)
		{
			buff s;s.set_up("�ؾ��Ķ���",0);
			buffmine->push_back(s);
		}
		(*buffmine)[foundbuff(buffmine,"�ؾ��Ķ���")].tim+=2;
		if((*buffmine)[foundbuff(buffmine,"�ؾ��Ķ���")].tim>=3)
		{
			(*buffmine)[foundbuff(buffmine,"�ؾ��Ķ���")].tim-=3,increasecost(costmine,costmaxmine,1);
			if((*buffmine)[foundbuff(buffmine,"�ؾ��Ķ���")].tim==0) buffmine->erase((buffmine->begin())+foundbuff(buffmine,"�ؾ��Ķ���"));
		}
	}
	if(found(t.speffect,"��ʿ�Ķ���"))
		increasemana(manamine,manamaxmine,15);
	if(found(t.speffect,"���˵Ķ���"))
		increasemana(manamine,manamaxmine,5);
	if(pos!=114514)
	{
		throwcard(cardmine,pos);
		if(foundbuff(buffmine,"�ɶɸ���")!=-1)
		{
			if(turn==1) trunk1-=5;
			if(turn==2) trunk2-=5;
			(*buffmine)[foundbuff(buffmine,"�ɶɸ���")].tim--;
			if((*buffmine)[foundbuff(buffmine,"�ɶɸ���")].tim==0) buffmine->erase(buffmine->begin()+foundbuff(buffmine,"�ɶɸ���"));
		}
		if(foundbuff(buffmine,"�ɶ�������")!=-1)
		{
			if(turn==1) trunk1-=5,trunk2+=5;
			if(turn==2) trunk2-=5,trunk1+=5;
			(*buffmine)[foundbuff(buffmine,"�ɶ�������")].tim--;
			if((*buffmine)[foundbuff(buffmine,"�ɶ�������")].tim==0) buffmine->erase(buffmine->begin()+foundbuff(buffmine,"�ɶ�������"));
		}
		if(trunk1>100) trunk1=100;
		if(trunk2>100) trunk2=100;
		if(trunk1<0) trunk1=0;
		if(trunk2<0) trunk2=0;
	} 
	if(t.effect==1) 
	{
		for(int i=0;i<(cardhis->size());i++)
			if(found((*cardhis)[i].speffect,"սʿ�Ķ���"))
			{
				(*cardhis)[i].speffect.erase((*cardhis)[i].speffect.begin()+i);
				return;
			}
		addhandcard(cardhis,drawcard(),handcardmaxhis,buffhis);
	}
	if(t.effect==2)
	{
		Shake(5,1);
		send_a_shake();
		int pp=ran(1,(cardmine->size()));
		send_a_card(thethrowcard((*cardmine)[pp-1]));
		throwcard(cardmine,pp);
	}
	if(t.effect==3)
		addcard(2,card("�谭",3,0));
	if(t.effect==4)
		increasemana(manamine,manamaxmine,20);
	if(t.effect==5)
	{
		Shake(5,1);
		send_a_shake();
		int pp=ran(1,(cardmine->size()));
		send_a_card(thethrowcard((*cardmine)[pp-1]));
		throwcard(cardmine,pp);
		pp=ran(1,(cardhis->size()));
		throwcard(cardhis,pp);
	}
	if(t.effect==6)
		increasemana(manamine,manamaxmine,50);
	if(t.effect==7)
		increasemana(manahis,manamaxhis,-20);
	if(t.effect==8)
		if(recardheap.size()>1)
		{
			card s=recardheap[recardheap.size()-2];
			recardheap.erase(recardheap.begin()+(recardheap.size()-2));
			addhandcard(cardhis,s,handcardmaxhis,buffhis);
		}
	if(t.effect==9)
	{
		bool flagg=1;int tt=0;
		while(flagg)
		{
			flagg=0;
			for(int i=0;i<(cardmine->size());i++)
				if((*cardmine)[i].name=="�ͷ�")
				{
					flagg=1;
					usecard((*cardmine)[i],i+1);
					tt++;
					break;
				}
		}
		if(tt>=2) Shake(3,1);
	}
	if(t.effect==10)
		for(int i=0;i<(cardmine->size());i++)
			if((*cardmine)[i].cost>2)
				(*cardmine)[i].cost--;
	if(t.effect==11)
	{
		int del=0;
		if(foundbuff(buffmine,"�־�")==-1)
		{
			buff s;s.set_up("�־�",0);
			buffmine->push_back(s);
			del=1;
		}
		(*buffmine)[foundbuff(buffmine,"�־�")].tim+=2+del;
	}
	if(t.effect==12)
	{
		int s=ran(1,cardlong);
		while(s==12 or (15<=s and s<=17 and !thecardsyst[2]) or (20<=s and s<=28 and !thecardsyst[3]) or (((31<=s and s<=34) or (36<=s and s<=49)) and !thecardsyst[4])) s=ran(1,cardlong);
		usecard(card(cardname[s],0,s),114514);
		moveto(0,1);print("��ʹ���ˡ�"+cardname[s]+"��");
	}
	if(t.effect==13)
	{
		bool flagg=1;
		while(flagg)
		{
			flagg=0;
			for(int i=0;i<(cardmine->size());i++)
				if((*cardmine)[i].name=="һ��ͬ��")
				{
					flagg=1;
					send_a_card(thethrowcard((*cardmine)[i]));
					throwcard(cardmine,i+1);
					break;
				}
		}
	}	
	if(t.effect==14)
	{
		vector<int> cywakioi;cywakioi.clear();
		for(int i=0;i<(cardmine->size());i++)
			if((*cardmine)[i].name!="һ��ͬ��")
				cywakioi.push_back(i);
		if(cywakioi.size()) (*cardmine)[cywakioi[ran(0,cywakioi.size()-1)]]=card("һ��ͬ��",2,13);
	}
	if(t.effect==15)
		twelveam=min(twelveam+1,10);
	if(t.effect==16)
	{
		tim++;
		if(tim==5) tim=1;
		timrate=0;
	}
	if(t.effect==17)
	{
		tim=ran(1,4);
		timrate=0;
	}
	if(t.effect==18)
	{
		if(handcard1.size()>handcard2.size())
		{
			int pp=ran(1,handcard1.size());
			if(turn==1) send_a_card(thethrowcard(handcard1[pp-1]));
			throwcard(&handcard1,pp);
		}
		else if(handcard2.size()>handcard1.size())
		{
			int pp=ran(1,handcard2.size());
			if(turn==2) send_a_card(thethrowcard(handcard2[pp-1]));
			throwcard(&handcard2,pp);
		}
	} 
	if(t.effect==19)
	{
		if(handcard1.size()>handcard2.size())
		{
			if(turn==1) addhandcard(&handcard1,drawcard(),&handcardmax1,&buffclear);
			else addhandcard(&handcard1,drawcard(),&handcardmax1,&buff2);
		}
		else if(handcard2.size()>handcard1.size()) 
		{
			if(turn==1) addhandcard(&handcard2,drawcard(),&handcardmax2,&buff1);
			else addhandcard(&handcard2,drawcard(),&handcardmax2,&buffclear);
		}
	}
	if(t.effect==20)
	{
		vector<int> cywakioi;cywakioi.clear();
		for(int i=0;i<(cardmine->size());i++)
			if(!found((*cardmine)[i].speffect,"���˵Ķ���"))
				cywakioi.push_back(i);
		if(cywakioi.size()) addfavour((*cardmine)[cywakioi[ran(0,cywakioi.size()-1)]],"���˵Ķ���");
	}
	if(t.effect==21)
	{
		vector<int> cywakioi;cywakioi.clear();
		for(int i=0;i<(cardmine->size());i++)
			if(!found((*cardmine)[i].speffect,"��ʿ�Ķ���"))
				cywakioi.push_back(i);
		if(cywakioi.size())
		{
			int cywaknoi=ran(0,cywakioi.size()-1);
			addfavour((*cardmine)[cywakioi[cywaknoi]],"��ʿ�Ķ���");
			cywakioi.erase(cywakioi.begin()+cywaknoi);
			if(cywakioi.size()) addfavour((*cardmine)[cywakioi[ran(0,cywakioi.size()-1)]],"��ʿ�Ķ���");
		}
	} 
	if(t.effect==22)
	{
		vector<int> cywakioi;cywakioi.clear();
		for(int i=0;i<(cardmine->size());i++)
			if(!found((*cardmine)[i].speffect,"��ʦ�Ķ���"))
				cywakioi.push_back(i);
		if(cywakioi.size())
		{
			int cywaknoi=ran(0,cywakioi.size()-1);
			addfavour((*cardmine)[cywakioi[cywaknoi]],"��ʦ�Ķ���");
			cywakioi.erase(cywakioi.begin()+cywaknoi);
			if(cywakioi.size()) addfavour((*cardmine)[cywakioi[ran(0,cywakioi.size()-1)]],"��ʦ�Ķ���");
		}
	} 
	if(t.effect==23)
	{
		vector<int> cywakioi;cywakioi.clear();
		for(int i=0;i<(cardmine->size());i++)
			if(!found((*cardmine)[i].speffect,"սʿ�Ķ���"))
				cywakioi.push_back(i);
		if(cywakioi.size()) addfavour((*cardmine)[cywakioi[ran(0,cywakioi.size()-1)]],"սʿ�Ķ���");
	}
	if(t.effect==24)
	{
		vector<int> cywakioi;cywakioi.clear();
		for(int i=0;i<(cardmine->size());i++)
			if(!found((*cardmine)[i].speffect,"�ؾ��Ķ���"))
				cywakioi.push_back(i);
		if(cywakioi.size())
		{
			int cywaknoi=ran(0,cywakioi.size()-1);
			addfavour((*cardmine)[cywakioi[cywaknoi]],"�ؾ��Ķ���");
			cywakioi.erase(cywakioi.begin()+cywaknoi);
			if(cywakioi.size()) addfavour((*cardmine)[cywakioi[ran(0,cywakioi.size()-1)]],"�ؾ��Ķ���");
		}
	}
	if(t.effect==25)
	{
		vector<int> cywakioi;cywakioi.clear();
		for(int i=0;i<(cardmine->size());i++)
			if(!found((*cardmine)[i].speffect,"��ħ�Ķ���"))
				cywakioi.push_back(i);
		if(cywakioi.size())
		{
			int cywaknoi=ran(0,cywakioi.size()-1);
			addfavour((*cardmine)[cywakioi[cywaknoi]],"��ħ�Ķ���");
			cywakioi.erase(cywakioi.begin()+cywaknoi);
			if(cywakioi.size()) addfavour((*cardmine)[cywakioi[ran(0,cywakioi.size()-1)]],"��ħ�Ķ���");
		}
	}
	if(t.effect==26)
	{
		vector<int> cywakioi;cywakioi.clear();
		for(int i=0;i<(cardmine->size());i++)
			if(!found((*cardmine)[i].speffect,"��ʦ�Ķ���"))
				cywakioi.push_back(i);
		if(cywakioi.size()) addfavour((*cardmine)[cywakioi[ran(0,cywakioi.size()-1)]],"��ʦ�Ķ���");
	}
	if(t.effect==27)
	{
		for(int i=0;i<(cardmine->size());i++)
			if(!foundfavour((*cardmine)[i]))
				addfavour((*cardmine)[i],"���˵Ķ���");
	}
	if(t.effect==28)
	{
		int s=ran(20,27);
		usecard(card(cardname[s],0,s),114514);
		moveto(0,1);print("��ʹ���ˡ�"+cardname[s]+"��");
	}
	if(t.effect==29)
	{
		if(prob==1)
		{
			addhandcard(cardhis,recardheap[recardheap.size()-1],handcardmaxhis,buffhis);
			recardheap.pop_back();
		}
		else
			increasemana(manamine,manamaxmine,-114514);
	}
	if(t.effect==30)
	{
		cardheap[0].cost+=2;
	}
	if(t.effect==31)
	{
		if(turn==1 and trunk2==100)
		{
			if(sekiroblood2==0 or bloodsure2==0)
			{
				if(server_mode<3)
				{
					send_string2("Win");
					send_int2(1);	
				}
				win_screen(1);	
			}
			else
			{
				bloodsure2=0;
				bloodsure1=1;
				sekiroblood2--;
				trunk2=0;
				trunk1-=20;
				if(trunk1<0) trunk1=0;
				send_a_shake();
				Shake(3,1);
			}	
		}
		if(turn==2 and trunk1==100)
		{
			if(sekiroblood1==0 or bloodsure1==0)
			{
				if(server_mode<3)
				{
					send_string2("Win");
					send_int2(2);	
				}
				win_screen(2);	
			}
			else
			{
				bloodsure1=0;
				bloodsure2=1;
				sekiroblood1--;
				trunk1=0;
				trunk2-=20;
				if(trunk2<0) trunk2=0;
				send_a_shake();
				Shake(3,1);
			}	
		}
	}
	if(t.effect==32)
	{
		if(turn==1) trunk1=max(trunk1-30,0);
		if(turn==2) trunk2=max(trunk2-30,0);
		int del=0;
		if(foundbuff(buffmine,"����")==-1)
		{
			buff s;s.set_up("����",0);
			buffmine->push_back(s);
			del=1;
		}
		(*buffmine)[foundbuff(buffmine,"����")].tim+=2+del;
	}
	if(t.effect==33)
	{
		int yjjakioi=handcard1.size()-handcard2.size();
		if(yjjakioi<0) yjjakioi=-yjjakioi;
		if(turn==1) trunk2=min(trunk2+6*yjjakioi,100);
		if(turn==2) trunk1=min(trunk1+6*yjjakioi,100);
	}
	if(t.effect==34)
	{
		if(turn==1) trunk2+=(100-trunk2)/2;
		if(turn==2) trunk1+=(100-trunk1)/2;
	}
	if(t.effect==35)
	{
		int del=0;
		if(foundbuff(buffhis,"����Ϊ��")==-1)
		{
			buff s;s.set_up("����Ϊ��",0);
			buffhis->push_back(s);
			del=1;
		}
		(*buffhis)[foundbuff(buffhis,"����Ϊ��")].tim+=1+del;
	}
	if(t.effect==36)
	{
		card s=drawcard();s.cost++;
		addhandcard(cardhis,s,handcardmaxhis,&buffclear);	
	}
	if(t.effect==37)
	{
		for(int i=0;i<(cardmine->size());i++)
		{
			if((*cardmine)[i].effect==33)
				(*cardmine)[i].cost++,(*cardmine)[i].effect=45,(*cardmine)[i].name=cardname[45];
			if((*cardmine)[i].effect==34)
				(*cardmine)[i].effect=39,(*cardmine)[i].name=cardname[39];
			if((*cardmine)[i].effect==36)
				(*cardmine)[i].effect=40,(*cardmine)[i].name=cardname[40];
			if((*cardmine)[i].effect==44)
				(*cardmine)[i].effect=38,(*cardmine)[i].name=cardname[38];
		}
	}
	if(t.effect==38)
	{
		int del=0;
		if(foundbuff(buffmine,"�ɶ�������")==-1)
		{
			buff s;s.set_up("�ɶ�������",0);
			buffmine->push_back(s);
		}
		(*buffmine)[foundbuff(buffmine,"�ɶ�������")].tim+=9;
	}
	if(t.effect==39)
	{
		if(turn==1) trunk2+=(100-trunk2)*2/3;
		if(turn==2) trunk1+=(100-trunk1)*2/3;
	}
	if(t.effect==40)
	{
		card s=drawcard();s.cost++;
		addhandcard(cardhis,s,handcardmaxhis,&buffclear);	
		addhandcard(cardhis,drawcard(),handcardmaxhis,&buffclear);	
	}
	if(t.effect==41)
	{
		if(foundbuff(buffhis,"�׵�")==-1)
		{
			buff s;s.set_up("�׵�",1);
			buffhis->push_back(s);
		}
	}
	if(t.effect==42)
	{
		if(foundbuff(buffmine,"�׵�")!=-1)
		{
			buffmine->erase(buffmine->begin()+(foundbuff(buffmine,"�׵�")));
			if(foundbuff(buffhis,"�׵�")==-1)
			{
				buff s;s.set_up("�׵�",1);
				buffhis->push_back(s);
			}
		}
	}
	if(t.effect==43)
	{
		addhandcard(cardhis,drawcard(),handcardmaxhis,buffhis);
		if(foundbuff(buffmine,"�׵�")!=-1)
		{
			buffmine->erase(buffmine->begin()+(foundbuff(buffmine,"�׵�")));
			if(foundbuff(buffhis,"�׵�")==-1)
			{
				buff s;s.set_up("�׵�",1);
				buffhis->push_back(s);
			}
		}
	}
	if(t.effect==44)
	{
		int del=0;
		if(foundbuff(buffmine,"�ɶɸ���")==-1)
		{
			buff s;s.set_up("�ɶɸ���",0);
			buffmine->push_back(s);
		}
		(*buffmine)[foundbuff(buffmine,"�ɶɸ���")].tim+=5;
	}
	if(t.effect==45)
	{
		int g=(cardmine->size())-(cardhis->size());
		if(g>0) REP(g) addhandcard(cardhis,drawcard(),handcardmaxhis,&buffclear);
	}
	if(t.effect==46)
	{
		if(turn==1) bloodsure1=1;
		if(turn==2) bloodsure2=1;
	}
	if(t.effect==47)
	{
		if(turn==1)
		{
			trunk1=max(0,trunk1-5);
			trunk2=min(100,trunk2+10);
		}
		if(turn==2)
		{
			trunk2=max(0,trunk2-5);
			trunk1=min(100,trunk1+10);
		}
	}
	if(t.effect==48)
	{
		if(turn==1)
		{
			trunk1=max(0,trunk1-10);
			trunk2=min(100,trunk2+15);
		}
		if(turn==2)
		{
			trunk2=max(0,trunk2-10);
			trunk1=min(100,trunk1+15);
		}
	}
	if(t.effect==49)
	{
		if(turn==1)
		{
			int g=max(50-mana2,0);
			trunk2=min(100,trunk2+g);	
		}
		if(turn==2)
		{
			int g=max(50-mana1,0);
			trunk1=min(100,trunk1+g);	
		}
		increasemana(manahis,manamaxhis,-50);
	}
	if(t.effect==50)
	{
		vector<buff> buffex1,buffex2;
		buffex1.clear();buffex2.clear();
		for(int i=0;i<buff1.size();i++)
			if(buff1[i].name!="����" and buff1[i].name!="��ŭ" and buff1[i].name!="��ʦ�Ķ���" and buff1[i].name!="��ħ�Ķ���")
			{
				buffex2.push_back(buff1[i]);
				buff1.erase(buff1.begin()+i);
				i--;
			}
		for(int i=0;i<buff2.size();i++)
			if(buff2[i].name!="����" and buff2[i].name!="��ŭ" and buff2[i].name!="��ʦ�Ķ���" and buff2[i].name!="��ħ�Ķ���")
			{
				buffex1.push_back(buff2[i]);
				buff2.erase(buff2.begin()+i);
				i--;
			}
		for(int i=0;i<buffex1.size();i++)
			buff1.push_back(buffex1[i]);
		for(int i=0;i<buffex2.size();i++)
			buff2.push_back(buffex2[i]);
	}
}
iv usemagic(skill t)
{
	if(t.effect!=24) send_a_skill(t);
	if(t.effect==1)
	{
		card a=drawcard();a.cost=0;
		addhandcard(cardmine,a,handcardmaxmine,&buffclear);
	}
	if(t.effect==2)
	{
		int pp=ran(1,cardmine->size());
		card a=(*cardmine)[pp-1];
		send_a_card(thethrowcard(a));
		throwcard(cardmine,pp);
		addhandcard(cardhis,a,handcardmaxhis,&buffclear);
	}
	if(t.effect==4)
	{
		vector<card> qwq;qwq.clear();
		int size1=handcard1.size(),size2=handcard2.size();
		for(int i=0;i<size1;i++)
			qwq.push_back(handcard1[i]);
		for(int i=0;i<size2;i++)
			qwq.push_back(handcard2[i]);
		handcard1.clear();handcard2.clear();
		random_shuffle(qwq.begin(),qwq.end());
		for(int i=0;i<size1;i++)
			handcard1.push_back(qwq[i]);
		for(int i=size1;i<qwq.size();i++)
			handcard2.push_back(qwq[i]);
	}
	if(t.effect==6)
		increasecost(costmine,costmaxmine,1);
	if(t.effect==9)
	{
		bool flagg=1;
		while(flagg)
		{
			flagg=0;
			for(int i=0;i<(cardmine->size());i++)
				if(found((*cardmine)[i].speffect,"�ӱߣ��ӱߣ��ӱߣ�"))
				{
					flagg=1;
					send_a_card(thethrowcard((*cardmine)[i]));
					throwcard(cardmine,i+1);
					break;
				}
		}
	}
	if(t.effect==12)
	{
		vector<int> ths1,ths2;
		ths1.clear();ths2.clear();
		int lly1=-1,lly2=15;
		for(int i=0;i<(cardmine->size());i++)
		{
			if((*cardmine)[i].cost>lly1)
			{
				lly1=(*cardmine)[i].cost;
				ths1.clear();
			}
			if((*cardmine)[i].cost==lly1) ths1.push_back(i);
		}
		for(int i=0;i<(cardhis->size());i++)
		{
			if((*cardhis)[i].cost<lly2)
			{
				lly2=(*cardhis)[i].cost;
				ths2.clear();
			}
			if((*cardhis)[i].cost==lly2) ths2.push_back(i);
		}
		swap((*cardmine)[ths1[ran(0,ths1.size()-1)]],(*cardhis)[ths2[ran(0,ths2.size()-1)]]);
	}
	if(t.effect==13)
	{
		int del=0;
		if(foundbuff(buffmine,"��ŭ")==-1)
		{
			buff s;s.set_up("��ŭ",0);
			buffmine->push_back(s);
			del=1;
		}
		(*buffmine)[foundbuff(buffmine,"��ŭ")].tim+=3+del;
	}
	if(t.effect==16)
	{
		if((*handcardmaxmine)>3)
		{
			if(cardmine->size()==*handcardmaxmine) throwcard(cardmine,*handcardmaxmine);
			(*handcardmaxmine)--;
		}
		else increasecost(costmine,costmaxmine,2);
	}
	if(t.effect==18)
	{
		(*cardhis)[ran(0,(cardhis->size())-1)].cost++;
	}
	if(t.effect==19)
	{
		if(foundbuff(buffmine,"����")==-1)
		{
			buff s;s.set_up("����",0);
			buffmine->push_back(s);
		}
		(*buffmine)[foundbuff(buffmine,"����")].tim++;
	}
	if(t.effect==21)
	{
		if(foundbuff(buffhis,"��˯")==-1)
		{
			buff s;s.set_up("��˯",1);
			buffhis->push_back(s);
		}
		(*buffhis)[foundbuff(buffhis,"��˯")].tim++;
	}
	if(t.effect==22)
		addhandcard(cardhis,card("��˯���",1,51),handcardmaxhis,buffhis);
	if(t.effect==24)
	{
		system("cls");
		proving=1;provemode=2;
		printground();moveto(12,11);cyan("��");
		proving=0;
		moveto(10,24);print("ѡ���ύ��α֤");
		card carddd[5]={card("qwq",0,0),card("qwq",0,0),card("qwq",0,0),card("qwq",0,0),card("qwq",0,0)};
		for(int i=1;i<=4;i++)
		{
			int s=ran(1,cardlong);
			while((15<=s and s<=17 and !thecardsyst[2]) or (20<=s and s<=28 and !thecardsyst[3]) or (((31<=s and s<=34) or (36<=s and s<=49)) and !thecardsyst[4]) or (((1<=s and s<=14) or (18<=s and s<=19) or (29<=s and s<=30) or s==35 or (50<=s and s<=51)) and !thecardsyst[1])) s=ran(1,cardlong);
			carddd[i]=card(cardname[s],normalcost[s],s);	
		}
		int CC=1;
		char c='T';
		int suuu=0;
		while(1)
		{
			for(int i=1;i<=4;i++)
			{
				moveto(6,11+i);printf("  ");
				moveto(8,11+i);print(change(i));
				moveto(12,11+i);if(carddd[i].cost<=*costmine)cyan(change(carddd[i].cost));else blue(change(carddd[i].cost));
				moveto(15,11+i);print("["+carddd[i].name+"]");
			}
			moveto(6,11+CC);
			if(suuu==1) print("��");
			else print("��");
			green(change(CC));
			moveto(12,11+CC);green(change(carddd[CC].cost));
			moveto(15,11+CC);green("["+carddd[CC].name+"]");
			c=getch();
			if(upc(c) or leftc(c)) CC--,suuu=0;
			if(downc(c) or downc(c)) CC++,suuu=0;
			if(CC==0) CC=4;
			if(CC==5) CC=1;
			if(usec(c)) suuu++;
			if(suuu==2)
			{
				send_string2("Prove");
				send_card(carddd[CC]);
				send_string2("F");
				moveto(10,24);print(string(100,' '));moveto(10,24);print("�ȴ��Է���Ӧ����");
				recv_situation();
				int k=recv_int2();
				moveto(10,27);print(string(100,' '));moveto(10,27);
				if(k==4) usecard(carddd[CC],114514);
				recheck();
				provemode=1;
				visskill[foundskill(simpleskillsmine,"֤��")-1]=1;
				system("cls");
				printground();
				if(k==3) print("�Է�������飬������Ч����δ����Ʋ��ܵ���һ���Ƶĳͷ�"),Shake(2,1);
				if(k==4) print("�Է�ѡ����ܣ��������Ĵ������"),Shake(2,1);
				send_a_situation();
				break;
			} 
		}
	}
}
iv drawturnstartcard()
{
	bool theflag=0;
	if((foundskill(skillsmine,"�����ֻ�") or foundskill(skillsmine,"�ӻ�")) and cardmine->size()==*handcardmaxmine) theflag=1;
	if(!foundskill(skillsmine,"���")) addhandcard(cardmine,drawcard(),handcardmaxmine,&buffclear);
	if(foundskill(skillsmine,"�ӻ�") and !theflag and (*cardmine)[(cardmine->size())-1].cost>3)
	{
		send_a_skill(theskill[17]);
		send_a_card(thethrowcard((*cardmine)[(cardmine->size())-1]));
		throwcard(cardmine,cardmine->size());
	}
	if(foundskill(skillsmine,"�����ֻ�") and !theflag)
		while((*cardmine)[(cardmine->size())-1].cost%2==0)
		{
			throwcard(cardmine,cardmine->size());
			addhandcard(cardmine,drawcard(),handcardmaxmine,&buffclear);
		}
	if(foundskill(skillsmine,"���"))
	{
		send_a_skill(theskill[20]);
		addhandcard(cardhis,drawcard(),handcardmaxhis,buffhis);
		int cnakioi=ran(1,cardhis->size());
		addhandcard(cardmine,(*cardhis)[cnakioi-1],handcardmaxmine,buffmine);
		throwcard(cardhis,cnakioi);
		recardheap.pop_back();
	} 
}
iv beginning()
{
	if(gamemode==3)
	{
		if(turn==1) trunk1-=20*(handcardmax1-handcard1.size())/(handcardmax1);
		if(turn==2) trunk2-=20*(handcardmax2-handcard2.size())/(handcardmax2);
		if(trunk1<0) trunk1=0;
		if(trunk2<0) trunk2=0;
	}
	for(int i=0;i<(buffmine->size());i++)
		if((*buffmine)[i].name!="����" and (*buffmine)[i].name!="�׵�" and (*buffmine)[i].name!="�ɶɸ���" and (*buffmine)[i].name!="�ɶ�������") (*buffmine)[i].tim--;
	for(int i=0;i<(buffmine->size());i++)
		if((*buffmine)[i].tim==0)
		{
			buffmine->erase(buffmine->begin()+i);
			i--;
		}
	int ddd=0;
	if(foundskill(skillsmine,"��������")) ddd=ran(1,3)-2;
	increasecost(costmine,costmaxmine,2+ddd);
	if(foundbuff(buffmine,"�־�")!=-1)
		 increasecost(costmine,costmaxmine,1);
	increasemana(manamine,manamaxmine,10);
	drawturnstartcard();
	if(tim==3) 
		drawturnstartcard();
	if(foundskill(skillsmine,"���ȶ�����"))
	{
		increasecost(costmine,costmaxmine,1);
		drawturnstartcard();
	}
	if(foundskill(skillsmine,"����l������r"))
	{
		if(ran(1,10)<=6)
		{
			vector<int> ee;ee.clear();
			for(int i=0;i<(cardmine->size());i++)
				if(!found((*cardmine)[i].speffect,"�ӱߣ��ӱߣ��ӱߣ�"))
					ee.push_back(i);
			if(ee.size())
			{
				send_a_skill(theskill[7]);
				(*cardmine)[ee[ran(0,ee.size()-1)]].speffect.push_back("�ӱߣ��ӱߣ��ӱߣ�");	
			}
		}
		bool eee=1;
		for(int i=0;i<(cardmine->size());i++)
			if(found((*cardmine)[i].speffect,"�ӱߣ��ӱߣ��ӱߣ�"))
			{
				eee=0;
				break;
			}
		if(eee)
		{
			send_a_skill(theskill[8]); 
			increasecost(costmine,costmaxmine,1);
		}
	}
	if(tim==1) increasecost(costmine,costmaxmine,1);
	int fashi=0;
	for(int i=0;i<(cardmine->size());i++)
		if(found((*cardmine)[i].speffect,"��ʦ�Ķ���"))
			fashi++;
	if(ran(1,10)<=fashi)
	{
		increasecost(costmine,costmaxmine,1);
		buff s;s.set_up("��ʦ�Ķ���",1);
		buffmine->push_back(s);
	}
	int emo=0;
	for(int i=0;i<(cardmine->size());i++)
		if(found((*cardmine)[i].speffect,"��ħ�Ķ���"))
			emo++;
	if(ran(1,10)<=emo)
	{
		int fff=ran(1,cardmine->size());
		card fff2=(*cardmine)[fff-1];
		throwcard(cardmine,fff);
		buff s;s.set_up("��ħ�Ķ���",1);
		buffmine->push_back(s);
		fff2.speffect.push_back("��ħ�Ķ���2");
		send_a_card(thethrowcard(fff2));
	}
	if(gamemode==2)
		drawturnstartcard();
}
iv ending()
{
	int ths_tea=0;
	for(int i=0;i<(cardmine->size());i++)
		if((*cardmine)[i].effect==51) 
			ths_tea++;
	if(ths_tea>1) addhandcard(cardmine,drawcard(),handcardmaxmine,&buffclear);
	for(int i=0;i<(skillsmine->size());i++)
		if(!((*skillsmine)[i].active))
		{
			if((*skillsmine)[i].effect==3)
			{
				int costm=-1,pos=0,ss=0;
				for(int j=0;j<(cardmine->size());j++)
				{
					if((*cardmine)[j].cost>costm)
					{
						costm=(*cardmine)[j].cost;
						pos=j+1;
						ss=1;
					}
					else if((*cardmine)[j].cost==costm)
						ss++;
				}
				if(ss==1)
				{
					send_a_skill((*skillsmine)[i]);
					send_a_card(thethrowcard((*cardmine)[pos-1]));
					throwcard(cardmine,pos);
				}
			}
		}
	if(foundbuff(buffmine,"�׵�")!=-1)
	{
		buffmine->erase(buffmine->begin()+foundbuff(buffmine,"�׵�"));
		REP(2) addhandcard(cardmine,drawcard(),handcardmaxmine,&buffclear);
	}
	if(gamemode==3 and cardmine->size()==(*handcardmaxmine))
	{
		if(turn==1) trunk1+=10;
		if(turn==2) trunk2+=10;
	}
}
iv recheck()
{
	//����
	while(1)
	{
		bool flagk=0;
		for(int i=0;i<(cardmine->size());i++)
			if(found((*cardmine)[i].speffect,"���˵Ķ���"))
			{
				flagk=1;
				break;	
			}
		if(!flagk) break;
		int langren=0;
		for(int i=0;i<(cardmine->size());i++)
			if(foundfavour((*cardmine)[i]))
				langren++;
		if(langren>3)
			for(int i=0;i<(cardmine->size());i++)
			{
				if(found((*cardmine)[i].speffect,"���˵Ķ���"))
				{
					throwcard(cardmine,i+1);
					break;
				}
			}	
		else break;
	}
	//��ʦ 
	bool flagm=0;
	for(int i=0;i<(cardmine->size());i++)
		if(!found((*cardmine)[i].speffect,"��ʦ�Ķ���"))
		{
			flagm=1;
			break;
		}
	if(!flagm)
	{
		cardmine->clear();
		win();
	}
}
iv game()
{
	if(turn==server_mode or server_mode==3)
	{
		if(gamemode==2)
		{
			clocksum++;
			if(clocksum==3) clocksum=1,clocks++;
			if(clocks==20)
			{
				if(handcard1.size()==handcard2.size())
				{
					handcard1.clear();
					handcard2.clear();
				}
				else if(handcard1.size()<handcard2.size())
					handcard1.clear();
				else
					handcard2.clear();
				win();
			}
		}
		if(turn==1)
		{
			cardmine=&handcard1;costmine=&cost1;costmaxmine=&costmax1;
			cardhis=&handcard2;costhis=&cost2;costmaxhis=&costmax2;
			manamine=&mana1;manamaxmine=&manamax1;
			manahis=&mana2;manamaxhis=&manamax2;
			skillsmine=&skills1,simpleskillsmine=&simpleskills1;
			handcardmaxmine=&handcardmax1,handcardmaxhis=&handcardmax2; 
			soulmine=&soul1,soulhis=&soul2;
			buffmine=&buff1,buffhis=&buff2;
		}
		else
		{
			cardmine=&handcard2;costmine=&cost2;costmaxmine=&costmax2;
			cardhis=&handcard1;costhis=&cost1;costmaxhis=&costmax1;	
			manamine=&mana2;manamaxmine=&manamax2;
			manahis=&mana1;manamaxhis=&manamax1;
			skillsmine=&skills2,simpleskillsmine=&simpleskills2;
			handcardmaxmine=&handcardmax2,handcardmaxhis=&handcardmax1; 
			soulmine=&soul2,soulhis=&soul1;
			buffmine=&buff2,buffhis=&buff1;
		}
		beginning();
		sure_to_use=0;sure_to_magic=0;sure_to_end=0;
		handkind=1;
		memset(visskill,0,sizeof(visskill));
		system("cls");
		char c='T';
		Choose=1;
		printground();
		send_a_situation();
		int lastchoose=1,prisonsum=0;
		while(1)
		{
			choosechanged(lastchoose,Choose);
			lastchoose=Choose;
			c=getch();
			moveto(0,1);print(string(24,' '));
			if(handkind==1)
			{
				if(sure_to_end==1 or sure_to_magic==1) moveto(10,27),print(string(18,' '));
				if(upc(c)) Choose--,sure_to_use=0,sure_to_magic=0,sure_to_end=0;
				if(downc(c)) Choose++,sure_to_use=0,sure_to_magic=0,sure_to_end=0;
				if(gamemode!=4)
				{
					if(leftc(c)) Choose--,sure_to_use=0,sure_to_magic=0,sure_to_end=0;
					if(rightc(c)) Choose++,sure_to_use=0,sure_to_magic=0,sure_to_end=0;	
				}
				else if((leftc(c) or rightc(c)) and !visskill[foundskill(simpleskillsmine,"֤��")-1]) provemode=3-provemode,printground();
				if(Choose==0) Choose=cardmine->size();
				if(Choose==(cardmine->size())+1) Choose=1;
				if(usec(c)) sure_to_use++,sure_to_magic=0,sure_to_end=0;
				if(surec(c)) sure_to_end++,sure_to_magic=0,sure_to_use=0;
				if(magicc(c)) sure_to_magic++,sure_to_use=0,sure_to_end=0;
				if(sure_to_use==2)
				{
					if(provemode==1)
					{
						moveto(0,1);
						if((*cardmine)[Choose-1].cost>*costmine) print("���ò����޷�ʹ�ô��ƣ�");
						else if(prisonsum>=2) print("���ܵ�������Ϊ�Ρ�Ч����");
						else
						{
							print(string(24,' '));
							*costmine-=(*cardmine)[Choose-1].cost;
							usecard((*cardmine)[Choose-1],Choose);
							if(tim==2)
								if(ran(1,10)<=twelveam)
									increasecost(costmine,costmaxmine,1);
							recheck();
							if(Choose>=(cardmine->size())) Choose=cardmine->size();
							lastchoose=Choose;
							printground();
							send_a_situation();
							if(foundbuff(buffmine,"����Ϊ��")!=-1) prisonsum++;
							if(foundbuff(buffmine,"��˯")!=-1 and ran(1,20)<=7) 
								break;
						}	
					}
					else
					{
						moveto(0,1);
						if((*cardmine)[Choose-1].cost>*costmine) print("���ò����޷�ʹ�ô��ƣ�");
						else
						{
							send_string2("Prove");
							send_card((*cardmine)[Choose-1]);
							send_string2("T");
							moveto(10,24);print(string(100,' '));moveto(10,24);print("�ȴ��Է���Ӧ����");
							recv_situation();
							moveto(10,27);print(string(100,' '));moveto(10,27); 
							int k=recv_int2();
							if(k==1) print("�Է�������飬����ʧЧ���Է��ܵ���һ���Ƶĳͷ�"),Shake(2,1);
							if(k==2) print("�Է�ѡ�����");
							moveto(0,1);print(string(24,' '));
							*costmine-=(*cardmine)[Choose-1].cost;
							usecard((*cardmine)[Choose-1],Choose);
							recheck();
							if(Choose>=(cardmine->size())) Choose=cardmine->size();
							lastchoose=Choose;
							provemode=1;
							printground();
							send_a_situation();
							visskill[foundskill(simpleskillsmine,"֤��")-1]=1;
						}
					}
					sure_to_use=0;
				}
				if(sure_to_magic==1)
				{
					moveto(10,27);
					print("ȷ��Ҫ�л�ģʽ��"+string(60,' '));
				}
				if(sure_to_magic==2)
				{
					handkind=2;
					lastchoose=Choose=1;
					sure_to_magic=0;
					system("cls");
					printground(); 
				}
				if(sure_to_end==1)
				{
					moveto(10,27);
					print("ȷ��Ҫ�����غ���"+string(60,' '));
				}
				if(sure_to_end==2)
					break;	
			}
			else if(handkind==2)
			{
				if(sure_to_end==1 or sure_to_magic==1) moveto(10,27),print(string(18,' '));
				if(upc(c) or leftc(c)) Choose--,sure_to_use=0,sure_to_magic=0,sure_to_end=0;
				if(downc(c) or rightc(c)) Choose++,sure_to_use=0,sure_to_magic=0,sure_to_end=0;
				if(Choose==0) Choose=simpleskillsmine->size();
				if(Choose==(simpleskillsmine->size())+1) Choose=1;
				if(usec(c)) sure_to_use++,sure_to_magic=0,sure_to_end=0;
				if(surec(c)) sure_to_end++,sure_to_magic=0,sure_to_use=0;
				if(magicc(c)) sure_to_magic++,sure_to_use=0,sure_to_end=0;
				if(sure_to_use==2)
				{
					moveto(0,1);
					if((*simpleskillsmine)[Choose-1].mana>*manamine) print("ħ�������޷�ʹ�øü��ܣ�");
					else if(visskill[Choose-1]) print("�˻غ��Ѿ�ʹ�ù��ü��ܣ�");
					else
					{
						print(string(24,' '));
						*manamine-=(*simpleskillsmine)[Choose-1].mana;
						usemagic((*simpleskillsmine)[Choose-1]);
						if(foundbuff(buffmine,"����")!=-1)
						{
							if(ran(1,10)<=(*buffmine)[foundbuff(buffmine,"����")].tim)
							{
								*manamine+=(*simpleskillsmine)[Choose-1].mana;
								skill g=theskill[19];g.mana=-1;
								send_a_skill(g);
							}
						}
						if((*simpleskillsmine)[Choose-1].name=="����") (*simpleskillsmine)[Choose-1].mana+=10;
						if((*simpleskillsmine)[Choose-1].name=="֤��") provemode=1;
						visskill[Choose-1]=1;	
						printground();
						send_a_situation();
					}
					sure_to_use=0;
				}
				if(sure_to_magic==1)
				{
					moveto(10,27);
					print("ȷ��Ҫ�л�ģʽ��"+string(60,' '));
				}
				if(sure_to_magic==2)
				{
					handkind=1;
					lastchoose=Choose=1;
					sure_to_magic=0;
					system("cls");
					printground(); 
				}
				if(sure_to_end==1)
				{
					moveto(10,27);
					print("ȷ��Ҫ�����غ���"+string(60,' '));
				}
				if(sure_to_end==2)
					break;	
			}
		}
		ending();
		if(timemode)
		{
			if(ran(1,10)<=timrate)
			{
				tim++;
				if(tim==5) tim=1;
				timrate=0;
			}
			else timrate=min(timrate+1,10);
		}
		send_a_situation();
		if(server_mode<3) 
		{
			send_string2("End");
			moveto(10,23);print(string(60,' '));
			moveto(10,24);print(string(100,' '));
			moveto(10,25);print(string(80,' '));
			moveto(10,26);print(string(80,' '));
			moveto(10,24);print("��Ļغϼ�����������");
			Sleep(500);
			while(_kbhit()) getch();
		}	
	}
	else
	{
		system("cls");
		cardsum=skillsum=0;
		while(1)
		{
			printground();
			UI_other();
			string whatt=recv_string2();
			if(whatt=="Card")
			{
				card g=recv_card();
				othercardlist[++cardsum]=g;
				otherlist[cardsum+skillsum]=1;	
			}
			if(whatt=="Skill")
			{
				skill g=recv_skill();
				otherskilllist[++skillsum]=g;
				otherlist[cardsum+skillsum]=2;
			}
			if(whatt=="Situation")
				recv_situation();
			if(whatt=="Win")
			{
				system("cls");
				int g=recv_int2();
				win_screen(g);
			}
			if(whatt=="Shake")
				Shake(5,1);
			if(whatt=="End")
			{
				moveto(10,23);print(string(60,' '));
				moveto(10,24);print(string(100,' '));
				moveto(10,25);print(string(60,' '));
				moveto(10,26);print(string(60,' '));
				moveto(10,24);print("�����ֵ���Ļغϡ���");
				Sleep(500);
				while(_kbhit()) getch();
				break;	
			}		
			if(whatt=="Prove")
			{
				otherskilllist[++skillsum]=theskill[24];
				otherlist[cardsum+skillsum]=2;
				UI_other();
				card g=recv_card();
				string TF=recv_string2();
				moveto(10,23);print(string(60,' '));
				moveto(10,24);print(string(100,' '));
				moveto(10,25);print(string(60,' '));
				moveto(10,26);print(string(60,' '));
				moveto(10,24);print("�Է��ύ֤��"+change(g.cost)+"����"+g.name+"��"+"�� z ������飬�� x ����");
				char c=getch();
				while(c!='z' and c!='x') c=getch();
				moveto(10,27);print(string(100,' '));moveto(10,27);
				if(TF=="T" and c=='z')
				{
					print("�Է����������ʵ��֤�����ʧЧ�����ܵ���һ���Ƶĳͷ�"),Shake(2,1);
					if(turn==2) addhandcard(&handcard1,drawcard(),&handcardmax1,&buff1);
					if(turn==1) addhandcard(&handcard2,drawcard(),&handcardmax2,&buff2);
				}
				if(TF=="T" and c=='x')
					print("�Է����������ʵ��֤��");
				if(TF=="F" and c=='z')
				{
					print("�Է����������ٵ�֤�������Ч���Է�δ����Ʋ��ܵ���һ���Ƶĳͷ�"),Shake(2,1);
					if(turn==1) addhandcard(&handcard1,drawcard(),&handcardmax1,&buff1);
					if(turn==2) addhandcard(&handcard2,drawcard(),&handcardmax2,&buff2);
				}
				if(TF=="F" and c=='x')
					print("�Է����������ٵ�֤�δ���ķ��ô��"),Shake(2,1);
				send_situation();
				if(TF=="T" and c=='z') send_int2(1);
				if(TF=="T" and c=='x') send_int2(2);
				if(TF=="F" and c=='z') send_int2(3);
				if(TF=="F" and c=='x') send_int2(4);
			}
		}
	}
	turn=3-turn;
	game();
}
iv showskill()
{
	system("cls");
	print("P1 "+soul1+"\n");
	for(int j=0;j<skills1.size();j++)
	{
		string activeword="";
		if(skills1[j].active) activeword="("+change(skills1[j].mana)+"��)";
		print(change(j+1)+".["+skills1[j].name+"]"+skillexplanation[skills1[j].effect]+activeword+"\n");
	}
	print("\n\n");
	print("P2 "+soul2+"\n");
	for(int j=0;j<skills2.size();j++)
	{
		string activeword="";
		if(skills2[j].active) activeword="("+change(skills2[j].mana)+"��)";
		print(change(j+1)+".["+skills2[j].name+"]"+skillexplanation[skills2[j].effect]+activeword+"\n");
	}
	Sleep(3000);
}
int zhu,bei,zhu_bei;
iv choosesoul()
{
	vector<skill> *skills,*simpleskills;
	string *thesoul;
	int ser3=1,sm;
	server3:
	if(server_mode<3) sm=server_mode;
	else sm=ser3;
	if(sm==1) skills=&skills1,simpleskills=&simpleskills1,thesoul=&soul1;
	if(sm==2) skills=&skills2,simpleskills=&simpleskills2,thesoul=&soul2;
	//qwq
	system("cls");
	print("        ѡ��P"+change(sm)+"��������ʣ�");
	char c='T';
	int choose=1,sure_to_choose=0;
	zhu=1,bei=1,zhu_bei=1;
	while(1)
	{
		for(int j=1;j<=soullong;j++)
		{
			moveto(4,j),print("  ");
			if(j<10) print("0");
			print(change(j)+" "+soullist[j]+" | "+soulexplanation[j]+"           ");
		}
		if(choose==soullong-1)
		{
			moveto(70,zhu);red("��");
			moveto(74,bei);blue("��");
		}
		//qwq
		moveto(4,choose);
		if(sure_to_choose==0) print("��");
		if(sure_to_choose==1) print("��"); 
		if(choose<10) green("0");
		green(change(choose)+" "+soullist[choose]+" | "+soulexplanation[choose]);
		//qwq	
		moveto(0,13);REP(5) print(string(120,' ')+"\n");moveto(0,13); 
		if(choose==soullong-1)
		{
			int tot=0;
			for(int j=0;j<soulskill[zhu].size();j++)
				if(soulskill[zhu][j].active) 
					print(change(++tot)+".["+soulskill[zhu][j].name+"]"+skillexplanation[soulskill[zhu][j].effect]+"("+change(soulskill[zhu][j].mana)+"��)\n");
			for(int j=0;j<soulskill[bei].size();j++)
				if(!soulskill[bei][j].active) 
					print(change(++tot)+".["+soulskill[bei][j].name+"]"+skillexplanation[soulskill[bei][j].effect]+"\n");
		}
		else
			for(int j=0;j<soulskill[choose].size();j++)
			{
				string activeword="";
				if(soulskill[choose][j].active) activeword="("+change(soulskill[choose][j].mana)+"��)";
				print(change(j+1)+".["+soulskill[choose][j].name+"]"+skillexplanation[soulskill[choose][j].effect]+activeword+"\n");
			}
		//qwq	
		c=getch();
		if(c=='W' or c=='w' or c=='A' or c=='a') choose--,sure_to_choose=0;
		if(c=='S' or c=='s' or c=='D' or c=='d') choose++,sure_to_choose=0;
		if(choose==soullong-1)
		{
			if(c==LEFT or c==RIGHT) zhu_bei=3-zhu_bei;
			if(zhu_bei==1)
			{
				if(c==UP)
				{
					zhu--;
					if(zhu==soullong-1) zhu--;
					if(zhu==0) zhu=soullong;
				}
				if(c==DOWN)
				{
					zhu++;
					if(zhu==soullong-1) zhu++;
					if(zhu==soullong+1) zhu=1;
				}
			} 
			else
			{
				if(c==UP)
				{
					bei--;
					if(bei==soullong-1) bei--;
					if(bei==0) bei=soullong;
				}
				if(c==DOWN)
				{
					bei++;
					if(bei==soullong-1) bei++;
					if(bei==soullong+1) bei=1;
				}
			}
		}
		if(usec(c) or surec(c)) sure_to_choose++;
		if('1'<=c and c<='9') choose=c-'0';
		if(c=='0') choose=10;
		if(sure_to_choose==2)
			break;
		if(choose==soullong+1) choose=1;
		if(choose==0) choose=soullong;
	}
	if(choose==soullong-1)
	{
		*thesoul=soullist[choose];
		if(G)
		{
			for(int i=1;i<=soullong-2;i++)
				for(int j=0;j<soulskill[i].size();j++)
				{
					skills->push_back(soulskill[i][j]);
					if(soulskill[i][j].active)simpleskills->push_back(soulskill[i][j]);
				}
		}
		else
		{
			if(zhu==soullong) zhu=ran(1,soullong-2);
			if(bei==soullong) bei=ran(1,soullong-2);
			for(int j=0;j<soulskill[zhu].size();j++)
				if(soulskill[zhu][j].active)
					skills->push_back(soulskill[zhu][j]),simpleskills->push_back(soulskill[zhu][j]);
			for(int j=0;j<soulskill[bei].size();j++)
				if(!soulskill[bei][j].active)
					skills->push_back(soulskill[bei][j]);	
		}
	}
	else
	{
		if(choose==soullong) choose=ran(1,soullong-2);
		*thesoul=soullist[choose];
		for(int j=0;j<soulskill[choose].size();j++)
			skills->push_back(soulskill[choose][j]);
		for(int j=0;j<(skills->size());j++)
			if((*skills)[j].active)
				simpleskills->push_back((*skills)[j]);	
	}
	if(gamemode==4) skills->push_back(theskill[24]),simpleskills->push_back(theskill[24]);
	if(server_mode<3)
	{
		for(int j=1;j<=soullong;j++)
		{
			moveto(4,j),print("  ");
			if(j<10) print("0");
			print(change(j)+" "+soullist[j]+" | "+soulexplanation[j]+"           ");
		}
		moveto(0,18);print("��ѡ����"+(*thesoul));	
	}
	else
	{
		if(ser3==1)
		{
			ser3=2;
			goto server3;
		}
	}
	if(server_mode==2)
	{
		send_string2(soul2);
		send_vector_skill(skills2);
		send_vector_skill(simpleskills2);
	}
	if(server_mode==1)
	{
		soul2=recv_string2();
		skills2=recv_vector_skill();
		simpleskills2=recv_vector_skill();
	}
}
iv option()
{
	system("cls");
	cyan("��Ϸ����");
	int choose=1;
	char c='T';
	while(1)
	{
		moveto(0,1);
		if(firsthand!=3)
			if(choose==1) green("> ������� P"+change(firsthand)+"  ");
			else red("  ������� P"+change(firsthand)+"  ");	
		else
			if(choose==1) green("> ������� ���");
			else red("  ������� ���");	
		moveto(0,2);
		if(choose==2)
			if(timemode) green("> ʱ��ϵͳ ��");
			else green("> ʱ��ϵͳ ��");
		else
			if(timemode) red("  ʱ��ϵͳ ��");
			else red("  ʱ��ϵͳ ��");
		moveto(0,3);print(string(26,' '));moveto(0,3);
		if(choose==3)
		{
			green("> ��Ϸģʽ "+gamemodename[gamemode]);
			moveto(10,24);print(string(50,' '));moveto(10,24);
			print(gamemodeexplanation[gamemode]);
		}
		else
		{
			red("  ��Ϸģʽ "+gamemodename[gamemode]);
			moveto(10,24);print(string(50,' '));
		}
		moveto(0,4);
		if(choose==4)
			green("> ����ϵͳ");
		else
			red("  ����ϵͳ");
		//qwq
		c=getch();
		if(upc(c) or leftc(c)) choose--;
		if(downc(c) or rightc(c)) choose++;
		if(usec(c))
		{
			if(choose==1) firsthand++;
			if(choose==2) 
			{
				timemode=1-timemode;
				thecardsyst[2]=timemode; 
			}
			if(choose==3)
			{
				gamemode++;
				thecardsyst[4]=int(gamemode==3);
			}
			if(choose==4)
			{
				cardsystem();
				system("cls");
				cyan("��Ϸ����");
			}
		}
		if(surec(c) or magicc(c))
			break;
		if(firsthand==4) firsthand=1;
		if(gamemode==gamemodelong+1) gamemode=1;
		if(choose==5) choose=1;
		if(choose==0) choose=4;
	}
	title();
}
iv cardsystem()
{
	system("cls");
	cyan("����ϵͳ");
	char c='T';
	int choose=1;
	while(1)
	{
		moveto(0,1);
		for(int i=1;i<=cardsystlong;i++)
		{
			red("  "+cardsyst[i]+" ");
			if(thecardsyst[i]) red("��\n");
			else red("��\n");
		}
		moveto(0,choose);
		green("> "+cardsyst[choose]+" ");
		if(thecardsyst[choose]) green("��\n");
			else green("��\n");
		moveto(10,24);print(string(50,' '));
		moveto(10,24);print(cardsystexplanation[choose]);
		char c=getch();
		moveto(10,25);print(string(50,' '));
		if(upc(c) or leftc(c)) choose--;
		if(downc(c) or rightc(c)) choose++;
		if(usec(c))
		{
			if(choose==1)
				thecardsyst[1]=1-thecardsyst[1];
			if(choose==2)
				if(timemode) thecardsyst[2]=1-thecardsyst[2];
			if(choose==3)
				thecardsyst[3]=1-thecardsyst[3];
			if(choose==4)
				if(gamemode==3) thecardsyst[4]=1-thecardsyst[4];
		}
		if(surec(c) or magicc(c)) 
		{
			if(!(thecardsyst[1] or thecardsyst[2] or thecardsyst[3] or thecardsyst[4]))
				moveto(10,25),print("�����Ҫ��������һ������");
			else break;
		}
		if(choose==0) choose=cardsystlong;
		if(choose==cardsystlong+1) choose=1; 
	}
}
iv title()
{
	system("cls");
	cyan("ANOTHER-CARD-GAME\n");
	char c='T';
	int choose=1;
	while(!(usec(c) or surec(c)))
	{
		moveto(0,1);
		red("  ��ʼ��Ϸ\n  ��Ϸ����\n  ��ʱ���´���");
		moveto(0,choose);
		if(choose==1) green("> ��ʼ��Ϸ");
		if(choose==2) green("> ��Ϸ����");
		if(choose==3) green("> ��ʱ���´���");
		c=getch();
		if(upc(c) or leftc(c)) choose--;
		if(downc(c) or rightc(c)) choose++;
		if(choose==0) choose=3;
		if(choose==4) choose=1;
	}
	if(choose==1)
	{
		if(gamemode==3)
		{
			system("cls");
			wolf();
			char c='T';
			while(!surec(c)) c=getch();
		}
		init_server();
		if(server_mode==1)
		{
			string version2=recv_string2();
			if(version!=version2)
			{
				send_int2(-1);
				win_screen(4);
			}
			send_int2(0);
			send_int2(timemode);
			send_int2(gamemode);
			for(int i=1;i<=cardsystlong;i++)
				send_int2(int(thecardsyst[i]));
		}
		if(server_mode==2)
		{
			send_string2(version);
			if(recv_int2()==-1)
				win_screen(4);
			timemode=recv_int2();
			gamemode=recv_int2();
			for(int i=1;i<=cardsystlong;i++)
				thecardsyst[i]=bool(recv_int2());
		}
	}
	if(choose==2) option();
	if(choose==3) update_code();
}
iv init_server()
{
	server_mode=1;
	bool connect_established=false;
	while(!connect_established)
	{
		connect_established=1;
		system("cls");
		cyan("ѡ���ս\n");
		char c='T';
		while(!(usec(c) or surec(c)))
		{
			moveto(0,1);
			red("  ���������\n  ����������Ϸ\n  ���ض�ս");
			moveto(0,server_mode);
			if(server_mode==1) green("> ���������");
			if(server_mode==2) green("> ����������Ϸ");
			if(server_mode==3) green("> ���ض�ս");
			c=getch();
			if(upc(c) or leftc(c)) server_mode--;
			if(downc(c) or rightc(c)) server_mode++;
			if(server_mode==0) server_mode=3;
			if(server_mode==4) server_mode=1;
			if(magicc(c))
			{
				title();
				return;
			} 
		}
		if(server_mode==3) break;
		moveto(0,4);
		WSAstart();
		if(server_mode==1)
		{
			system("cls");
			char hostname[256]={0},ip[256]={0};
			gethostname(hostname,sizeof(hostname));
			HOSTENT* host=gethostbyname(hostname);
			strcpy(ip,inet_ntoa(*(in_addr*)*host->h_addr_list));
			printf("���ip��ַ��:%s\n\n�ȴ��������...",ip);   
		}
		if(server_mode==2)
			printf("input ip:");
		if(TCP_initialize()!=0)
		{
			connect_established=0;
			system("cls");
			if(server_mode==1)
			{
				print("�޷����������...�����Ƿ���ͬһ�����������л����Ժ�����...\n");
				getch();
			}
			else
			{
				print("�޷�������������...��������״�����������Ƿ���������...\n");
				getch();
			}
		}	
	}
}
iv update_code()
{
	server_mode=1;
	bool connect_established=false;
	while(!connect_established)
	{
		connect_established=1;
		system("cls");
		cyan("��ʱ���´���\n");
		char c='T';
		while(!(usec(c) or surec(c)))
		{
			moveto(0,1);
			red("  ���������\n  ���ӷ����");
			moveto(0,server_mode);
			if(server_mode==1) green("> ���������");
			if(server_mode==2) green("> ���ӷ����");
			c=getch();
			if(upc(c) or leftc(c)) server_mode--;
			if(downc(c) or rightc(c)) server_mode++;
			if(server_mode==0) server_mode=2;
			if(server_mode==3) server_mode=1;
			if(magicc(c))
			{
				title();
				return;
			} 
		}
		moveto(0,4);
		WSAstart();
		if(server_mode==1)
		{
			system("cls");
			char hostname[256]={0},ip[256]={0};
			gethostname(hostname,sizeof(hostname));
			HOSTENT* host=gethostbyname(hostname);
			strcpy(ip,inet_ntoa(*(in_addr*)*host->h_addr_list));
			printf("���ip��ַ��:%s\n\n�ȴ��������...",ip);   
		}
		if(server_mode==2)
			printf("input ip:");
		if(TCP_initialize()!=0)
		{
			connect_established=0;
			system("cls");
			if(server_mode==1)
			{
				print("�޷����������...�����Ƿ���ͬһ�����������л����Ժ�����...\n");
				getch();
			}
			else
			{
				print("�޷�������������...��������״�����������Ƿ���������...\n");
				getch();
			}
		}	
	}
	if(server_mode==1)
	{
		system("cls");
		red("��ȷ����� ANOTHER-CARD-GAME.cpp��PreInfo(ACG).hpp �� Socket(ACG).hpp ��ͬһ��Ŀ¼��\n��Y���������߹رտ�ִ���ļ�\n");
		char c=getch();
		while(c!='Y') c=getch();
		printf("�ѽ��У�");REP(10) print("��");
		string s;
		freopen("ANOTHER-CARD-GAME.cpp","r",stdin);
		int t=0,total=2315+425+309;
		while(1)
		{
			getline(cin,s);
			send_string2(s);
			int ggg=int(double(++t)/double(total))*100;
			if(ggg/10!=int(double(t-1)/double(total))*10)
			{
				moveto(8,2);
				REP(ggg/10) print("��");
			} 
			if(s.find("//Ϊ��ʱ���´��ݵ�ʵ������ɾ������")==0) break;
		}
		fclose(stdin);
		freopen("PreInfo(ACG).hpp","r",stdin);
		while(1)
		{
			getline(cin,s);
			send_string2(s);
			int ggg=int(double(++t)/double(total))*100;
			if(ggg/10!=int(double(t-1)/double(total))*10)
			{
				moveto(8,2);
				REP(ggg/10) print("��");
			} 
			if(s.find("//Ϊ��ʱ���´��ݵ�ʵ������ɾ������")==0) break;
		}
		fclose(stdin);
		freopen("Socket(ACG).hpp","r",stdin);
		while(1)
		{
			getline(cin,s);
			send_string2(s);
			int ggg=int(double(++t)/double(total))*100;
			if(ggg/10!=int(double(t-1)/double(total))*10)
			{
				moveto(8,2);
				REP(ggg/10) print("��");
			} 
			if(s.find("//Ϊ��ʱ���´��ݵ�ʵ������ɾ������")==0) break;
		}
		fclose(stdin);
		moveto(8,2);
		REP(10) print("��");
	}
	if(server_mode==2)
	{
		system("cls");
		printf("���ڸ��¡���");
		freopen("ANOTHER-CARD-GAME.cpp","w",stdout);
		while(1)
		{
			string s=recv_string2();
			cout<<s<<endl;
			if(s.find("//Ϊ��ʱ���´��ݵ�ʵ������ɾ������")==0) break;
		}
		fclose(stdout);
		freopen("PreInfo(ACG).hpp","w",stdout);
		while(1)
		{
			string s=recv_string2();
			cout<<s<<endl;
			if(s.find("//Ϊ��ʱ���´��ݵ�ʵ������ɾ������")==0) break;
		}
		fclose(stdout);
		freopen("Socket(ACG).hpp","w",stdout);
		while(1)
		{
			string s=recv_string2();
			cout<<s<<endl;
			if(s.find("//Ϊ��ʱ���´��ݵ�ʵ������ɾ������")==0) break;
		}
		fclose(stdout);
	}
	exit(0);
} 
iv init_restart()
{
	server_mode=0;
	handcard1.clear();
	handcard2.clear();
	cardheap.clear();
	recardheap.clear();
	skills1.clear();skills2.clear();simpleskills1.clear();simpleskills2.clear();
	buff1.clear();
	buff2.clear();
	clocks=clocksum=0;
	tim=0,twelveam=0,timrate=0;
}
iv maingame()
{
	init_restart();
	title();
	choosesoul();
	startgame();
	showskill();
	game();	
}
int main()
{
	system("mode con cols=130 lines=30");
	SetConsoleTitle("ANOTHER-CARD-GAME v2.0.4");
	init();
	maingame();
}
//����Ҫ�ڱ���ѡ������� -lwsock32 ���ܽ��б��� 
//Ϊ��ʱ���´��ݵ�ʵ������ɾ������ 