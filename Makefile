main: main.cpp Entity.o Player.o Monster.o Warrior.o Mage.o Skeleton.o Slime.o Potion.o
	clang++ main.cpp ClassSelect.cpp MonsterGen.cpp PlayerActions.cpp MoveGen.cpp PotionGen.cpp InputChecker.cpp Entity.o Player.o Monster.o Warrior.o Mage.o Skeleton.o Slime.o Potion.o -o main

Entity.o: Entity.h Entity.cpp
	g++ -c Entity.cpp

Monster.o: Monster.h Monster.cpp
	g++ -c Monster.cpp

Player.o: Player.h Player.cpp
	g++ -c Player.cpp

Warrior.o: Warrior.h Warrior.cpp
	g++ -c Warrior.cpp

Mage.o: Mage.h Mage.cpp
	g++ -c Mage.cpp

Skeleton.o: Skeleton.h Skeleton.cpp
	g++ -c Skeleton.cpp

Slime.o: Slime.h Slime.cpp
	g++ -c Slime.cpp

Potion.o: Potion.h Potion.cpp
	g++ -c Potion.cpp

test: TesterEntity TesterPlayer TesterMonster

TesterEntity: TesterEntity.cpp Entity.h Entity.cpp Slime.h Slime.cpp Monster.h Monster.cpp
	g++ TesterEntity.cpp Slime.cpp Entity.cpp Monster.cpp
	./a.out

TesterMonster: TesterMonster.cpp Entity.h Entity.cpp Slime.h Slime.cpp Monster.h Monster.cpp Skeleton.h Skeleton.cpp
	g++ TesterMonster.cpp Slime.cpp Skeleton.cpp Entity.cpp Monster.cpp
	./a.out

TesterPlayer: TesterPlayer.cpp Entity.cpp Entity.h Player.h Player.cpp Warrior.h Warrior.cpp Monster.h Monster.cpp Skeleton.h Skeleton.cpp
	g++ TesterPlayer.cpp Entity.cpp Player.cpp Warrior.cpp Monster.cpp Skeleton.cpp
	./a.out