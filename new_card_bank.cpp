#include <iostream>
#include "card_bank.h"
#include <vector>
#include <string>
using namespace std;

void upload_all_cards(Card hazzard[], Card starting[], Card aging[], Card pirates[]) {
   hazzard[0].init("Raft Wreck", 0, 1, 3, 1, "Food: +1 life", 0, 1, 1);
   hazzard[1].init("Raft Wreck", 0, 1, 3, 1, "Food: +1 life", 0, 1, 1);
   hazzard[2].init("Raft Wreck", 0, 1, 3, 1, "Mimesis: 1x copy", 0, 1, 1);
   hazzard[3].init("Raft Wreck", 0, 1, 3, 1, "Cognition: 1x destroy", 0, 1, 1);
   hazzard[4].init("Raft Wreck", 0, 1, 3, 1, "Trick: 1x below the stack", 0, 1, 1);
   hazzard[5].init("Raft Wreck", 0, 1, 3, 1, "Books: -1 stage", 0, 1, 1);
   hazzard[6].init("Raft Wreck", 0, 1, 3, 1, "Strategy: 2x exchange", 0, 1, 2);
   hazzard[7].init("Raft Wreck", 0, 1, 3, 1, "Strategy: 2x exchange", 0, 1, 2);
   hazzard[8].init("Raft Wreck", 0, 1, 3, 1, "Toolbox: +2 cards", 0, 1, 2);
   hazzard[9].init("Raft Wreck", 0, 1, 3, 1, "Toolbox: +2 cards", 0, 1, 2);
   hazzard[10].init("Island Exploration", 1, 3, 6, 2, "Cognition: 1x detroy", 1, 1, 1);
   hazzard[11].init("Island Exploration", 1, 3, 6, 2, "Mimesis: 1x copy", 0, 1, 1);
   hazzard[12].init("Island Exploration", 1, 3, 6, 2, "Weapon", 2, 1, 0);
   hazzard[13].init("Island Exploration", 1, 3, 6, 2, "Weapon", 2, 1, 0);
   hazzard[14].init("Island Exploration", 1, 3, 6, 2, "Food: +1 life", 1, 1, 1);
   hazzard[15].init("Island Exploration", 1, 3, 6, 2, "Food: +1 life", 1, 1, 1);
   hazzard[16].init("Island Exploration", 1, 3, 6, 2, "Trick: 1x below the stack", 1, 1, 1);
   hazzard[17].init("Island Exploration", 1, 3, 6, 2, "Production: 1x double", 1, 1, 1);
   hazzard[18].init("Deep Island Exploration", 2, 5, 8, 3, "Production: 1x double", 2, 1, 1);
   hazzard[19].init("Deep Island Exploration", 2, 5, 8, 3, "Food: +1 life", 2, 1, 1);
   hazzard[20].init("Deep Island Exploration", 2, 5, 8, 3, "Strategy: 1x exchange", 2, 1, 1);
   hazzard[21].init("Deep Island Exploration", 2, 5, 8, 3, "Vision: sort 3 cards", 2, 1, 3);
   hazzard[22].init("Deep Island Exploration", 2, 5, 8, 3, "Cognition: 1x detroy", 2, 1, 1);
   hazzard[23].init("Deep Island Exploration", 2, 5, 8, 3, "Experience: +1 card", 2, 1, 1);
   hazzard[24].init("Wild Beasts", 4, 7, 11, 4, "Strategy: 1x exchange", 3, 1, 1);
   hazzard[25].init("Wild Beasts", 4, 7, 11, 4, "Vision: sort 3 cards", 3, 1, 3);
   hazzard[26].init("Wild Beasts", 4, 7, 11, 4, "Experience: +1 card", 3, 1, 1);
   hazzard[27].init("Wild Beasts", 4, 7, 11, 4, "Cognition: 1x destroy", 3, 1, 1);
   hazzard[28].init("Cannibals", 5, 9, 14, 5, "Weapon", 4, 1, 0);
   hazzard[29].init("Cannibals", 5, 9, 14, 5, "Weapon", 4, 1, 0);

   starting[0].init("", 0, 0, 0, 0, "Muse", 2, 1, 0);
   starting[1].init("", 0, 0, 0, 0, "Muse", 2, 1, 0);
   starting[2].init("", 0, 0, 0, 0, "Muse", 2, 1, 0);
   starting[3].init("", 0, 0, 0, 0, "Unconcentrated", -1, 1, 0);
   starting[4].init("", 0, 0, 0, 0, "Unconcentrated", -1, 1, 0);
   starting[5].init("", 0, 0, 0, 0, "Unconcentrated", -1, 1, 0);
   starting[6].init("", 0, 0, 0, 0, "Normal", 0, 1, 0);
   starting[7].init("", 0, 0, 0, 0, "Normal", 0, 1, 0);
   starting[8].init("", 0, 0, 0, 0, "Normal", 0, 1, 0);
   starting[9].init("", 0, 0, 0, 0, "Weak", 0, 1, 0);
   starting[10].init("", 0, 0, 0, 0, "Weak", 0, 1, 0);
   starting[11].init("", 0, 0, 0, 0, "Weak", 0, 1, 0);
   starting[12].init("", 0, 0, 0, 0, "Eat: +2 life", 0, 1, 1);
   starting[13].init("", 0, 0, 0, 0, "Eat: +2 life", 0, 1, 1);
   starting[14].init("", 0, 0, 0, 0, "Eat: +2 life", 0, 1, 1);
   starting[15].init("", 0, 0, 0, 0, "Concentrated", 1, 1, 0);
   starting[16].init("", 0, 0, 0, 0, "Concentrated", 1, 1, 0);
   starting[17].init("", 0, 0, 0, 0, "Concentrated", 1, 1, 0);

   aging[0].init("", 0, 0, 0, 0, "Very Hungry: -2 life", 0, 2, -1);
                    //"-1 usable time" means the function is activated automatically.
   aging[1].init("", 0, 0, 0, 0, "Hungry: -1 life", 0, 2, -1);
   aging[2].init("", 0, 0, 0, 0, "Very Unconcentrated", -2, 2, 0);
   aging[3].init("", 0, 0, 0, 0, "Unconcentrated", -1, 2, 0);
   aging[4].init("", 0, 0, 0, 0, "Fear: highest card = 0", 0, 2, -1);
   aging[5].init("", 0, 0, 0, 0, "Sleepy: stop", 0, 2, -1);
   aging[6].init("", 0, 0, 0, 0, "Stupid", -2, 2, 0);
   aging[7].init("", 0, 0, 0, 0, "Suicide", -5, 2, 0);
   aging[8].init("", 0, 0, 0, 0, "Very Stupid", -3, 2, 0);
   aging[9].init("", 0, 0, 0, 0, "Mad", -4, 2, 0);

   pirates[0].init("The Thriller Bark Pirates", 0, 0, 15, 5, "", 0, 0, 0);
                    //costs[2] means the goal point.
   pirates[1].init("The Fire Tank Pirates", 0, 0, 20, 6, "", 0, 0, 0);
   pirates[2].init("The Kid Pirates", 0, 0, 25, 7, "", 0, 0, 0);
   pirates[3].init("The Kuja Pirates", 0, 0, 16, 7, "", 0, 0, 0);
   pirates[4].init("The Golden Lion Pirates", 0, 0, 24, 8, "", 0, 0, 0);
   pirates[5].init("The Straw Hat Pirates", 0, 0, 30, 8, "", 0, 0, 0);
   pirates[6].init("The Blackbeard Pirate Fleet", 0, 0, 22, 9, "", 0, 0, 0);
   pirates[7].init("The Big Mom Pirates", 0, 0, 35, 9, "", 0, 0, 0);
   pirates[8].init("The Beasts Pirates", 0, 0, 40, 10, "", 0, 0, 0);
   pirates[9].init("The Red Hair Pirates", 0, 0, 52, 10, "", 0, 0, 0);
}
