#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

const int defaultHp = 200;
const int defaultMp = 100;
const int defaultX = 1;
const int defaultY = 1;
const int defaultStrength = 20;
const int defaultExp = 0;
const int defaultLevel = 1;
const int defaultDex = 45;
const string weaponList[4] = {"NO_WEAPON","BASEBALL BAT","AXE","SWORD"};

char map[2][10][36] =
{
	{"00000000000000000000000000000000000",
	 "00011111111100001111100011111100000",
	 "01110000000101111000111110000211110",
	 "01011100001111001101100000111100010",
	 "01010011100000000110000001100000010",
	 "00011110000000001100110011000000010",
	 "00000010000000000110011001000000010",
	 "01111010000111111100001101111111010",
	 "01001111110000100000000111110001110",
	 "03000000000000111111111100000000000"}
	,
	{"00111000111111000000001111111100000",
	 "11101111100001111100111030000110000",
	 "00101000100011000111100010011110000",
	 "00101011100110000000111111111011110",
	 "11111110100011110000100000010000110",
	 "10000000100000010001100111110000010",
	 "10111120110000110000111100001111110",
	 "11100000011100001110000000011000000",
	 "10100111000111111011111111010000000",
	 "10111101111100000000000011110000000"}
};


char fighting[10][8][45]
{
	{"                                            ",
	 "                                            ",
	 "                                            ",
	 "  _|Y|_                                     ",
	 "  +*o*+                         ___         ",
	 "  (| |)                        |O_O|        ",
	 "   ^ ^                          mmmmmmmmmm  ",
	 "--------------------------------------------",
	}
	,
	{"                                            ",
	 "                                            ",
	 "                                            ",
	 "  _|Y|_                        ?????        ",
	 "  +*w*+                         ___         ",
	 "  (| |)          @@@>>>>       |>_<|        ",
	 "   ^ ^                          mmmmmmmmmm  ",
	 "--------------------------------------------",
	}
	,
	{"                                            ",
	 "  ?????                                     ",
	 "                                            ",
	 "  _|Y|_                                     ",
	 "  +>_<+                         ___         ",
	 "  (| |)          <<<<@@@       |OwO|        ",
	 "   ^ ^                          mmmmmmmmmm  ",
	 "--------------------------------------------",
	}
	,
	{"                                            ",
	 "                                            ",
	 "                                            ",
	 "  _|Y|_                       &?$%^$%#      ",
	 "  +*W*+                         ___         ",
	 "  (| |)          @@@>>>>       |8^8|        ",
	 "   ^ ^                          mmmmmmmmmm  ",
	 "--------------------------------------------",
	}
	,
	{"                                            ",
	 " *&$^#%@                                    ",
	 "                                            ",
	 "  _|Y|_                                     ",
	 "  +8^8+                         ___         ",
	 "  (| |)          <<<<@@@       |OWO|        ",
	 "   ^ ^                          mmmmmmmmmm  ",
	 "--------------------------------------------",
	}
	,
	{"                                            ",
	 "                                            ",
	 "                                            ",
	 "  _|Y|_                                     ",
	 "  +*o*+                         ___         ",
	 "  /| |D                        |O_O|        ",
	 "   ^ ^                          mmmmmmmmmm  ",
	 "--------------------------------------------",
	}
	,
	{"                                            ",
	 "                                            ",
	 "                                            ",
	 "  _|Y|_                        ?????        ",
	 "  +*w*+                         ___         ",
	 "  /| |D          @@@>>>>       |>_<|        ",
	 "   ^ ^                          mmmmmmmmmm  ",
	 "--------------------------------------------",
	}
	,
	{"                                            ",
	 "  ?????                                     ",
	 "                                            ",
	 "  _|Y|_                                     ",
	 "  +>_<+                         ___         ",
	 "  /| |D          <<<<@@@       |OwO|        ",
	 "   ^ ^                          mmmmmmmmmm  ",
	 "--------------------------------------------",
	}
	,
	{"                                            ",
	 "                                            ",
	 "                                            ",
	 "  _|Y|_                       &?$%^$%#      ",
	 "  +*W*+                         ___         ",
	 "  /| |D          @@@>>>>       |8^8|        ",
	 "   ^ ^                          mmmmmmmmmm  ",
	 "--------------------------------------------",
	}
	,
	{"                                            ",
	 " *&$^#%@                                    ",
	 "                                            ",
	 "  _|Y|_                                     ",
	 "  +8^8+                         ___         ",
	 "  /| |D          <<<<@@@       |OWO|        ",
	 "   ^ ^                          mmmmmmmmmm  ",
	 "--------------------------------------------",
	}
};



