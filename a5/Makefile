XX = g++
CXXFLAGS = -Wall -MMD

OBJECTS = cc3k.o textdisplay.o factory.o cell.o chamber.o CC3K/grid_bug.o CC3K/goblin.o CC3K/dragon.o CC3K/merchant.o CC3K/gameobject.o CC3K/wall1.o CC3K/wall2.o CC3K/stairway.o CC3K/blank.o CC3K/door.o CC3K/passage.o CC3K/enemy.o CC3K/knight.o CC3K/orc.o CC3K/dragonHoard.o CC3K/enemy.o CC3K/floorelem.o CC3K/gameobject.o CC3K/goldPile.o CC3K/passage.o CC3K/potion.o CC3K/potion_BA.o CC3K/potion_RH.o CC3K/potion_PH.o CC3K/potion_BD.o CC3K/potion_WA.o CC3K/potion_WD.o CC3K/treasure.o CC3K/playercharacter.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = cc3k

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean

clean :
	rm ${DEPENDS} ${EXEC} ${OBJECTS} 