class Map
{
	public:
		Map() : mapName("new_Map"), No(-1){};
		Map(string name, int x){mapName = name; No = x;};
		~Map(){};
		string getMapName() {return mapName;}	
	private:
		string mapName;
		int No;
};

class Role
{
	public:
		Role(string, int);
		~Role(){};
		bool moveLeft();
		bool moveRight();
		bool moveDown();
		bool moveUp();
		//void transferMap(Map);
		//int getRoleX() {return x;}
		//int getRoleY() {return y;}
		void inistialize_position();
		void display();
		bool isDead(){return hp <= 0;};
		int getMapNo(){return MapNo;};
		void attack();
		void beAttacked();
		void recover();
		void levelUp();
		void raiseExp(int);
		int getDex(){return Dex;}
		void changeWeapon();
		void weaponEffect();
		void changeStrength(int);
		void changeDex(int);
		int getWeaponNum(){return weaponNum;}
	private:
		int x;
		int y;
		int hp;
		int mp;
		string roleName;
		int strength;
		int MapNo;
		int Level;  // ���ť���+20*����
		int Exp;
		int weaponNum;
		string Weapon;
		int Dex;
};

Role::Role(string name, int No) : roleName(name) , MapNo(No)
{
	hp = defaultHp;
	mp = defaultMp;
	strength = defaultStrength;
	Exp = defaultExp;
	Level = defaultLevel;
	Dex = defaultDex;
	weaponNum = 0;
	Weapon = weaponList[weaponNum];
}

bool Role::moveLeft()
{
	if( y == 0 || map[MapNo-1][x][y-1] == '0' ) return false; 
	else if(map[MapNo-1][x][y-1] == '1' || map[MapNo-1][x][y-1] == '3' ) { y--; return true; } 
	else if(map[MapNo-1][x][y-1] == '2') {MapNo = (MapNo*-1)+3; inistialize_position(); return true;}
}

bool Role::moveRight()
{
	if( y == 34 || map[MapNo-1][x][y+1] == '0' ) return false;
	else if(map[MapNo-1][x][y+1] == '1' || map[MapNo-1][x][y+1] == '3' ) { y++; return true; }
	else if(map[MapNo-1][x][y+1] == '2') {MapNo = (MapNo*-1)+3; inistialize_position(); return true;}
}

bool Role::moveDown()
{
	if( x == 9 || map[MapNo-1][x+1][y] == '0' ) return false;
	else if(map[MapNo-1][x+1][y] == '1' || map[MapNo-1][x+1][y] == '3' ) { x++; return true;}
	else if(map[MapNo-1][x+1][y] == '2') {MapNo = (MapNo*-1)+3; inistialize_position(); return true;}
}

bool Role::moveUp()
{
	if( x == 0 || map[MapNo-1][x-1][y] == '0' ) return false;
	else if(map[MapNo-1][x-1][y] == '1' || map[MapNo-1][x-1][y] == '3' ) { x--; return true;}
	else if(map[MapNo-1][x-1][y] == '2') {MapNo = (MapNo*-1)+3; inistialize_position(); return true;}
}


void Role::inistialize_position()
{
	for( int i = 0 ; i < 10 ; i++ )
		for( int j = 0 ; j < 35 ; j++ )
			if( map[MapNo-1][i][j] == '3' ){
				x = i; 
				y = j;
				break;
			}
}

void Role::display()
{
	cout << endl;
	for( int i = 0 ; i < 10 ; i++ )
	{
 		for( int j = 0 ; j < 35 ; j++ )
		{
			if     ( i == x && j == y) cout << "[]";
			else if( map[MapNo-1][i][j] == '0') cout << "##";
			else if( map[MapNo-1][i][j] == '1') cout << "  ";
			else if( map[MapNo-1][i][j] == '2') cout << "<>";
			else if( map[MapNo-1][i][j] == '3') cout << "  ";
		}
		cout << endl;
	}
	cout << roleName << " now is at Map" << MapNo << " (" << x << "," << y << ")" << endl << endl
	;
}

void Role::attack()
{
	cout << "You attack slime , cause " << strength << " demages!!    ";
}

void Role::beAttacked()
{
	hp -= 10;
	if(hp < 0) hp = 0;
	cout << "Your HP: " << hp << endl << endl;
}

void Role::recover()
{
	hp += rand()%80+51;
	cout << roleName << " recover , hp is " << hp << " now" << endl << endl;
}

void Role::raiseExp(int e)
{
	Exp += e/2;
	cout << "Your experience raises by " << e/2 << endl;
	cout << "Now your experience is " << Exp << endl;
}

void Role::levelUp()
{
	if(Exp >= 100*Level*Level)
	{
		Level++;
		cout << "Congratulations!!! Level-up!!! And now your level is " << Level << endl;
		weaponEffect();	// update the strength for level-up
	}
}

void Role::changeStrength(int effect)
{
	strength = defaultStrength + (Level-1)*5 + effect;
}

void Role::changeDex(int effect)
{
	Dex = defaultDex + (Level-1)*3 + effect;
}

void Role::changeWeapon()
{
	if(Level < 3)	// for Level 0, 1 or 2, no other weapon
	{
		cout << "You have no other weapon." << endl << endl;
	}
	else
	{
		(Level >= (weaponNum+1)*2+1) ? weaponNum++ : weaponNum = 0;
		Weapon = weaponList[weaponNum];
		cout << "You take " << Weapon << " as your weapon now" << endl;
		weaponEffect();
	}
}

void Role::weaponEffect()
{
	if(weaponNum == 0)
	{
		changeStrength(0);
		changeDex(0);
	}
	if(weaponNum == 1)
	{
		changeStrength(1);
		changeDex(3);
	}
	else if(weaponNum == 2)
	{
		changeStrength(3);
		changeDex(8);
	}
	else if(weaponNum == 3)
	{
		changeStrength(6);
		changeDex(5);
	}
	cout << "Your Strength is " << strength << endl;
	cout << "Your Dex is " << Dex << endl << endl;
}



class Slime
{
	public:
	    Slime();
		~Slime(){};
		bool isDead(){return hp <= 0;};
		void attack();
		void beAttacked();
		int getExp(){return exp;};
	private:
	    int hp;
	    int exp;
		int strength;
};

Slime::Slime() : strength(10)
{
	hp = 70 + rand()%41;
	exp = hp;
}

void Slime::attack()
{
	cout << "Slime attack you , cause " << strength << " demages!!    ";
}

void Slime::beAttacked()
{
	hp -= 20;
	if(hp <= 0) hp = 0;
	cout << "Smile's HP: " << hp << endl << endl;
}



void displayFighting(int k)
{
	for(int i = 0 ; i < 7 ; i++){
		for(int j = 0 ; j < 44 ; j++)
			cout << fighting[k][i][j];
		cout << endl;
	}
	
	cout << endl << "============================================" << endl << endl;
}



int main(){
	bool canMove = false;
	char command;
	unsigned seed;
	Map firstMap("First_Map",1);
	Map secondMap("Second_Map",2);
	Role player1("Andy", 1);
	player1.inistialize_position();
	
	player1.display();
	
	while(!player1.isDead()){
		seed = (unsigned)time(NULL);
		srand(seed);
		
		if(canMove) player1.display();
		if(canMove && rand()%10 > 8) player1.recover();
		canMove = false;
		cout << "key in A/S/D/W/Q (RIGHT/DOWN/LEFT/UP/CHANGE_WEAPON): ";
		cin >> command;
		if(command == 'a' || command == 'A') canMove = player1.moveLeft();
		if(command == 's' || command == 'S') canMove = player1.moveDown();
		if(command == 'd' || command == 'D') canMove = player1.moveRight();
		if(command == 'w' || command == 'W') canMove = player1.moveUp(); 
		if(command == 'q' || command == 'Q') player1.changeWeapon();
				
		if( (rand()%5 > 3) && canMove ){
			cout << endl << "The slime appears!! The Fight starts!!";
			cout << endl << "The slime appears!! The Fight starts!!";
			cout << endl << "The slime appears!! The Fight starts!!";
			cout << endl << endl;
			Slime *slime = new Slime;
			int status = 0;
			while( !slime->isDead() && !player1.isDead() )
			{
				cout << endl;
				cout << "You can choose 1 or 2 to attack the slime," << endl;
				cout << "1: physical attack and 2: magic attack," << endl;
				cout << "pick up your choice: ";
				int randnum;
				cin >> command;
				if(command == '1' || command == '2')
				{
					cout << endl << endl;
//					randnum = rand()%2 + 1;
//					if((int)command == randnum+48)
					if(rand()%100 < player1.getDex())
					{
						player1.attack();
						slime->beAttacked();
						status = !slime->isDead() ? 1 : 3;
					}
					else
					{
						slime->attack();
						player1.beAttacked();
						status = !player1.isDead() ? 2 : 4;
					}
					player1.getWeaponNum() ? displayFighting(status+5) : displayFighting(status);
				}
			}
			if( player1.isDead() ) 
			{
				delete slime;
				break;
			}
			else
			{
				cout << endl << "You win the Fight!! Congratulations!!" << endl;
				player1.raiseExp(slime->getExp());
				player1.levelUp();
				delete slime;
			}
		}

	}
	
	cout << endl << "Your hero is dead , Game Over!!" << endl;

	return 0;
}