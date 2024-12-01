// Includes

#include <PA9.h>       // Include for PA_Lib

#if 0
#include "MessageQueue.h"	// Includes for liblobby
#include "802.11.h"
#include "lobby.h"
#endif

#include "gfx/all_gfx.c"
#include "gfx/all_gfx.h"

#include "annuler.h"
#include "bruitCarte.h"
#include "choix.h"
#include "erreur.h"
#include "fleche.h"
#include "flecheRot.h"
#include "nouvelleCarte.h"
#include "ouvrir.h"
#include "retournerCarte.h"
#include "valider.h"

// REF

/*	LANGUES	*/

int lang=0;

const char * nomCarte[2][111] = {
	{"","Bogomile","Fungus","Elmidea","Nocturnus","Incube","Aphide","Elastos","Phantom","Carnidea","Larva","Gallus","Orchida","Schizoïd","Licorne","Xylopode","Koalt","Malaku","Arconada","Formicide","Feng","Héra","Selek","Weevil","Scavenger","Adéphage","Diodon","Satyrux","Trogiidae","Barbarian","Berserker","Pampa","Tomberry","Célébis","Eiffel","Cariatide","T-Rex","Succube","Tikal","Wendigo","Marsupial","Draconus","Moloch","Ao","Polyphage","Ekarissor","Kanibal","Chimaira","Koyo K","Protesis","Pikasso","Xylomid","Griffon","Sulfor","Tomberry Senior","Wedge/Biggs","Fujin/Raijin","Sulfura","Goliath","Lygus","Ecorché","Iguanor","Hornet","Flotix","Cyanide","Shumi","Krystal","Alienator","Pampa Senior","Acron","Agamemnon","Anakronox","Mithra","Acarnan","Omniborg","Attila","Fabryce","Monarch","GroChocobo","Angel","Gilgamesh","MiniMog","Chicobo","Golgotha","Shiva","Ifrit","Ondine","Tauros","Taurux","Ahuri","Nosferatu","Leviathan","Odin","Zéphir","Cerbères","Alexander","Phoenix","Bahamut","Helltrain","Orbital","Ward","Kiros","Laguna","Selphie","Quistis","Irvine","Zell","Linoa","Edea","Seifer","Squall"},
	{"","Geezard","Funguar","Bite Bug","Red Bat","Blobra","Gayla","Gesper","Fastitocalon-F","Blood Soul","Caterchipillar","Cockatrice","Grat","Buel","Mesmerize","Glacial Eye","Belhelmel","Thrustaevis","Anacondaur","Creeps","Grendel","Jellyeye","Grand Mantis","Forbidden","Armadodo","Tri-Face","Fastitocalon","Snow Lion","Ochu","SAM08G","Death Claw","Cactuar","Tonberry","Abyss Worm","Turtapod","Vysage","T-Rexaur","Bomb","Blitz","Wendigo","Torama","Imp","Blue Dragon","Adamantoise","Hexadragon","Iron Giant","Behemoth","Chimera","Pupu","Elastoid","GIM47N","Malboro","Ruby Dragon","Elnoyle","Tonberry King","Wedge & Biggs","Fujin & Raijin","Elvoret","X-ATM092","Granaldo","Gerogero","Iguion","Abadon","Trauma","Oilboyle","Shumi Tribe","Krysta","Propagator","Jumbo Cactuar","Tri-point","Gargantua","Mobile Type 8","Sphinxara","Tiamat","BGH251F2","Red Giant","Catoblepas","Ultima Weapon","Chubby Chocobo","Angelo","Gilgamesh","Minimog","Chicobo","Quezacotl","Shiva","Ifrit","Siren","Sacred","Minotaur","Carbuncle","Diablos","Leviathan","Odin","Pandemona","Cerebus","Alexander","Phoenix","Bahamut","Doomtrain","Eden","Ward","Kiros","Laguna","Selphie","Quistis","Irvine","Zell","Rinoa","Edea","Seifer","Squall"}
};

const char * nomAdv[2][14] = {
	{"Squall","Zell","Selphie","Linoa","Quistis","Irvine","Seifer","Ward","Kiros","Laguna","Edea","Cid","Boko","Moomba"},
	{"Squall","Zell","Selphie","Rinoa","Quistis","Irvine","Seifer","Ward","Kiros","Laguna","Edea","Cid","Boko","Moomba"}
};

const char * nomRegle[2][8] = {
	{"Open","Mort subite","Aléatoire","Identique","Plus","Combo","Même murs","Elémentaire"},
	{"Open","Sudden Death","Random","Same","Plus","Combo","Same Wall","Elemental"}
};

const char * nomRegleVainqueur[2][4] = {
	{"One","Directe","Change","Totale"},
	{"One","Direct","Diff","All"}
};

const char * message[2][69] = {
	{"Oui            Non","Refaire une partie","Changer de persos","Changer de règles","Quitter la partie","Cartes possédées :","Monstre","Boss","G-Force","Perso","Total","Victoires","Défaites","Egalités","Carte","niveau","Valider","Aucune","Revenir au\nmenu principal ?","Annuler la partie ?","Choisissez votre personnage","Jouer avec","Revenir au menu\nprécédent ?","Sélectionnez les règles de la partie","Règles :","Vous confirmez ?","Choisissez","Prendre cette carte ?","Prendre ces cartes ?","carte","cartes","perdue","gagnée","Règle du vainqueur :","Votre adversaire change de perso","Votre adversaire change de règles","En attente de l'adversaire","Votre adversaire a quitté la partie.","En attente d'un joueur...","Téléchargement d'un nouveau joueur...","Un adversaire trouvé","adversaires trouvés","Votre adversaire a annulé son invitation.","Accepter l'invitation ?","Votre adversaire choisit son personnage","Refuser l'invitation ?","Annuler la recherche\nde joueurs ?","Aucun adversaire trouvé","Annuler l'invitation ?","Défier ce joueur ?","Attente de la confirmation de l'adversaire","Ce joueur est déjà en train de jouer.","Il ne vous reste plus assez de cartes...","Programmé par Minoru","Les images et les musiques appartiennent à Squaresoft","Merci d'avoir joué !","Vous pouvez maintenant défier","Choisissez un adversaire","Jouer contre","Vous ne pouvez pas jeter une carte rare.","Vous n'aurez plus assez de cartes si vous jetez celle-ci.","Voulez-vous jeter cette carte ?","Votre adversaire a quitté la partie.","Vous devez maintenant éteindre la console.","L'adversaire a refusé de jouer avec vous.","Impossible de charger la sauvegarde.","Etes-vous sûr ?","Données effacées.","Carte "},
	{"Yes            No    ","Play again","Change characters","Changer rules","Exit","Cards owned :","Monster","Boss","G-Force","Character","Total","Victories","Defeats","Draws","Card","level","Confirm","None","Back to main menu ?","Cancel ?","Choose your character","Play with","Back to\nprevious menu ?","Choose the rules for the game","Rules :","Are you sure ?","Choose","Take that card ?","Take these cards ?","card you want","cards you want","Card lost","Card acquired","Trade rule :","Your opponent change his character","Your opponent change the rules","Pending the opponent","Your opponent has left the game.","Pending a player...","Downloading a new player...","One player found","players found","Your opponent has canceled his invitation.","Accept the invitation ?","Your opponent choose his character","Refuse the invitation ?","Cancel player researching ?","No player found","Cancel the invitation ?","Challenge this player ?","Pending your opponent's confirmation","This player is already in game.","You have no cards enought...","Programmed by Minoru","Pictures and musics belong to Squaresoft","Thank you for playing !","You can now challenge","Choose your opponent","Challenge","You cannot throw a rare card.","You will not have enough cards if you throw this one.","Do you want to throw that card ?","Your opponent has left the game.","You must now turn off the console.","The opponent has refused to play with you.","Unable to load the save file.","Are you sure ?","Data cleared.",""}
};

/* LANGUES*/

const unsigned short * carteG_Pal[2][111] = {
	{c000g_Pal,c001rg_Pal,c002rg_Pal,c003rg_Pal,c004rg_Pal,c005rg_Pal,c006rg_Pal,c007rg_Pal,c008rg_Pal,c009rg_Pal,c010rg_Pal,c011rg_Pal,c012rg_Pal,c013rg_Pal,c014rg_Pal,c015rg_Pal,c016rg_Pal,c017rg_Pal,c018rg_Pal,c019rg_Pal,c020rg_Pal,c021rg_Pal,c022rg_Pal,c023rg_Pal,c024rg_Pal,c025rg_Pal,c026rg_Pal,c027rg_Pal,c028rg_Pal,c029rg_Pal,c030rg_Pal,c031rg_Pal,c032rg_Pal,c033rg_Pal,c034rg_Pal,c035rg_Pal,c036rg_Pal,c037rg_Pal,c038rg_Pal,c039rg_Pal,c040rg_Pal,c041rg_Pal,c042rg_Pal,c043rg_Pal,c044rg_Pal,c045rg_Pal,c046rg_Pal,c047rg_Pal,c048rg_Pal,c049rg_Pal,c050rg_Pal,c051rg_Pal,c052rg_Pal,c053rg_Pal,c054rg_Pal,c055rg_Pal,c056rg_Pal,c057rg_Pal,c058rg_Pal,c059rg_Pal,c060rg_Pal,c061rg_Pal,c062rg_Pal,c063rg_Pal,c064rg_Pal,c065rg_Pal,c066rg_Pal,c067rg_Pal,c068rg_Pal,c069rg_Pal,c070rg_Pal,c071rg_Pal,c072rg_Pal,c073rg_Pal,c074rg_Pal,c075rg_Pal,c076rg_Pal,c077rg_Pal,c078rg_Pal,c079rg_Pal,c080rg_Pal,c081rg_Pal,c082rg_Pal,c083rg_Pal,c084rg_Pal,c085rg_Pal,c086rg_Pal,c087rg_Pal,c088rg_Pal,c089rg_Pal,c090rg_Pal,c091rg_Pal,c092rg_Pal,c093rg_Pal,c094rg_Pal,c095rg_Pal,c096rg_Pal,c097rg_Pal,c098rg_Pal,c099rg_Pal,c100rg_Pal,c101rg_Pal,c102rg_Pal,c103rg_Pal,c104rg_Pal,c105rg_Pal,c106rg_Pal,c107rg_Pal,c108rg_Pal,c109rg_Pal,c110rg_Pal},
	{c000g_Pal,c001bg_Pal,c002bg_Pal,c003bg_Pal,c004bg_Pal,c005bg_Pal,c006bg_Pal,c007bg_Pal,c008bg_Pal,c009bg_Pal,c010bg_Pal,c011bg_Pal,c012bg_Pal,c013bg_Pal,c014bg_Pal,c015bg_Pal,c016bg_Pal,c017bg_Pal,c018bg_Pal,c019bg_Pal,c020bg_Pal,c021bg_Pal,c022bg_Pal,c023bg_Pal,c024bg_Pal,c025bg_Pal,c026bg_Pal,c027bg_Pal,c028bg_Pal,c029bg_Pal,c030bg_Pal,c031bg_Pal,c032bg_Pal,c033bg_Pal,c034bg_Pal,c035bg_Pal,c036bg_Pal,c037bg_Pal,c038bg_Pal,c039bg_Pal,c040bg_Pal,c041bg_Pal,c042bg_Pal,c043bg_Pal,c044bg_Pal,c045bg_Pal,c046bg_Pal,c047bg_Pal,c048bg_Pal,c049bg_Pal,c050bg_Pal,c051bg_Pal,c052bg_Pal,c053bg_Pal,c054bg_Pal,c055bg_Pal,c056bg_Pal,c057bg_Pal,c058bg_Pal,c059bg_Pal,c060bg_Pal,c061bg_Pal,c062bg_Pal,c063bg_Pal,c064bg_Pal,c065bg_Pal,c066bg_Pal,c067bg_Pal,c068bg_Pal,c069bg_Pal,c070bg_Pal,c071bg_Pal,c072bg_Pal,c073bg_Pal,c074bg_Pal,c075bg_Pal,c076bg_Pal,c077bg_Pal,c078bg_Pal,c079bg_Pal,c080bg_Pal,c081bg_Pal,c082bg_Pal,c083bg_Pal,c084bg_Pal,c085bg_Pal,c086bg_Pal,c087bg_Pal,c088bg_Pal,c089bg_Pal,c090bg_Pal,c091bg_Pal,c092bg_Pal,c093bg_Pal,c094bg_Pal,c095bg_Pal,c096bg_Pal,c097bg_Pal,c098bg_Pal,c099bg_Pal,c100bg_Pal,c101bg_Pal,c102bg_Pal,c103bg_Pal,c104bg_Pal,c105bg_Pal,c106bg_Pal,c107bg_Pal,c108bg_Pal,c109bg_Pal,c110bg_Pal}
};

const unsigned char * carteG_Sprite[2][111] = {
	{c000g_Sprite,c001rg_Sprite,c002rg_Sprite,c003rg_Sprite,c004rg_Sprite,c005rg_Sprite,c006rg_Sprite,c007rg_Sprite,c008rg_Sprite,c009rg_Sprite,c010rg_Sprite,c011rg_Sprite,c012rg_Sprite,c013rg_Sprite,c014rg_Sprite,c015rg_Sprite,c016rg_Sprite,c017rg_Sprite,c018rg_Sprite,c019rg_Sprite,c020rg_Sprite,c021rg_Sprite,c022rg_Sprite,c023rg_Sprite,c024rg_Sprite,c025rg_Sprite,c026rg_Sprite,c027rg_Sprite,c028rg_Sprite,c029rg_Sprite,c030rg_Sprite,c031rg_Sprite,c032rg_Sprite,c033rg_Sprite,c034rg_Sprite,c035rg_Sprite,c036rg_Sprite,c037rg_Sprite,c038rg_Sprite,c039rg_Sprite,c040rg_Sprite,c041rg_Sprite,c042rg_Sprite,c043rg_Sprite,c044rg_Sprite,c045rg_Sprite,c046rg_Sprite,c047rg_Sprite,c048rg_Sprite,c049rg_Sprite,c050rg_Sprite,c051rg_Sprite,c052rg_Sprite,c053rg_Sprite,c054rg_Sprite,c055rg_Sprite,c056rg_Sprite,c057rg_Sprite,c058rg_Sprite,c059rg_Sprite,c060rg_Sprite,c061rg_Sprite,c062rg_Sprite,c063rg_Sprite,c064rg_Sprite,c065rg_Sprite,c066rg_Sprite,c067rg_Sprite,c068rg_Sprite,c069rg_Sprite,c070rg_Sprite,c071rg_Sprite,c072rg_Sprite,c073rg_Sprite,c074rg_Sprite,c075rg_Sprite,c076rg_Sprite,c077rg_Sprite,c078rg_Sprite,c079rg_Sprite,c080rg_Sprite,c081rg_Sprite,c082rg_Sprite,c083rg_Sprite,c084rg_Sprite,c085rg_Sprite,c086rg_Sprite,c087rg_Sprite,c088rg_Sprite,c089rg_Sprite,c090rg_Sprite,c091rg_Sprite,c092rg_Sprite,c093rg_Sprite,c094rg_Sprite,c095rg_Sprite,c096rg_Sprite,c097rg_Sprite,c098rg_Sprite,c099rg_Sprite,c100rg_Sprite,c101rg_Sprite,c102rg_Sprite,c103rg_Sprite,c104rg_Sprite,c105rg_Sprite,c106rg_Sprite,c107rg_Sprite,c108rg_Sprite,c109rg_Sprite,c110rg_Sprite},
	{c000g_Sprite,c001bg_Sprite,c002bg_Sprite,c003bg_Sprite,c004bg_Sprite,c005bg_Sprite,c006bg_Sprite,c007bg_Sprite,c008bg_Sprite,c009bg_Sprite,c010bg_Sprite,c011bg_Sprite,c012bg_Sprite,c013bg_Sprite,c014bg_Sprite,c015bg_Sprite,c016bg_Sprite,c017bg_Sprite,c018bg_Sprite,c019bg_Sprite,c020bg_Sprite,c021bg_Sprite,c022bg_Sprite,c023bg_Sprite,c024bg_Sprite,c025bg_Sprite,c026bg_Sprite,c027bg_Sprite,c028bg_Sprite,c029bg_Sprite,c030bg_Sprite,c031bg_Sprite,c032bg_Sprite,c033bg_Sprite,c034bg_Sprite,c035bg_Sprite,c036bg_Sprite,c037bg_Sprite,c038bg_Sprite,c039bg_Sprite,c040bg_Sprite,c041bg_Sprite,c042bg_Sprite,c043bg_Sprite,c044bg_Sprite,c045bg_Sprite,c046bg_Sprite,c047bg_Sprite,c048bg_Sprite,c049bg_Sprite,c050bg_Sprite,c051bg_Sprite,c052bg_Sprite,c053bg_Sprite,c054bg_Sprite,c055bg_Sprite,c056bg_Sprite,c057bg_Sprite,c058bg_Sprite,c059bg_Sprite,c060bg_Sprite,c061bg_Sprite,c062bg_Sprite,c063bg_Sprite,c064bg_Sprite,c065bg_Sprite,c066bg_Sprite,c067bg_Sprite,c068bg_Sprite,c069bg_Sprite,c070bg_Sprite,c071bg_Sprite,c072bg_Sprite,c073bg_Sprite,c074bg_Sprite,c075bg_Sprite,c076bg_Sprite,c077bg_Sprite,c078bg_Sprite,c079bg_Sprite,c080bg_Sprite,c081bg_Sprite,c082bg_Sprite,c083bg_Sprite,c084bg_Sprite,c085bg_Sprite,c086bg_Sprite,c087bg_Sprite,c088bg_Sprite,c089bg_Sprite,c090bg_Sprite,c091bg_Sprite,c092bg_Sprite,c093bg_Sprite,c094bg_Sprite,c095bg_Sprite,c096bg_Sprite,c097bg_Sprite,c098bg_Sprite,c099bg_Sprite,c100bg_Sprite,c101bg_Sprite,c102bg_Sprite,c103bg_Sprite,c104bg_Sprite,c105bg_Sprite,c106bg_Sprite,c107bg_Sprite,c108bg_Sprite,c109bg_Sprite,c110bg_Sprite}
};

const unsigned char * cadre_Pal[14] = {persoc00_Pal,persoc01_Pal,persoc02_Pal,persoc03_Pal,persoc04_Pal,persoc05_Pal,persoc06_Pal,persoc07_Pal,persoc08_Pal,persoc09_Pal,persoc10_Pal,persoc11_Pal,persoc12_Pal,persoc13_Pal};

const unsigned char * cadre_Sprite[14] = {persoc00_Sprite,persoc01_Sprite,persoc02_Sprite,persoc03_Sprite,persoc04_Sprite,persoc05_Sprite,persoc06_Sprite,persoc07_Sprite,persoc08_Sprite,persoc09_Sprite,persoc10_Sprite,persoc11_Sprite,persoc12_Sprite,persoc13_Sprite};

const unsigned char * perso_Pal[15] = {persog00_Pal,persog01_Pal,persog02_Pal,persog03_Pal,persog04_Pal,persog05_Pal,persog06_Pal,persog07_Pal,persog08_Pal,persog09_Pal,persog10_Pal,persog11_Pal,persog12_Pal,persog13_Pal,persog14_Pal};

const unsigned char * perso_Sprite[15][4] = {{persog000_Sprite,persog001_Sprite,persog002_Sprite,persog003_Sprite},{persog010_Sprite,persog011_Sprite,persog012_Sprite,persog013_Sprite},{persog020_Sprite,persog021_Sprite,persog022_Sprite,persog023_Sprite},{persog030_Sprite,persog031_Sprite,persog032_Sprite,persog033_Sprite},{persog040_Sprite,persog041_Sprite,persog042_Sprite,persog043_Sprite},{persog050_Sprite,persog051_Sprite,persog052_Sprite,persog053_Sprite},{persog060_Sprite,persog061_Sprite,persog062_Sprite,persog063_Sprite},{persog070_Sprite,persog071_Sprite,persog072_Sprite,persog073_Sprite},{persog080_Sprite,persog081_Sprite,persog082_Sprite,persog083_Sprite},{persog090_Sprite,persog091_Sprite,persog092_Sprite,persog093_Sprite},{persog100_Sprite,persog101_Sprite,persog102_Sprite,persog103_Sprite},{persog110_Sprite,persog111_Sprite,persog112_Sprite,persog113_Sprite},{persog120_Sprite,persog121_Sprite,persog122_Sprite,persog123_Sprite},{persog130_Sprite,persog131_Sprite,persog132_Sprite,persog133_Sprite},{persog140_Sprite,persog141_Sprite,persog142_Sprite,persog143_Sprite}};

const unsigned char * element_Texture[9] = {0,element1_Texture,element2_Texture,element3_Texture,element4_Texture,element5_Texture,element6_Texture,element7_Texture,element8_Texture};

const unsigned short text_Pal[16] __attribute__ ((aligned (4))) = {PA_RGB(0,0,0), PA_RGB(31,31,31), PA_RGB(8,8,8), PA_RGB(16,16,16), PA_RGB(16,16,31), PA_RGB(31,31,16),PA_RGB(0,0,0), 0, 0, 0, 0, 0, 0, 0, 0, PA_RGB(31,0,31)};

const unsigned int valeurCarte[111][4] = {
	{10,10,10,10},
	{1,5,4,1},
	{5,3,1,1},
	{1,5,3,3},
	{6,2,1,1},
	{2,5,3,1},
	{2,4,1,4},
	{1,1,5,4},
	{3,1,5,2},
	{2,1,1,6},
	{4,3,2,4},
	{2,6,1,2},
	{7,1,1,3},
	{6,3,2,2},
	{5,4,3,3},
	{6,3,1,4},
	{3,3,4,5},
	{5,5,3,2},
	{5,5,1,3},
	{5,2,2,5},
	{4,2,4,5},
	{3,7,2,1},
	{5,3,2,5},
	{6,2,6,3},
	{6,6,3,1},
	{3,5,5,5},
	{7,3,5,1},
	{7,3,1,5},
	{5,3,6,3},
	{5,4,6,2},
	{4,2,4,7},
	{6,3,2,6},
	{3,4,6,4},
	{7,5,2,3},
	{2,7,3,6},
	{6,5,5,4},
	{4,7,6,2},
	{2,3,7,6},
	{1,7,6,4},
	{7,6,3,1},
	{7,4,4,4},
	{3,6,7,3},
	{6,3,2,7},
	{4,6,5,5},
	{7,3,5,4},
	{6,5,5,6},
	{3,7,6,5},
	{7,3,6,5},
	{3,1,10,2},
	{6,7,2,6},
	{5,4,5,7},
	{7,2,7,4},
	{7,4,2,7},
	{5,6,3,7},
	{4,4,6,7},
	{6,7,6,2},
	{2,4,8,8},
	{7,4,8,3},
	{4,3,8,7},
	{7,5,2,8},
	{1,3,8,8},
	{8,2,2,8},
	{6,5,8,4},
	{4,6,8,5},
	{1,8,8,4},
	{6,4,5,8},
	{7,1,5,8},
	{8,8,4,4},
	{8,4,8,4},
	{8,8,5,2},
	{5,8,6,6},
	{8,3,6,7},
	{8,8,3,5},
	{8,4,8,5},
	{5,5,7,8},
	{6,7,8,4},
	{1,7,8,7},
	{7,8,7,2},
	{4,9,4,8},
	{9,3,6,7},
	{3,6,7,9},
	{9,2,3,9},
	{9,4,4,8},
	{2,4,9,9},
	{6,9,7,4},
	{9,8,6,2},
	{8,2,9,6},
	{5,9,1,9},
	{9,9,5,2},
	{8,4,4,10},
	{5,3,10,8},
	{7,7,10,1},
	{8,5,10,3},
	{10,7,1,7},
	{7,10,4,6},
	{9,2,10,4},
	{7,10,2,7},
	{10,6,8,2},
	{3,10,1,10},
	{4,10,4,9},
	{10,8,7,2},
	{6,10,7,6},
	{5,9,10,3},
	{10,4,8,6},
	{9,2,6,10},
	{2,10,6,9},
	{8,6,5,10},
	{4,10,10,2},
	{10,3,10,3},
	{6,4,9,10},
	{10,9,4,6}
};

const int elementCarte[111] = {0,0,0,0,0,0,2,0,7,0,0,2,0,0,0,4,0,8,5,2,2,0,0,0,7,5,7,4,0,3,3,0,0,7,0,0,0,3,2,0,0,0,5,7,3,0,0,1,0,0,0,5,3,0,0,0,0,8,0,0,5,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,2,4,3,0,7,7,0,0,1,0,8,0,6,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0};

/*const char * nomCarte[lang][111] = {"","Bogomile","Fungus","Elmidea","Nocturnus","Incube","Aphide","Elastos","Phantom","Carnidea","Larva","Gallus","Orchida","Schizoïd","Licorne","Xylopode","Koalt","Malaku","Arconada","Formicide","Feng","Héra","Selek","Weevil","Scavenger","Adéphage","Diodon","Satyrux","Trogiidae","Barbarian","Berserker","Pampa","Tomberry","Célébis","Eiffel","Cariatide","T-Rex","Succube","Tikal","Wendigo","Marsupial","Draconus","Moloch","Ao","Polyphage","Ekarissor","Kanibal","Chimaira","Koyo K","Protesis","Pikasso","Xylomid","Griffon","Sulfor","Tomberry Senior","Wedge/Biggs","Fujin/Raijin","Sulfura","Goliath","Lygus","Ecorché","Iguanor","Hornet","Flotix","Cyanide","Shumi","Krystal","Alienator","Pampa Senior","Acron","Agamemnon","Anakronox","Mithra","Acarnan","Omniborg","Attila","Fabryce","Monarch","GroChocobo","Angel","Gilgamesh","MiniMog","Chicobo","Golgotha","Shiva","Ifrit","Ondine","Tauros","Taurux","Ahuri","Nosferatu","Leviathan","Odin","Zéphir","Cerbères","Alexander","Phoenix","Bahamut","Helltrain","Orbital","Ward","Kiros","Laguna","Selphie","Quistis","Irvine","Zell","Linoa","Edea","Seifer","Squall"};

const char * nomAdv[lang][14] = {"Squall","Zell","Selphie","Linoa","Quistis","Irvine","Seifer","Ward","Kiros","Laguna","Edea","Cid","Boko","Moomba"};

const char * nomRegle[lang][8] = {"Open","Mort subite","Aléatoire","Identique","Plus","Combo","Même murs","Elémentaire"};

const char * nomRegleVainqueur[lang][4] = {"One","Directe","Change","Totale"};*/

const int regleAdv[12][9] = {	// 0 = Open ; 1 = Mort subite ; 2 = Aléatoire ; 3 = Identique ; 4 = Plus ; 5 = Combo ; 6 = Même murs ; 7 = Elémentaire ; 8 = Vainqueur{0=One;1=Directe;2=Change;3=Totale}
//	{1,1,1,1,1,1,1,1,2},	// Faux Zell (bouh !)
	{1,0,0,0,0,0,0,0,0},	// Zell		-- Open, One
	{0,0,0,0,0,0,0,0,0},	// Selphie	-- One
	{1,0,0,1,0,0,0,0,0},	// Linoa	-- Open, Identique, One
	{1,0,0,0,0,0,0,1,0},	// Quistis	-- Open, Elémentaire, One
	{1,0,0,1,1,0,0,0,2},	// Irvine	-- Open, Identique, Plus, Change
	{1,0,0,1,1,0,0,1,3},	// Seifer	-- Open, Identique, Plus, Elémentaire, Totale
	{1,0,0,1,1,1,0,0,0},	// Ward		-- Open, Identique, Plus, Combo, One
	{1,0,1,1,1,0,0,0,2},	// Kiros	-- Open, Aléatoire, Identique, Plus, Change
	{1,0,0,1,1,1,1,1,2},	// Laguna	-- Open, Identique, Plus, Combo, Même murs, Elémentaire, Change
	{0,1,0,1,1,1,1,1,3},	// Edea		-- Mort subite, Identique, Plus, Combo, Même Murs, Elémentaire, Totale
	{1,0,0,1,1,1,0,0,1},	// Cid		-- Open, Identique, Plus, Combo, Directe
	{0,1,1,1,1,1,1,1,1}	// Boko		-- Mort subite, Aléatoire, Identique, Plus, Combo, Même murs, Elémentaire, Directe
};

const int conditionDebloquer[12][2] = {	// 0 = Nombre de victoire ; 1 = Numero de carte à gagner
	{1,0},		// Zell
	{0,86},		// Selphie
	{0,79},		// Linoa
	{3,0},		// Quistis
	{5,0},		// Irvine
	{1,0},		// Seifer
	{5,0},		// Ward
	{7,0},		// Kiros
	{0,97},		// Laguna
	{10,0},		// Edea
	{0,110},	// Cid
	{1,0}		// Boko
};

int reglePerso[8];
int regleWifi[8];
int collection[111];
int historique[111];
int persoDebloque;
int cartesRares[12][33];
int victoires[12][3];	// 0 = victoires ; 1 = défaites ; 2 = match nul
int dernierAdversaire;

const int styleJeu[12][8] = {		// 0 = Retourner carte ; 1 = Valeur libre ; 2 = Face cachée ; 3 = Entre 2 cartes ; 4 = Protection ; 5 = Numero carte prise ; 6 = Gachi ; 7 = Anticipation
	{100,1,0,0,0,0,0,0},		// Zell
	{50,24,24,0,0,0,0,0},		// Selphie
	{100,1,36,3,3,0,0,0},		// Linoa
	{100,1,24,5,2,0,0,1},		// Quistis
	{100,1,24,5,2,0,1,1},		// Irvine
	{500,1,24,5,2,0,0,1},		// Seifer
	{100,1,24,5,2,0,1,1},		// Ward
	{100,1,24,5,2,0,1,1},		// Kiros
	{100,1,24,6,2,0,1,2},		// Laguna
	{150,1,60,8,5,0,0,2},		// Edea
	{150,1,60,10,5,1,1,2},		// Cid
	{300,5,120,20,10,2,2,2}	// Boko
};

const int carteLvlMax[12][2] = {
	{1,2},	// Zell
	{1,3},	// Selphie
	{1,4},	// Linoa
	{2,4},	// Quistis
	{2,5},	// Irvine
	{3,6},	// Seifer
	{3,6},	// Ward
	{4,6},	// Kiros
	{4,6},	// Laguna
	{5,7},	// Edea
	{5,7},	// Cid
	{1,7}	// Boko
};

const int carteDebloque[12][3] = {
	{0,3,11},	// Zell		-- Débloque GF2 après Linoa		-- Persos après Cid
	{0,5,8},	// Selphie	-- Débloque GF2 après Irvine	-- Débloque Persos après Kiros
	{0,6,12},	// Linoa	-- Débloque GF2 après Seifer	-- Persos après Boko
	{0,0,0},	// Quistis	-- Tous déloqués dès le début
	{0,7,0},	// Irvine	-- Débloque GF2 après Ward
	{0,7,0},	// Seifer	-- Débloque GF2 après Ward
	{0,0,9},	// Ward		-- Débloque Persos après Laguna
	{0,9,0},	// Kiros	-- Débloque GF2 après Laguna
	{0,10,0},	// Laguna	-- Débloque GF2 après Edea
	{0,0,11},	// Edea		-- Débloque Persos après Cid
	{0,0,12},	// Cid		-- Débloque Persos après Boko
	{13,0,0}	// Boko		-- Débloque GF1 après FIN
};

int cartesRaresInit[12][33] = {
	{0,0,0,1,0,0,0,0,0,0,0, 0,0,0,0,1,0,0,0,0,0,0, 0,0,0,0,1,0,0,0,0,0,0},	// Zell
	{0,0,0,0,0,0,0,0,1,0,0, 0,0,1,0,0,0,0,0,0,0,0, 0,0,0,0,0,1,0,0,0,0,0},	// Selphie
	{0,1,1,0,0,0,0,0,0,0,0, 0,0,0,1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,0,0,0},	// Linoa
	{0,0,0,0,0,1,1,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0},	// Quistis
	{0,0,0,0,0,0,0,0,0,1,1, 1,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0},	// Irvine
	{0,0,0,0,0,0,0,1,0,0,0, 0,0,0,0,0,1,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,1,0},	// Seifer
	{0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,1,0,0,0,0, 0,0,1,0,0,0,0,0,0,0,0},	// Ward
	{0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,1,0,0,0, 1,0,0,0,0,0,0,0,0,0,0},	// Kiros
	{0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,1,0,0, 0,1,0,0,0,0,0,0,0,0,0},	// Laguna
	{0,0,0,0,0,0,0,0,0,0,0, 0,1,0,0,0,0,0,0,0,1,0, 0,0,0,1,0,0,1,0,0,0,0},	// Edea
	{0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,1,0,1},	// Cid
	{1,0,0,0,1,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0}	// Boko
  /* G A G  M C G S I O T T  A  N L O Z C A P  B H O  W K L S Q  I Z L E S S
	 r n i  i h o h f n a a  h  o é d é e l h  a e r  a i a e u  r e i d e q
	 o g l  n i l i r d u u  u  s v i p r e o  h l b  r r g l i  v l n e i u
	 c e g  i c g v i i r r  r  f i n h b x e  a l i  d o u p s  i l o a f a
	 h l a  m o o a t n o u  i  e a   y è a n  m t t    s n h t  n   a   e l
	 o   m  o b t     e s x     r t   r r n i  u r a      a i i  e       r l
	 c   e  g o h               a h     e d x  t a l        e s
	 o   s      a               t a     s e      i
	 b   h                      u n       r      n
	 o
   */
};

const int chanceCarteRare[12] = {
	2,	// Zell
	2,	// Selphie
	2,	// Linoa
	2,	// Quistis
	3,	// Irvine
	1,	// Seifer
	3,	// Ward
	3,	// Kiros
	3,	// Laguna
	4,	// Edea
	4,	// Cid
	7	// Boko
};

/*const int echangeAdv[12][12] = {	// Chance d'échanger des cartes quand on éteind la DS pendant 12h (une chance sur n)
	{0,4,6,4,8,50,20,70,0,16,12,100},			// Zell
	{3,0,5,4,2,10,20,50,70,16,30,100},		// Selphie
	{8,10,0,7,7,16,60,60,50,30,70,100},		// Linoa
	{12,16,10,0,8,9,60,60,60,16,16,100},			// Quistis
	{20,3,8,8,0,20,50,40,50,30,50,100},			// Irvine
	{50,50,40,40,50,0,30,30,40,20,60,100},			// Seifer
	{50,4,6,4,8,20,0,0,0,16,12,100},			// Ward					JE ME SUIS ARRETE LA
	{0,4,6,4,8,20,50,0,0,16,12,100},			// Kiros
	{0,4,6,4,8,20,50,0,0,16,12,100},			// Laguna
	{0,4,6,4,8,20,50,0,0,0,12,100},			// Edea
	{0,4,6,4,8,20,50,0,0,16,0,100},			// Cid
	{0,0,0,0,0,0,0,0,0,0,0,0}				// Boko (Boko ne perd jamais)
};*/

int plateau[5][5];
int idCarte[5][5];
int plateauJoueur[5][5];
int elementPlateau[5][5];	// 0=rien ; 1=eau ; 2=eclair ; 3=feu ; 4=glace ; 5=poison ; 6=sacre ; 7=terre ; 8=vent
int bonusCase[5][5];
int mainJoueur1[2][5];
int mainJoueur2[2][5];
int idCarteInit[10];
int scoreJoueur;
int scoreWifi[2];
bool carteJouee[2][5];
bool cartePrise[2][5];

bool wifiActive=false;
int choixPersoWifi;
int persoAdvWifi;
int wifiOn=0;
int etapeWifi=0;
int etape=0;
int choixFinWifi=0;
bool reponseWifi=false;
bool allowChoixPerso=false;
bool effacementPersoWifi=false;
bool affichagePersoWifi=false;
int afficherNomWifiId=0;
int idUserWifi=0;
unsigned char bitmap[48][96];
unsigned char bitmapWifi[10][48][96];

int distanceArretCarte=0;
int yInitCarte=0;

/* AFFICHAGE DES CARTES DE L'ADVERSAIRE EN MODE WIFI */

bool choixCarteWifi=false;
bool enleverCarteWifi[5];
bool ajouterCarteWifi[5];
int yActuelWifi[5];
int yFinalWifi[5];
int vitesseWifi[5];

int tourWifi;
int carteWifi;
int zoneWifi;
int nombreCarteAfficheWifi;
bool carteJoueeWifi;
int nouvelleIdCarteInitWifi[10];
int mainJWifi[2];

const int persoDebloqueInit = 1;
const int nombreNouvellesCartes = 7;	// Ne surtout pas dépasser 22 !
const int chanceNouveauLvl2 = 3;
const int chanceElementCase = 4;
const int vitesseCarte = 5;
const int vitesseAfficherCarte = 10;
const int vitesseRotationFleche = 64;
const int vitesseFleche = 50;
const int tourFleche = 7;
const int timerCurseur1 = 30;
const int timerCurseur2 = 3;
const int vitessePerso = 32;
const int framesEntreDeuxCartes = 16;
const int frameDeplacementFleche = 3;
const int maxUserwifi = 10;

bool sauvegarde = true;		// Permet de sauvgarder (utile à désactiver si la sauvegarde n'a pas été chargée)
bool musique = true;

unsigned short * bgBitmap[2];
char * carte_gfx[2][11];
char * carte_pal[2][11];
char * carteG3D_tex;
char id_music[8];
u8 * musique_buffer;
s16 carte3D_gfx[10];
s16 element_gfx[9];
s16 bonus_gfx[9];
s16 carteG3D_gfx;
s16 carteG_gfx;
s16 brille_gfx;

extern FILE *nds_file;// on pointe vers le fichier

bool cartePriseExiste() {
	int i,j;
	for (i=0;i<5;i++) {
		for (j=0;j<2;j++) {
			if (cartePrise[j][i]) {
				return true;
			}
		}
	}
	return false;
}

int getNombreCarte(int mode,int niveauMin,int niveauMax) {
	int retour=0;
	int i;
	
	for (i=11*(niveauMin-1)+1;i<=11*niveauMax;i++) {
		retour += (mode) ? collection[i] : (collection[i] > 0);
	}
	return retour;
}

int getNombreVictoires(int mode) {
	int i;
	int retour=0;
	for (i=0;i<12;i++) {
		retour += victoires[i][mode];
	}
	return retour;
}

int getCaseX(int id) {
	int i,j;
	for (i=0;i<3;i++) {
		for (j=0;j<3;j++) {
			if (idCarte[j+1][i+1] == id) {
				return j;
			}
		}
	}
	return -1;
}

int getCaseY(int id) {
	int i,j;
	for (i=0;i<3;i++) {
		for (j=0;j<3;j++) {
			if (idCarte[j+1][i+1] == id) {
				return i;
			}
		}
	}
	return -1;
}

bool sauvegarder() {   
	if (sauvegarde) {
 		FILE* fichier = NULL;
 
		fichier = fopen("fat:/TripleTriad.sav", "wb"); // On ouvre le fichier : Attention, le fichier ne doit pas être à 0 sinon ca plante! Faire un fichier de 100 kilo pour être tranquile ^^
 
		//Si l'ouverture a fonctionnée
		if (fichier != NULL) {
		
			int lengthSave = 1659;
		
			char nombreFile[lengthSave];
			
			sprintf(nombreFile, "1 %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %01d %01d %01d %01d %01d %01d %01d %01d %02d %02d %02d ",
						collection[1],collection[2],collection[3],collection[4],collection[5],collection[6],collection[7],collection[8],collection[9],collection[10],collection[11],collection[12],collection[13],collection[14],collection[15],collection[16],collection[17],collection[18],collection[19],collection[20],collection[21],collection[22],collection[23],collection[24],collection[25],collection[26],collection[27],collection[28],collection[29],collection[30],collection[31],collection[32],collection[33],collection[34],collection[35],collection[36],collection[37],collection[38],collection[39],collection[40],collection[41],collection[42],collection[43],collection[44],collection[45],collection[46],collection[47],collection[48],collection[49],collection[50],collection[51],collection[52],collection[53],collection[54],collection[55],collection[56],collection[57],collection[58],collection[59],collection[60],collection[61],collection[62],collection[63],collection[64],collection[65],collection[66],collection[67],collection[68],collection[69],collection[70],collection[71],collection[72],collection[73],collection[74],collection[75],collection[76],collection[77],collection[78],collection[79],collection[80],collection[81],collection[82],collection[83],collection[84],collection[85],collection[86],collection[87],collection[88],collection[89],collection[90],collection[91],collection[92],collection[93],collection[94],collection[95],collection[96],collection[97],collection[98],collection[99],collection[100],collection[101],collection[102],collection[103],collection[104],collection[105],collection[106],collection[107],collection[108],collection[109],collection[110],
						historique[1],historique[2],historique[3],historique[4],historique[5],historique[6],historique[7],historique[8],historique[9],historique[10],historique[11],historique[12],historique[13],historique[14],historique[15],historique[16],historique[17],historique[18],historique[19],historique[20],historique[21],historique[22],historique[23],historique[24],historique[25],historique[26],historique[27],historique[28],historique[29],historique[30],historique[31],historique[32],historique[33],historique[34],historique[35],historique[36],historique[37],historique[38],historique[39],historique[40],historique[41],historique[42],historique[43],historique[44],historique[45],historique[46],historique[47],historique[48],historique[49],historique[50],historique[51],historique[52],historique[53],historique[54],historique[55],historique[56],historique[57],historique[58],historique[59],historique[60],historique[61],historique[62],historique[63],historique[64],historique[65],historique[66],historique[67],historique[68],historique[69],historique[70],historique[71],historique[72],historique[73],historique[74],historique[75],historique[76],historique[77],historique[78],historique[79],historique[80],historique[81],historique[82],historique[83],historique[84],historique[85],historique[86],historique[87],historique[88],historique[89],historique[90],historique[91],historique[92],historique[93],historique[94],historique[95],historique[96],historique[97],historique[98],historique[99],historique[100],historique[101],historique[102],historique[103],historique[104],historique[105],historique[106],historique[107],historique[108],historique[109],historique[110],
						cartesRares[0][0],cartesRares[0][1],cartesRares[0][2],cartesRares[0][3],cartesRares[0][4],cartesRares[0][5],cartesRares[0][6],cartesRares[0][7],cartesRares[0][8],cartesRares[0][9],cartesRares[0][10],cartesRares[0][11],cartesRares[0][12],cartesRares[0][13],cartesRares[0][14],cartesRares[0][15],cartesRares[0][16],cartesRares[0][17],cartesRares[0][18],cartesRares[0][19],cartesRares[0][20],cartesRares[0][21],cartesRares[0][22],cartesRares[0][23],cartesRares[0][24],cartesRares[0][25],cartesRares[0][26],cartesRares[0][27],cartesRares[0][28],cartesRares[0][29],cartesRares[0][30],cartesRares[0][31],cartesRares[0][32],
						cartesRares[1][0],cartesRares[1][1],cartesRares[1][2],cartesRares[1][3],cartesRares[1][4],cartesRares[1][5],cartesRares[1][6],cartesRares[1][7],cartesRares[1][8],cartesRares[1][9],cartesRares[1][10],cartesRares[1][11],cartesRares[1][12],cartesRares[1][13],cartesRares[1][14],cartesRares[1][15],cartesRares[1][16],cartesRares[1][17],cartesRares[1][18],cartesRares[1][19],cartesRares[1][20],cartesRares[1][21],cartesRares[1][22],cartesRares[1][23],cartesRares[1][24],cartesRares[1][25],cartesRares[1][26],cartesRares[1][27],cartesRares[1][28],cartesRares[1][29],cartesRares[1][30],cartesRares[1][31],cartesRares[1][32],
						cartesRares[2][0],cartesRares[2][1],cartesRares[2][2],cartesRares[2][3],cartesRares[2][4],cartesRares[2][5],cartesRares[2][6],cartesRares[2][7],cartesRares[2][8],cartesRares[2][9],cartesRares[2][10],cartesRares[2][11],cartesRares[2][12],cartesRares[2][13],cartesRares[2][14],cartesRares[2][15],cartesRares[2][16],cartesRares[2][17],cartesRares[2][18],cartesRares[2][19],cartesRares[2][20],cartesRares[2][21],cartesRares[2][22],cartesRares[2][23],cartesRares[2][24],cartesRares[2][25],cartesRares[2][26],cartesRares[2][27],cartesRares[2][28],cartesRares[2][29],cartesRares[2][30],cartesRares[2][31],cartesRares[2][32],
						cartesRares[3][0],cartesRares[3][1],cartesRares[3][2],cartesRares[3][3],cartesRares[3][4],cartesRares[3][5],cartesRares[3][6],cartesRares[3][7],cartesRares[3][8],cartesRares[3][9],cartesRares[3][10],cartesRares[3][11],cartesRares[3][12],cartesRares[3][13],cartesRares[3][14],cartesRares[3][15],cartesRares[3][16],cartesRares[3][17],cartesRares[3][18],cartesRares[3][19],cartesRares[3][20],cartesRares[3][21],cartesRares[3][22],cartesRares[3][23],cartesRares[3][24],cartesRares[3][25],cartesRares[3][26],cartesRares[3][27],cartesRares[3][28],cartesRares[3][29],cartesRares[3][30],cartesRares[3][31],cartesRares[3][32],
						cartesRares[4][0],cartesRares[4][1],cartesRares[4][2],cartesRares[4][3],cartesRares[4][4],cartesRares[4][5],cartesRares[4][6],cartesRares[4][7],cartesRares[4][8],cartesRares[4][9],cartesRares[4][10],cartesRares[4][11],cartesRares[4][12],cartesRares[4][13],cartesRares[4][14],cartesRares[4][15],cartesRares[4][16],cartesRares[4][17],cartesRares[4][18],cartesRares[4][19],cartesRares[4][20],cartesRares[4][21],cartesRares[4][22],cartesRares[4][23],cartesRares[4][24],cartesRares[4][25],cartesRares[4][26],cartesRares[4][27],cartesRares[4][28],cartesRares[4][29],cartesRares[4][30],cartesRares[4][31],cartesRares[4][32],
						cartesRares[5][0],cartesRares[5][1],cartesRares[5][2],cartesRares[5][3],cartesRares[5][4],cartesRares[5][5],cartesRares[5][6],cartesRares[5][7],cartesRares[5][8],cartesRares[5][9],cartesRares[5][10],cartesRares[5][11],cartesRares[5][12],cartesRares[5][13],cartesRares[5][14],cartesRares[5][15],cartesRares[5][16],cartesRares[5][17],cartesRares[5][18],cartesRares[5][19],cartesRares[5][20],cartesRares[5][21],cartesRares[5][22],cartesRares[5][23],cartesRares[5][24],cartesRares[5][25],cartesRares[5][26],cartesRares[5][27],cartesRares[5][28],cartesRares[5][29],cartesRares[5][30],cartesRares[5][31],cartesRares[5][32],
						cartesRares[6][0],cartesRares[6][1],cartesRares[6][2],cartesRares[6][3],cartesRares[6][4],cartesRares[6][5],cartesRares[6][6],cartesRares[6][7],cartesRares[6][8],cartesRares[6][9],cartesRares[6][10],cartesRares[6][11],cartesRares[6][12],cartesRares[6][13],cartesRares[6][14],cartesRares[6][15],cartesRares[6][16],cartesRares[6][17],cartesRares[6][18],cartesRares[6][19],cartesRares[6][20],cartesRares[6][21],cartesRares[6][22],cartesRares[6][23],cartesRares[6][24],cartesRares[6][25],cartesRares[6][26],cartesRares[6][27],cartesRares[6][28],cartesRares[6][29],cartesRares[6][30],cartesRares[6][31],cartesRares[6][32],
						cartesRares[7][0],cartesRares[7][1],cartesRares[7][2],cartesRares[7][3],cartesRares[7][4],cartesRares[7][5],cartesRares[7][6],cartesRares[7][7],cartesRares[7][8],cartesRares[7][9],cartesRares[7][10],cartesRares[7][11],cartesRares[7][12],cartesRares[7][13],cartesRares[7][14],cartesRares[7][15],cartesRares[7][16],cartesRares[7][17],cartesRares[7][18],cartesRares[7][19],cartesRares[7][20],cartesRares[7][21],cartesRares[7][22],cartesRares[7][23],cartesRares[7][24],cartesRares[7][25],cartesRares[7][26],cartesRares[7][27],cartesRares[7][28],cartesRares[7][29],cartesRares[7][30],cartesRares[7][31],cartesRares[7][32],
						cartesRares[8][0],cartesRares[8][1],cartesRares[8][2],cartesRares[8][3],cartesRares[8][4],cartesRares[8][5],cartesRares[8][6],cartesRares[8][7],cartesRares[8][8],cartesRares[8][9],cartesRares[8][10],cartesRares[8][11],cartesRares[8][12],cartesRares[8][13],cartesRares[8][14],cartesRares[8][15],cartesRares[8][16],cartesRares[8][17],cartesRares[8][18],cartesRares[8][19],cartesRares[8][20],cartesRares[8][21],cartesRares[8][22],cartesRares[8][23],cartesRares[8][24],cartesRares[8][25],cartesRares[8][26],cartesRares[8][27],cartesRares[8][28],cartesRares[8][29],cartesRares[8][30],cartesRares[8][31],cartesRares[8][32],
						cartesRares[9][0],cartesRares[9][1],cartesRares[9][2],cartesRares[9][3],cartesRares[9][4],cartesRares[9][5],cartesRares[9][6],cartesRares[9][7],cartesRares[9][8],cartesRares[9][9],cartesRares[9][10],cartesRares[9][11],cartesRares[9][12],cartesRares[9][13],cartesRares[9][14],cartesRares[9][15],cartesRares[9][16],cartesRares[9][17],cartesRares[9][18],cartesRares[9][19],cartesRares[9][20],cartesRares[9][21],cartesRares[9][22],cartesRares[9][23],cartesRares[9][24],cartesRares[9][25],cartesRares[9][26],cartesRares[9][27],cartesRares[9][28],cartesRares[9][29],cartesRares[9][30],cartesRares[9][31],cartesRares[9][32],
						cartesRares[10][0],cartesRares[10][1],cartesRares[10][2],cartesRares[10][3],cartesRares[10][4],cartesRares[10][5],cartesRares[10][6],cartesRares[10][7],cartesRares[10][8],cartesRares[10][9],cartesRares[10][10],cartesRares[10][11],cartesRares[10][12],cartesRares[10][13],cartesRares[10][14],cartesRares[10][15],cartesRares[10][16],cartesRares[10][17],cartesRares[10][18],cartesRares[10][19],cartesRares[10][20],cartesRares[10][21],cartesRares[10][22],cartesRares[10][23],cartesRares[10][24],cartesRares[10][25],cartesRares[10][26],cartesRares[10][27],cartesRares[10][28],cartesRares[10][29],cartesRares[10][30],cartesRares[10][31],cartesRares[10][32],
						cartesRares[11][0],cartesRares[11][1],cartesRares[11][2],cartesRares[11][3],cartesRares[11][4],cartesRares[11][5],cartesRares[11][6],cartesRares[11][7],cartesRares[11][8],cartesRares[11][9],cartesRares[11][10],cartesRares[11][11],cartesRares[11][12],cartesRares[11][13],cartesRares[11][14],cartesRares[11][15],cartesRares[11][16],cartesRares[11][17],cartesRares[11][18],cartesRares[11][19],cartesRares[11][20],cartesRares[11][21],cartesRares[11][22],cartesRares[11][23],cartesRares[11][24],cartesRares[11][25],cartesRares[11][26],cartesRares[11][27],cartesRares[11][28],cartesRares[11][29],cartesRares[11][30],cartesRares[11][31],cartesRares[11][32],
						victoires[0][0],victoires[0][1],victoires[0][2],victoires[1][0],victoires[1][1],victoires[1][2],victoires[2][0],victoires[2][1],victoires[2][2],victoires[3][0],victoires[3][1],victoires[3][2],victoires[4][0],victoires[4][1],victoires[4][2],victoires[5][0],victoires[5][1],victoires[5][2],victoires[6][0],victoires[6][1],victoires[6][2],victoires[7][0],victoires[7][1],victoires[7][2],victoires[8][0],victoires[8][1],victoires[8][2],victoires[9][0],victoires[9][1],victoires[9][2],victoires[10][0],victoires[10][1],victoires[10][2],victoires[11][0],victoires[11][1],victoires[11][2],
						reglePerso[0],reglePerso[1],reglePerso[2],reglePerso[3],reglePerso[4],reglePerso[5],reglePerso[6],reglePerso[7],
						persoDebloque,dernierAdversaire,choixPersoWifi
			);
			
			
			
			fwrite(nombreFile,lengthSave,1,fichier);
			fclose(fichier); // On ferme le fichier
			return true;
		}
		// Si l'ouverture n'a pas fonctionné
		return false;
	}
	return false;
}

void nouvelleSauv() {

	int i,j;
	int min,max;
	
	// On efface tout
	for (i=0;i<111;i++) {
		collection[i] = (int)0;
		historique[i] = (int)0;
	}

	// On donne n cartes de niveau 1 ou 2 sans doublon
	int nouveau[nombreNouvellesCartes];
	bool doublon;
	for (i=0;i<nombreNouvellesCartes;i++) {
		if (PA_RandMax(chanceNouveauLvl2) == 0) {	// Carte niveau 2
			min = 12;
			max = 22;
		}
		else {										// Carte niveau 1
			min = 1;
			max = 11;
		}
		do {
			doublon = false;
			nouveau[i] = PA_RandMinMax(min,max);
			for (j=0;j<i;j++) {
				if (nouveau[j] == nouveau[i]) {
					doublon = true;
				}
			}
		}
		while (doublon);
		
		collection[nouveau[i]]++;
		historique[nouveau[i]] = 1;
	}
	persoDebloque = persoDebloqueInit;
	dernierAdversaire = 0;
	choixPersoWifi = 0;
	for (i=0;i<12;i++) {
		for (j=0;j<33;j++) {
			cartesRares[i][j] = cartesRaresInit[i][j];
		}
		for (j=0;j<3;j++) {
			victoires[i][j] = 0;
		}
	}
	for (i=0;i<8;i++) {
		reglePerso[i] = 0;
	}
}

bool charger() {	
	FILE *fichier = NULL;
	fichier = fopen("fat:/TripleTriad.sav", "rb"); //On ouvre le fichier

	//Si l'ouverture a fonctionnée
	if (fichier != NULL)
	{
		//int nombreFile[653];

		int temp=0;
		
		fscanf(fichier, "%01d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %03d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %01d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %04d %01d %01d %01d %01d %01d %01d %01d %01d %02d %02d %02d ",
					&temp,
					&collection[1],&collection[2],&collection[3],&collection[4],&collection[5],&collection[6],&collection[7],&collection[8],&collection[9],&collection[10],&collection[11],&collection[12],&collection[13],&collection[14],&collection[15],&collection[16],&collection[17],&collection[18],&collection[19],&collection[20],&collection[21],&collection[22],&collection[23],&collection[24],&collection[25],&collection[26],&collection[27],&collection[28],&collection[29],&collection[30],&collection[31],&collection[32],&collection[33],&collection[34],&collection[35],&collection[36],&collection[37],&collection[38],&collection[39],&collection[40],&collection[41],&collection[42],&collection[43],&collection[44],&collection[45],&collection[46],&collection[47],&collection[48],&collection[49],&collection[50],&collection[51],&collection[52],&collection[53],&collection[54],&collection[55],&collection[56],&collection[57],&collection[58],&collection[59],&collection[60],&collection[61],&collection[62],&collection[63],&collection[64],&collection[65],&collection[66],&collection[67],&collection[68],&collection[69],&collection[70],&collection[71],&collection[72],&collection[73],&collection[74],&collection[75],&collection[76],&collection[77],&collection[78],&collection[79],&collection[80],&collection[81],&collection[82],&collection[83],&collection[84],&collection[85],&collection[86],&collection[87],&collection[88],&collection[89],&collection[90],&collection[91],&collection[92],&collection[93],&collection[94],&collection[95],&collection[96],&collection[97],&collection[98],&collection[99],&collection[100],&collection[101],&collection[102],&collection[103],&collection[104],&collection[105],&collection[106],&collection[107],&collection[108],&collection[109],&collection[110],
					&historique[1],&historique[2],&historique[3],&historique[4],&historique[5],&historique[6],&historique[7],&historique[8],&historique[9],&historique[10],&historique[11],&historique[12],&historique[13],&historique[14],&historique[15],&historique[16],&historique[17],&historique[18],&historique[19],&historique[20],&historique[21],&historique[22],&historique[23],&historique[24],&historique[25],&historique[26],&historique[27],&historique[28],&historique[29],&historique[30],&historique[31],&historique[32],&historique[33],&historique[34],&historique[35],&historique[36],&historique[37],&historique[38],&historique[39],&historique[40],&historique[41],&historique[42],&historique[43],&historique[44],&historique[45],&historique[46],&historique[47],&historique[48],&historique[49],&historique[50],&historique[51],&historique[52],&historique[53],&historique[54],&historique[55],&historique[56],&historique[57],&historique[58],&historique[59],&historique[60],&historique[61],&historique[62],&historique[63],&historique[64],&historique[65],&historique[66],&historique[67],&historique[68],&historique[69],&historique[70],&historique[71],&historique[72],&historique[73],&historique[74],&historique[75],&historique[76],&historique[77],&historique[78],&historique[79],&historique[80],&historique[81],&historique[82],&historique[83],&historique[84],&historique[85],&historique[86],&historique[87],&historique[88],&historique[89],&historique[90],&historique[91],&historique[92],&historique[93],&historique[94],&historique[95],&historique[96],&historique[97],&historique[98],&historique[99],&historique[100],&historique[101],&historique[102],&historique[103],&historique[104],&historique[105],&historique[106],&historique[107],&historique[108],&historique[109],&historique[110],
					&cartesRares[0][0],&cartesRares[0][1],&cartesRares[0][2],&cartesRares[0][3],&cartesRares[0][4],&cartesRares[0][5],&cartesRares[0][6],&cartesRares[0][7],&cartesRares[0][8],&cartesRares[0][9],&cartesRares[0][10],&cartesRares[0][11],&cartesRares[0][12],&cartesRares[0][13],&cartesRares[0][14],&cartesRares[0][15],&cartesRares[0][16],&cartesRares[0][17],&cartesRares[0][18],&cartesRares[0][19],&cartesRares[0][20],&cartesRares[0][21],&cartesRares[0][22],&cartesRares[0][23],&cartesRares[0][24],&cartesRares[0][25],&cartesRares[0][26],&cartesRares[0][27],&cartesRares[0][28],&cartesRares[0][29],&cartesRares[0][30],&cartesRares[0][31],&cartesRares[0][32],
					&cartesRares[1][0],&cartesRares[1][1],&cartesRares[1][2],&cartesRares[1][3],&cartesRares[1][4],&cartesRares[1][5],&cartesRares[1][6],&cartesRares[1][7],&cartesRares[1][8],&cartesRares[1][9],&cartesRares[1][10],&cartesRares[1][11],&cartesRares[1][12],&cartesRares[1][13],&cartesRares[1][14],&cartesRares[1][15],&cartesRares[1][16],&cartesRares[1][17],&cartesRares[1][18],&cartesRares[1][19],&cartesRares[1][20],&cartesRares[1][21],&cartesRares[1][22],&cartesRares[1][23],&cartesRares[1][24],&cartesRares[1][25],&cartesRares[1][26],&cartesRares[1][27],&cartesRares[1][28],&cartesRares[1][29],&cartesRares[1][30],&cartesRares[1][31],&cartesRares[1][32],
					&cartesRares[2][0],&cartesRares[2][1],&cartesRares[2][2],&cartesRares[2][3],&cartesRares[2][4],&cartesRares[2][5],&cartesRares[2][6],&cartesRares[2][7],&cartesRares[2][8],&cartesRares[2][9],&cartesRares[2][10],&cartesRares[2][11],&cartesRares[2][12],&cartesRares[2][13],&cartesRares[2][14],&cartesRares[2][15],&cartesRares[2][16],&cartesRares[2][17],&cartesRares[2][18],&cartesRares[2][19],&cartesRares[2][20],&cartesRares[2][21],&cartesRares[2][22],&cartesRares[2][23],&cartesRares[2][24],&cartesRares[2][25],&cartesRares[2][26],&cartesRares[2][27],&cartesRares[2][28],&cartesRares[2][29],&cartesRares[2][30],&cartesRares[2][31],&cartesRares[2][32],
					&cartesRares[3][0],&cartesRares[3][1],&cartesRares[3][2],&cartesRares[3][3],&cartesRares[3][4],&cartesRares[3][5],&cartesRares[3][6],&cartesRares[3][7],&cartesRares[3][8],&cartesRares[3][9],&cartesRares[3][10],&cartesRares[3][11],&cartesRares[3][12],&cartesRares[3][13],&cartesRares[3][14],&cartesRares[3][15],&cartesRares[3][16],&cartesRares[3][17],&cartesRares[3][18],&cartesRares[3][19],&cartesRares[3][20],&cartesRares[3][21],&cartesRares[3][22],&cartesRares[3][23],&cartesRares[3][24],&cartesRares[3][25],&cartesRares[3][26],&cartesRares[3][27],&cartesRares[3][28],&cartesRares[3][29],&cartesRares[3][30],&cartesRares[3][31],&cartesRares[3][32],
					&cartesRares[4][0],&cartesRares[4][1],&cartesRares[4][2],&cartesRares[4][3],&cartesRares[4][4],&cartesRares[4][5],&cartesRares[4][6],&cartesRares[4][7],&cartesRares[4][8],&cartesRares[4][9],&cartesRares[4][10],&cartesRares[4][11],&cartesRares[4][12],&cartesRares[4][13],&cartesRares[4][14],&cartesRares[4][15],&cartesRares[4][16],&cartesRares[4][17],&cartesRares[4][18],&cartesRares[4][19],&cartesRares[4][20],&cartesRares[4][21],&cartesRares[4][22],&cartesRares[4][23],&cartesRares[4][24],&cartesRares[4][25],&cartesRares[4][26],&cartesRares[4][27],&cartesRares[4][28],&cartesRares[4][29],&cartesRares[4][30],&cartesRares[4][31],&cartesRares[4][32],
					&cartesRares[5][0],&cartesRares[5][1],&cartesRares[5][2],&cartesRares[5][3],&cartesRares[5][4],&cartesRares[5][5],&cartesRares[5][6],&cartesRares[5][7],&cartesRares[5][8],&cartesRares[5][9],&cartesRares[5][10],&cartesRares[5][11],&cartesRares[5][12],&cartesRares[5][13],&cartesRares[5][14],&cartesRares[5][15],&cartesRares[5][16],&cartesRares[5][17],&cartesRares[5][18],&cartesRares[5][19],&cartesRares[5][20],&cartesRares[5][21],&cartesRares[5][22],&cartesRares[5][23],&cartesRares[5][24],&cartesRares[5][25],&cartesRares[5][26],&cartesRares[5][27],&cartesRares[5][28],&cartesRares[5][29],&cartesRares[5][30],&cartesRares[5][31],&cartesRares[5][32],
					&cartesRares[6][0],&cartesRares[6][1],&cartesRares[6][2],&cartesRares[6][3],&cartesRares[6][4],&cartesRares[6][5],&cartesRares[6][6],&cartesRares[6][7],&cartesRares[6][8],&cartesRares[6][9],&cartesRares[6][10],&cartesRares[6][11],&cartesRares[6][12],&cartesRares[6][13],&cartesRares[6][14],&cartesRares[6][15],&cartesRares[6][16],&cartesRares[6][17],&cartesRares[6][18],&cartesRares[6][19],&cartesRares[6][20],&cartesRares[6][21],&cartesRares[6][22],&cartesRares[6][23],&cartesRares[6][24],&cartesRares[6][25],&cartesRares[6][26],&cartesRares[6][27],&cartesRares[6][28],&cartesRares[6][29],&cartesRares[6][30],&cartesRares[6][31],&cartesRares[6][32],
					&cartesRares[7][0],&cartesRares[7][1],&cartesRares[7][2],&cartesRares[7][3],&cartesRares[7][4],&cartesRares[7][5],&cartesRares[7][6],&cartesRares[7][7],&cartesRares[7][8],&cartesRares[7][9],&cartesRares[7][10],&cartesRares[7][11],&cartesRares[7][12],&cartesRares[7][13],&cartesRares[7][14],&cartesRares[7][15],&cartesRares[7][16],&cartesRares[7][17],&cartesRares[7][18],&cartesRares[7][19],&cartesRares[7][20],&cartesRares[7][21],&cartesRares[7][22],&cartesRares[7][23],&cartesRares[7][24],&cartesRares[7][25],&cartesRares[7][26],&cartesRares[7][27],&cartesRares[7][28],&cartesRares[7][29],&cartesRares[7][30],&cartesRares[7][31],&cartesRares[7][32],
					&cartesRares[8][0],&cartesRares[8][1],&cartesRares[8][2],&cartesRares[8][3],&cartesRares[8][4],&cartesRares[8][5],&cartesRares[8][6],&cartesRares[8][7],&cartesRares[8][8],&cartesRares[8][9],&cartesRares[8][10],&cartesRares[8][11],&cartesRares[8][12],&cartesRares[8][13],&cartesRares[8][14],&cartesRares[8][15],&cartesRares[8][16],&cartesRares[8][17],&cartesRares[8][18],&cartesRares[8][19],&cartesRares[8][20],&cartesRares[8][21],&cartesRares[8][22],&cartesRares[8][23],&cartesRares[8][24],&cartesRares[8][25],&cartesRares[8][26],&cartesRares[8][27],&cartesRares[8][28],&cartesRares[8][29],&cartesRares[8][30],&cartesRares[8][31],&cartesRares[8][32],
					&cartesRares[9][0],&cartesRares[9][1],&cartesRares[9][2],&cartesRares[9][3],&cartesRares[9][4],&cartesRares[9][5],&cartesRares[9][6],&cartesRares[9][7],&cartesRares[9][8],&cartesRares[9][9],&cartesRares[9][10],&cartesRares[9][11],&cartesRares[9][12],&cartesRares[9][13],&cartesRares[9][14],&cartesRares[9][15],&cartesRares[9][16],&cartesRares[9][17],&cartesRares[9][18],&cartesRares[9][19],&cartesRares[9][20],&cartesRares[9][21],&cartesRares[9][22],&cartesRares[9][23],&cartesRares[9][24],&cartesRares[9][25],&cartesRares[9][26],&cartesRares[9][27],&cartesRares[9][28],&cartesRares[9][29],&cartesRares[9][30],&cartesRares[9][31],&cartesRares[9][32],
					&cartesRares[10][0],&cartesRares[10][1],&cartesRares[10][2],&cartesRares[10][3],&cartesRares[10][4],&cartesRares[10][5],&cartesRares[10][6],&cartesRares[10][7],&cartesRares[10][8],&cartesRares[10][9],&cartesRares[10][10],&cartesRares[10][11],&cartesRares[10][12],&cartesRares[10][13],&cartesRares[10][14],&cartesRares[10][15],&cartesRares[10][16],&cartesRares[10][17],&cartesRares[10][18],&cartesRares[10][19],&cartesRares[10][20],&cartesRares[10][21],&cartesRares[10][22],&cartesRares[10][23],&cartesRares[10][24],&cartesRares[10][25],&cartesRares[10][26],&cartesRares[10][27],&cartesRares[10][28],&cartesRares[10][29],&cartesRares[10][30],&cartesRares[10][31],&cartesRares[10][32],
					&cartesRares[11][0],&cartesRares[11][1],&cartesRares[11][2],&cartesRares[11][3],&cartesRares[11][4],&cartesRares[11][5],&cartesRares[11][6],&cartesRares[11][7],&cartesRares[11][8],&cartesRares[11][9],&cartesRares[11][10],&cartesRares[11][11],&cartesRares[11][12],&cartesRares[11][13],&cartesRares[11][14],&cartesRares[11][15],&cartesRares[11][16],&cartesRares[11][17],&cartesRares[11][18],&cartesRares[11][19],&cartesRares[11][20],&cartesRares[11][21],&cartesRares[11][22],&cartesRares[11][23],&cartesRares[11][24],&cartesRares[11][25],&cartesRares[11][26],&cartesRares[11][27],&cartesRares[11][28],&cartesRares[11][29],&cartesRares[11][30],&cartesRares[11][31],&cartesRares[11][32],
					&victoires[0][0],&victoires[0][1],&victoires[0][2],&victoires[1][0],&victoires[1][1],&victoires[1][2],&victoires[2][0],&victoires[2][1],&victoires[2][2],&victoires[3][0],&victoires[3][1],&victoires[3][2],&victoires[4][0],&victoires[4][1],&victoires[4][2],&victoires[5][0],&victoires[5][1],&victoires[5][2],&victoires[6][0],&victoires[6][1],&victoires[6][2],&victoires[7][0],&victoires[7][1],&victoires[7][2],&victoires[8][0],&victoires[8][1],&victoires[8][2],&victoires[9][0],&victoires[9][1],&victoires[9][2],&victoires[10][0],&victoires[10][1],&victoires[10][2],&victoires[11][0],&victoires[11][1],&victoires[11][2],
					&reglePerso[0],&reglePerso[1],&reglePerso[2],&reglePerso[3],&reglePerso[4],&reglePerso[5],&reglePerso[6],&reglePerso[7],
					&persoDebloque,&dernierAdversaire,&choixPersoWifi
		);
		
		fclose(fichier); //On ferme le fichier
		
		if (temp == 0) {
			nouvelleSauv();
			sauvegarder();
		}
		return true;
	}
	//Si l'ouverture n'a pas fonctionnée
	return false;
}

bool sauvegarderBitmap(int sauv) {
	if (sauvegarde) {
 		FILE* fichier = NULL;
		
		fichier = fopen("fat:/BitmapWifi.sav"); // On ouvre le fichier : Attention, le fichier ne doit pas être à 0 sinon ca plante! Faire un fichier de 100 kilo pour être tranquile ^^
		
		//Si l'ouverture a fonctionnée
		if (fichier != NULL) {
			
			int lengthSave = 4611;
			char enregistrement[lengthSave];
			sprintf(enregistrement,"%01d %s ",sauv,bitmap);
			/*sprintf(enregistrement, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s ",
					bitmap[0],bitmap[1],bitmap[2],bitmap[3],bitmap[4],bitmap[5],bitmap[6],bitmap[7],bitmap[8],bitmap[9],bitmap[10],bitmap[11],bitmap[12],bitmap[13],bitmap[14],bitmap[15],bitmap[16],bitmap[17],bitmap[18],bitmap[19],bitmap[20],bitmap[21],bitmap[22],bitmap[23],bitmap[24],bitmap[25],bitmap[26],bitmap[27],bitmap[28],bitmap[29],bitmap[30],bitmap[31],bitmap[32],bitmap[33],bitmap[34],bitmap[35],bitmap[36],bitmap[37],bitmap[38],bitmap[39],bitmap[40],bitmap[41],bitmap[42],bitmap[43],bitmap[44],bitmap[45],bitmap[46],bitmap[47]
			);*/
			
			/*sprintf(enregistrement, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c ",
					bitmap[0][0],bitmap[0][1],bitmap[0][2],bitmap[0][3],bitmap[0][4],bitmap[0][5],bitmap[0][6],bitmap[0][7],bitmap[0][8],bitmap[0][9],bitmap[0][10],bitmap[0][11],bitmap[0][12],bitmap[0][13],bitmap[0][14],bitmap[0][15],bitmap[0][16],bitmap[0][17],bitmap[0][18],bitmap[0][19],bitmap[0][20],bitmap[0][21],bitmap[0][22],bitmap[0][23],bitmap[0][24],bitmap[0][25],bitmap[0][26],bitmap[0][27],bitmap[0][28],bitmap[0][29],bitmap[0][30],bitmap[0][31],bitmap[0][32],bitmap[0][33],bitmap[0][34],bitmap[0][35],bitmap[0][36],bitmap[0][37],bitmap[0][38],bitmap[0][39],bitmap[0][40],bitmap[0][41],bitmap[0][42],bitmap[0][43],bitmap[0][44],bitmap[0][45],bitmap[0][46],bitmap[0][47],bitmap[0][48],bitmap[0][49],bitmap[0][50],bitmap[0][51],bitmap[0][52],bitmap[0][53],bitmap[0][54],bitmap[0][55],bitmap[0][56],bitmap[0][57],bitmap[0][58],bitmap[0][59],bitmap[0][60],bitmap[0][61],bitmap[0][62],bitmap[0][63],bitmap[0][64],bitmap[0][65],bitmap[0][66],bitmap[0][67],bitmap[0][68],bitmap[0][69],bitmap[0][70],bitmap[0][71],bitmap[0][72],bitmap[0][73],bitmap[0][74],bitmap[0][75],bitmap[0][76],bitmap[0][77],bitmap[0][78],bitmap[0][79],bitmap[0][80],bitmap[0][81],bitmap[0][82],bitmap[0][83],bitmap[0][84],bitmap[0][85],bitmap[0][86],bitmap[0][87],bitmap[0][88],bitmap[0][89],bitmap[0][90],bitmap[0][91],bitmap[0][92],bitmap[0][93],bitmap[0][94],bitmap[0][95],
					bitmap[1][0],bitmap[1][1],bitmap[1][2],bitmap[1][3],bitmap[1][4],bitmap[1][5],bitmap[1][6],bitmap[1][7],bitmap[1][8],bitmap[1][9],bitmap[1][10],bitmap[1][11],bitmap[1][12],bitmap[1][13],bitmap[1][14],bitmap[1][15],bitmap[1][16],bitmap[1][17],bitmap[1][18],bitmap[1][19],bitmap[1][20],bitmap[1][21],bitmap[1][22],bitmap[1][23],bitmap[1][24],bitmap[1][25],bitmap[1][26],bitmap[1][27],bitmap[1][28],bitmap[1][29],bitmap[1][30],bitmap[1][31],bitmap[1][32],bitmap[1][33],bitmap[1][34],bitmap[1][35],bitmap[1][36],bitmap[1][37],bitmap[1][38],bitmap[1][39],bitmap[1][40],bitmap[1][41],bitmap[1][42],bitmap[1][43],bitmap[1][44],bitmap[1][45],bitmap[1][46],bitmap[1][47],bitmap[1][48],bitmap[1][49],bitmap[1][50],bitmap[1][51],bitmap[1][52],bitmap[1][53],bitmap[1][54],bitmap[1][55],bitmap[1][56],bitmap[1][57],bitmap[1][58],bitmap[1][59],bitmap[1][60],bitmap[1][61],bitmap[1][62],bitmap[1][63],bitmap[1][64],bitmap[1][65],bitmap[1][66],bitmap[1][67],bitmap[1][68],bitmap[1][69],bitmap[1][70],bitmap[1][71],bitmap[1][72],bitmap[1][73],bitmap[1][74],bitmap[1][75],bitmap[1][76],bitmap[1][77],bitmap[1][78],bitmap[1][79],bitmap[1][80],bitmap[1][81],bitmap[1][82],bitmap[1][83],bitmap[1][84],bitmap[1][85],bitmap[1][86],bitmap[1][87],bitmap[1][88],bitmap[1][89],bitmap[1][90],bitmap[1][91],bitmap[1][92],bitmap[1][93],bitmap[1][94],bitmap[1][95],
					bitmap[2][0],bitmap[2][1],bitmap[2][2],bitmap[2][3],bitmap[2][4],bitmap[2][5],bitmap[2][6],bitmap[2][7],bitmap[2][8],bitmap[2][9],bitmap[2][10],bitmap[2][11],bitmap[2][12],bitmap[2][13],bitmap[2][14],bitmap[2][15],bitmap[2][16],bitmap[2][17],bitmap[2][18],bitmap[2][19],bitmap[2][20],bitmap[2][21],bitmap[2][22],bitmap[2][23],bitmap[2][24],bitmap[2][25],bitmap[2][26],bitmap[2][27],bitmap[2][28],bitmap[2][29],bitmap[2][30],bitmap[2][31],bitmap[2][32],bitmap[2][33],bitmap[2][34],bitmap[2][35],bitmap[2][36],bitmap[2][37],bitmap[2][38],bitmap[2][39],bitmap[2][40],bitmap[2][41],bitmap[2][42],bitmap[2][43],bitmap[2][44],bitmap[2][45],bitmap[2][46],bitmap[2][47],bitmap[2][48],bitmap[2][49],bitmap[2][50],bitmap[2][51],bitmap[2][52],bitmap[2][53],bitmap[2][54],bitmap[2][55],bitmap[2][56],bitmap[2][57],bitmap[2][58],bitmap[2][59],bitmap[2][60],bitmap[2][61],bitmap[2][62],bitmap[2][63],bitmap[2][64],bitmap[2][65],bitmap[2][66],bitmap[2][67],bitmap[2][68],bitmap[2][69],bitmap[2][70],bitmap[2][71],bitmap[2][72],bitmap[2][73],bitmap[2][74],bitmap[2][75],bitmap[2][76],bitmap[2][77],bitmap[2][78],bitmap[2][79],bitmap[2][80],bitmap[2][81],bitmap[2][82],bitmap[2][83],bitmap[2][84],bitmap[2][85],bitmap[2][86],bitmap[2][87],bitmap[2][88],bitmap[2][89],bitmap[2][90],bitmap[2][91],bitmap[2][92],bitmap[2][93],bitmap[2][94],bitmap[2][95],
					bitmap[3][0],bitmap[3][1],bitmap[3][2],bitmap[3][3],bitmap[3][4],bitmap[3][5],bitmap[3][6],bitmap[3][7],bitmap[3][8],bitmap[3][9],bitmap[3][10],bitmap[3][11],bitmap[3][12],bitmap[3][13],bitmap[3][14],bitmap[3][15],bitmap[3][16],bitmap[3][17],bitmap[3][18],bitmap[3][19],bitmap[3][20],bitmap[3][21],bitmap[3][22],bitmap[3][23],bitmap[3][24],bitmap[3][25],bitmap[3][26],bitmap[3][27],bitmap[3][28],bitmap[3][29],bitmap[3][30],bitmap[3][31],bitmap[3][32],bitmap[3][33],bitmap[3][34],bitmap[3][35],bitmap[3][36],bitmap[3][37],bitmap[3][38],bitmap[3][39],bitmap[3][40],bitmap[3][41],bitmap[3][42],bitmap[3][43],bitmap[3][44],bitmap[3][45],bitmap[3][46],bitmap[3][47],bitmap[3][48],bitmap[3][49],bitmap[3][50],bitmap[3][51],bitmap[3][52],bitmap[3][53],bitmap[3][54],bitmap[3][55],bitmap[3][56],bitmap[3][57],bitmap[3][58],bitmap[3][59],bitmap[3][60],bitmap[3][61],bitmap[3][62],bitmap[3][63],bitmap[3][64],bitmap[3][65],bitmap[3][66],bitmap[3][67],bitmap[3][68],bitmap[3][69],bitmap[3][70],bitmap[3][71],bitmap[3][72],bitmap[3][73],bitmap[3][74],bitmap[3][75],bitmap[3][76],bitmap[3][77],bitmap[3][78],bitmap[3][79],bitmap[3][80],bitmap[3][81],bitmap[3][82],bitmap[3][83],bitmap[3][84],bitmap[3][85],bitmap[3][86],bitmap[3][87],bitmap[3][88],bitmap[3][89],bitmap[3][90],bitmap[3][91],bitmap[3][92],bitmap[3][93],bitmap[3][94],bitmap[3][95],
					bitmap[4][0],bitmap[4][1],bitmap[4][2],bitmap[4][3],bitmap[4][4],bitmap[4][5],bitmap[4][6],bitmap[4][7],bitmap[4][8],bitmap[4][9],bitmap[4][10],bitmap[4][11],bitmap[4][12],bitmap[4][13],bitmap[4][14],bitmap[4][15],bitmap[4][16],bitmap[4][17],bitmap[4][18],bitmap[4][19],bitmap[4][20],bitmap[4][21],bitmap[4][22],bitmap[4][23],bitmap[4][24],bitmap[4][25],bitmap[4][26],bitmap[4][27],bitmap[4][28],bitmap[4][29],bitmap[4][30],bitmap[4][31],bitmap[4][32],bitmap[4][33],bitmap[4][34],bitmap[4][35],bitmap[4][36],bitmap[4][37],bitmap[4][38],bitmap[4][39],bitmap[4][40],bitmap[4][41],bitmap[4][42],bitmap[4][43],bitmap[4][44],bitmap[4][45],bitmap[4][46],bitmap[4][47],bitmap[4][48],bitmap[4][49],bitmap[4][50],bitmap[4][51],bitmap[4][52],bitmap[4][53],bitmap[4][54],bitmap[4][55],bitmap[4][56],bitmap[4][57],bitmap[4][58],bitmap[4][59],bitmap[4][60],bitmap[4][61],bitmap[4][62],bitmap[4][63],bitmap[4][64],bitmap[4][65],bitmap[4][66],bitmap[4][67],bitmap[4][68],bitmap[4][69],bitmap[4][70],bitmap[4][71],bitmap[4][72],bitmap[4][73],bitmap[4][74],bitmap[4][75],bitmap[4][76],bitmap[4][77],bitmap[4][78],bitmap[4][79],bitmap[4][80],bitmap[4][81],bitmap[4][82],bitmap[4][83],bitmap[4][84],bitmap[4][85],bitmap[4][86],bitmap[4][87],bitmap[4][88],bitmap[4][89],bitmap[4][90],bitmap[4][91],bitmap[4][92],bitmap[4][93],bitmap[4][94],bitmap[4][95],
					bitmap[5][0],bitmap[5][1],bitmap[5][2],bitmap[5][3],bitmap[5][4],bitmap[5][5],bitmap[5][6],bitmap[5][7],bitmap[5][8],bitmap[5][9],bitmap[5][10],bitmap[5][11],bitmap[5][12],bitmap[5][13],bitmap[5][14],bitmap[5][15],bitmap[5][16],bitmap[5][17],bitmap[5][18],bitmap[5][19],bitmap[5][20],bitmap[5][21],bitmap[5][22],bitmap[5][23],bitmap[5][24],bitmap[5][25],bitmap[5][26],bitmap[5][27],bitmap[5][28],bitmap[5][29],bitmap[5][30],bitmap[5][31],bitmap[5][32],bitmap[5][33],bitmap[5][34],bitmap[5][35],bitmap[5][36],bitmap[5][37],bitmap[5][38],bitmap[5][39],bitmap[5][40],bitmap[5][41],bitmap[5][42],bitmap[5][43],bitmap[5][44],bitmap[5][45],bitmap[5][46],bitmap[5][47],bitmap[5][48],bitmap[5][49],bitmap[5][50],bitmap[5][51],bitmap[5][52],bitmap[5][53],bitmap[5][54],bitmap[5][55],bitmap[5][56],bitmap[5][57],bitmap[5][58],bitmap[5][59],bitmap[5][60],bitmap[5][61],bitmap[5][62],bitmap[5][63],bitmap[5][64],bitmap[5][65],bitmap[5][66],bitmap[5][67],bitmap[5][68],bitmap[5][69],bitmap[5][70],bitmap[5][71],bitmap[5][72],bitmap[5][73],bitmap[5][74],bitmap[5][75],bitmap[5][76],bitmap[5][77],bitmap[5][78],bitmap[5][79],bitmap[5][80],bitmap[5][81],bitmap[5][82],bitmap[5][83],bitmap[5][84],bitmap[5][85],bitmap[5][86],bitmap[5][87],bitmap[5][88],bitmap[5][89],bitmap[5][90],bitmap[5][91],bitmap[5][92],bitmap[5][93],bitmap[5][94],bitmap[5][95],
					bitmap[6][0],bitmap[6][1],bitmap[6][2],bitmap[6][3],bitmap[6][4],bitmap[6][5],bitmap[6][6],bitmap[6][7],bitmap[6][8],bitmap[6][9],bitmap[6][10],bitmap[6][11],bitmap[6][12],bitmap[6][13],bitmap[6][14],bitmap[6][15],bitmap[6][16],bitmap[6][17],bitmap[6][18],bitmap[6][19],bitmap[6][20],bitmap[6][21],bitmap[6][22],bitmap[6][23],bitmap[6][24],bitmap[6][25],bitmap[6][26],bitmap[6][27],bitmap[6][28],bitmap[6][29],bitmap[6][30],bitmap[6][31],bitmap[6][32],bitmap[6][33],bitmap[6][34],bitmap[6][35],bitmap[6][36],bitmap[6][37],bitmap[6][38],bitmap[6][39],bitmap[6][40],bitmap[6][41],bitmap[6][42],bitmap[6][43],bitmap[6][44],bitmap[6][45],bitmap[6][46],bitmap[6][47],bitmap[6][48],bitmap[6][49],bitmap[6][50],bitmap[6][51],bitmap[6][52],bitmap[6][53],bitmap[6][54],bitmap[6][55],bitmap[6][56],bitmap[6][57],bitmap[6][58],bitmap[6][59],bitmap[6][60],bitmap[6][61],bitmap[6][62],bitmap[6][63],bitmap[6][64],bitmap[6][65],bitmap[6][66],bitmap[6][67],bitmap[6][68],bitmap[6][69],bitmap[6][70],bitmap[6][71],bitmap[6][72],bitmap[6][73],bitmap[6][74],bitmap[6][75],bitmap[6][76],bitmap[6][77],bitmap[6][78],bitmap[6][79],bitmap[6][80],bitmap[6][81],bitmap[6][82],bitmap[6][83],bitmap[6][84],bitmap[6][85],bitmap[6][86],bitmap[6][87],bitmap[6][88],bitmap[6][89],bitmap[6][90],bitmap[6][91],bitmap[6][92],bitmap[6][93],bitmap[6][94],bitmap[6][95],
					bitmap[7][0],bitmap[7][1],bitmap[7][2],bitmap[7][3],bitmap[7][4],bitmap[7][5],bitmap[7][6],bitmap[7][7],bitmap[7][8],bitmap[7][9],bitmap[7][10],bitmap[7][11],bitmap[7][12],bitmap[7][13],bitmap[7][14],bitmap[7][15],bitmap[7][16],bitmap[7][17],bitmap[7][18],bitmap[7][19],bitmap[7][20],bitmap[7][21],bitmap[7][22],bitmap[7][23],bitmap[7][24],bitmap[7][25],bitmap[7][26],bitmap[7][27],bitmap[7][28],bitmap[7][29],bitmap[7][30],bitmap[7][31],bitmap[7][32],bitmap[7][33],bitmap[7][34],bitmap[7][35],bitmap[7][36],bitmap[7][37],bitmap[7][38],bitmap[7][39],bitmap[7][40],bitmap[7][41],bitmap[7][42],bitmap[7][43],bitmap[7][44],bitmap[7][45],bitmap[7][46],bitmap[7][47],bitmap[7][48],bitmap[7][49],bitmap[7][50],bitmap[7][51],bitmap[7][52],bitmap[7][53],bitmap[7][54],bitmap[7][55],bitmap[7][56],bitmap[7][57],bitmap[7][58],bitmap[7][59],bitmap[7][60],bitmap[7][61],bitmap[7][62],bitmap[7][63],bitmap[7][64],bitmap[7][65],bitmap[7][66],bitmap[7][67],bitmap[7][68],bitmap[7][69],bitmap[7][70],bitmap[7][71],bitmap[7][72],bitmap[7][73],bitmap[7][74],bitmap[7][75],bitmap[7][76],bitmap[7][77],bitmap[7][78],bitmap[7][79],bitmap[7][80],bitmap[7][81],bitmap[7][82],bitmap[7][83],bitmap[7][84],bitmap[7][85],bitmap[7][86],bitmap[7][87],bitmap[7][88],bitmap[7][89],bitmap[7][90],bitmap[7][91],bitmap[7][92],bitmap[7][93],bitmap[7][94],bitmap[7][95],
					bitmap[8][0],bitmap[8][1],bitmap[8][2],bitmap[8][3],bitmap[8][4],bitmap[8][5],bitmap[8][6],bitmap[8][7],bitmap[8][8],bitmap[8][9],bitmap[8][10],bitmap[8][11],bitmap[8][12],bitmap[8][13],bitmap[8][14],bitmap[8][15],bitmap[8][16],bitmap[8][17],bitmap[8][18],bitmap[8][19],bitmap[8][20],bitmap[8][21],bitmap[8][22],bitmap[8][23],bitmap[8][24],bitmap[8][25],bitmap[8][26],bitmap[8][27],bitmap[8][28],bitmap[8][29],bitmap[8][30],bitmap[8][31],bitmap[8][32],bitmap[8][33],bitmap[8][34],bitmap[8][35],bitmap[8][36],bitmap[8][37],bitmap[8][38],bitmap[8][39],bitmap[8][40],bitmap[8][41],bitmap[8][42],bitmap[8][43],bitmap[8][44],bitmap[8][45],bitmap[8][46],bitmap[8][47],bitmap[8][48],bitmap[8][49],bitmap[8][50],bitmap[8][51],bitmap[8][52],bitmap[8][53],bitmap[8][54],bitmap[8][55],bitmap[8][56],bitmap[8][57],bitmap[8][58],bitmap[8][59],bitmap[8][60],bitmap[8][61],bitmap[8][62],bitmap[8][63],bitmap[8][64],bitmap[8][65],bitmap[8][66],bitmap[8][67],bitmap[8][68],bitmap[8][69],bitmap[8][70],bitmap[8][71],bitmap[8][72],bitmap[8][73],bitmap[8][74],bitmap[8][75],bitmap[8][76],bitmap[8][77],bitmap[8][78],bitmap[8][79],bitmap[8][80],bitmap[8][81],bitmap[8][82],bitmap[8][83],bitmap[8][84],bitmap[8][85],bitmap[8][86],bitmap[8][87],bitmap[8][88],bitmap[8][89],bitmap[8][90],bitmap[8][91],bitmap[8][92],bitmap[8][93],bitmap[8][94],bitmap[8][95],
					bitmap[9][0],bitmap[9][1],bitmap[9][2],bitmap[9][3],bitmap[9][4],bitmap[9][5],bitmap[9][6],bitmap[9][7],bitmap[9][8],bitmap[9][9],bitmap[9][10],bitmap[9][11],bitmap[9][12],bitmap[9][13],bitmap[9][14],bitmap[9][15],bitmap[9][16],bitmap[9][17],bitmap[9][18],bitmap[9][19],bitmap[9][20],bitmap[9][21],bitmap[9][22],bitmap[9][23],bitmap[9][24],bitmap[9][25],bitmap[9][26],bitmap[9][27],bitmap[9][28],bitmap[9][29],bitmap[9][30],bitmap[9][31],bitmap[9][32],bitmap[9][33],bitmap[9][34],bitmap[9][35],bitmap[9][36],bitmap[9][37],bitmap[9][38],bitmap[9][39],bitmap[9][40],bitmap[9][41],bitmap[9][42],bitmap[9][43],bitmap[9][44],bitmap[9][45],bitmap[9][46],bitmap[9][47],bitmap[9][48],bitmap[9][49],bitmap[9][50],bitmap[9][51],bitmap[9][52],bitmap[9][53],bitmap[9][54],bitmap[9][55],bitmap[9][56],bitmap[9][57],bitmap[9][58],bitmap[9][59],bitmap[9][60],bitmap[9][61],bitmap[9][62],bitmap[9][63],bitmap[9][64],bitmap[9][65],bitmap[9][66],bitmap[9][67],bitmap[9][68],bitmap[9][69],bitmap[9][70],bitmap[9][71],bitmap[9][72],bitmap[9][73],bitmap[9][74],bitmap[9][75],bitmap[9][76],bitmap[9][77],bitmap[9][78],bitmap[9][79],bitmap[9][80],bitmap[9][81],bitmap[9][82],bitmap[9][83],bitmap[9][84],bitmap[9][85],bitmap[9][86],bitmap[9][87],bitmap[9][88],bitmap[9][89],bitmap[9][90],bitmap[9][91],bitmap[9][92],bitmap[9][93],bitmap[9][94],bitmap[9][95],
					bitmap[10][0],bitmap[10][1],bitmap[10][2],bitmap[10][3],bitmap[10][4],bitmap[10][5],bitmap[10][6],bitmap[10][7],bitmap[10][8],bitmap[10][9],bitmap[10][10],bitmap[10][11],bitmap[10][12],bitmap[10][13],bitmap[10][14],bitmap[10][15],bitmap[10][16],bitmap[10][17],bitmap[10][18],bitmap[10][19],bitmap[10][20],bitmap[10][21],bitmap[10][22],bitmap[10][23],bitmap[10][24],bitmap[10][25],bitmap[10][26],bitmap[10][27],bitmap[10][28],bitmap[10][29],bitmap[10][30],bitmap[10][31],bitmap[10][32],bitmap[10][33],bitmap[10][34],bitmap[10][35],bitmap[10][36],bitmap[10][37],bitmap[10][38],bitmap[10][39],bitmap[10][40],bitmap[10][41],bitmap[10][42],bitmap[10][43],bitmap[10][44],bitmap[10][45],bitmap[10][46],bitmap[10][47],bitmap[10][48],bitmap[10][49],bitmap[10][50],bitmap[10][51],bitmap[10][52],bitmap[10][53],bitmap[10][54],bitmap[10][55],bitmap[10][56],bitmap[10][57],bitmap[10][58],bitmap[10][59],bitmap[10][60],bitmap[10][61],bitmap[10][62],bitmap[10][63],bitmap[10][64],bitmap[10][65],bitmap[10][66],bitmap[10][67],bitmap[10][68],bitmap[10][69],bitmap[10][70],bitmap[10][71],bitmap[10][72],bitmap[10][73],bitmap[10][74],bitmap[10][75],bitmap[10][76],bitmap[10][77],bitmap[10][78],bitmap[10][79],bitmap[10][80],bitmap[10][81],bitmap[10][82],bitmap[10][83],bitmap[10][84],bitmap[10][85],bitmap[10][86],bitmap[10][87],bitmap[10][88],bitmap[10][89],bitmap[10][90],bitmap[10][91],bitmap[10][92],bitmap[10][93],bitmap[10][94],bitmap[10][95],
					bitmap[11][0],bitmap[11][1],bitmap[11][2],bitmap[11][3],bitmap[11][4],bitmap[11][5],bitmap[11][6],bitmap[11][7],bitmap[11][8],bitmap[11][9],bitmap[11][10],bitmap[11][11],bitmap[11][12],bitmap[11][13],bitmap[11][14],bitmap[11][15],bitmap[11][16],bitmap[11][17],bitmap[11][18],bitmap[11][19],bitmap[11][20],bitmap[11][21],bitmap[11][22],bitmap[11][23],bitmap[11][24],bitmap[11][25],bitmap[11][26],bitmap[11][27],bitmap[11][28],bitmap[11][29],bitmap[11][30],bitmap[11][31],bitmap[11][32],bitmap[11][33],bitmap[11][34],bitmap[11][35],bitmap[11][36],bitmap[11][37],bitmap[11][38],bitmap[11][39],bitmap[11][40],bitmap[11][41],bitmap[11][42],bitmap[11][43],bitmap[11][44],bitmap[11][45],bitmap[11][46],bitmap[11][47],bitmap[11][48],bitmap[11][49],bitmap[11][50],bitmap[11][51],bitmap[11][52],bitmap[11][53],bitmap[11][54],bitmap[11][55],bitmap[11][56],bitmap[11][57],bitmap[11][58],bitmap[11][59],bitmap[11][60],bitmap[11][61],bitmap[11][62],bitmap[11][63],bitmap[11][64],bitmap[11][65],bitmap[11][66],bitmap[11][67],bitmap[11][68],bitmap[11][69],bitmap[11][70],bitmap[11][71],bitmap[11][72],bitmap[11][73],bitmap[11][74],bitmap[11][75],bitmap[11][76],bitmap[11][77],bitmap[11][78],bitmap[11][79],bitmap[11][80],bitmap[11][81],bitmap[11][82],bitmap[11][83],bitmap[11][84],bitmap[11][85],bitmap[11][86],bitmap[11][87],bitmap[11][88],bitmap[11][89],bitmap[11][90],bitmap[11][91],bitmap[11][92],bitmap[11][93],bitmap[11][94],bitmap[11][95],
					bitmap[12][0],bitmap[12][1],bitmap[12][2],bitmap[12][3],bitmap[12][4],bitmap[12][5],bitmap[12][6],bitmap[12][7],bitmap[12][8],bitmap[12][9],bitmap[12][10],bitmap[12][11],bitmap[12][12],bitmap[12][13],bitmap[12][14],bitmap[12][15],bitmap[12][16],bitmap[12][17],bitmap[12][18],bitmap[12][19],bitmap[12][20],bitmap[12][21],bitmap[12][22],bitmap[12][23],bitmap[12][24],bitmap[12][25],bitmap[12][26],bitmap[12][27],bitmap[12][28],bitmap[12][29],bitmap[12][30],bitmap[12][31],bitmap[12][32],bitmap[12][33],bitmap[12][34],bitmap[12][35],bitmap[12][36],bitmap[12][37],bitmap[12][38],bitmap[12][39],bitmap[12][40],bitmap[12][41],bitmap[12][42],bitmap[12][43],bitmap[12][44],bitmap[12][45],bitmap[12][46],bitmap[12][47],bitmap[12][48],bitmap[12][49],bitmap[12][50],bitmap[12][51],bitmap[12][52],bitmap[12][53],bitmap[12][54],bitmap[12][55],bitmap[12][56],bitmap[12][57],bitmap[12][58],bitmap[12][59],bitmap[12][60],bitmap[12][61],bitmap[12][62],bitmap[12][63],bitmap[12][64],bitmap[12][65],bitmap[12][66],bitmap[12][67],bitmap[12][68],bitmap[12][69],bitmap[12][70],bitmap[12][71],bitmap[12][72],bitmap[12][73],bitmap[12][74],bitmap[12][75],bitmap[12][76],bitmap[12][77],bitmap[12][78],bitmap[12][79],bitmap[12][80],bitmap[12][81],bitmap[12][82],bitmap[12][83],bitmap[12][84],bitmap[12][85],bitmap[12][86],bitmap[12][87],bitmap[12][88],bitmap[12][89],bitmap[12][90],bitmap[12][91],bitmap[12][92],bitmap[12][93],bitmap[12][94],bitmap[12][95],
					bitmap[13][0],bitmap[13][1],bitmap[13][2],bitmap[13][3],bitmap[13][4],bitmap[13][5],bitmap[13][6],bitmap[13][7],bitmap[13][8],bitmap[13][9],bitmap[13][10],bitmap[13][11],bitmap[13][12],bitmap[13][13],bitmap[13][14],bitmap[13][15],bitmap[13][16],bitmap[13][17],bitmap[13][18],bitmap[13][19],bitmap[13][20],bitmap[13][21],bitmap[13][22],bitmap[13][23],bitmap[13][24],bitmap[13][25],bitmap[13][26],bitmap[13][27],bitmap[13][28],bitmap[13][29],bitmap[13][30],bitmap[13][31],bitmap[13][32],bitmap[13][33],bitmap[13][34],bitmap[13][35],bitmap[13][36],bitmap[13][37],bitmap[13][38],bitmap[13][39],bitmap[13][40],bitmap[13][41],bitmap[13][42],bitmap[13][43],bitmap[13][44],bitmap[13][45],bitmap[13][46],bitmap[13][47],bitmap[13][48],bitmap[13][49],bitmap[13][50],bitmap[13][51],bitmap[13][52],bitmap[13][53],bitmap[13][54],bitmap[13][55],bitmap[13][56],bitmap[13][57],bitmap[13][58],bitmap[13][59],bitmap[13][60],bitmap[13][61],bitmap[13][62],bitmap[13][63],bitmap[13][64],bitmap[13][65],bitmap[13][66],bitmap[13][67],bitmap[13][68],bitmap[13][69],bitmap[13][70],bitmap[13][71],bitmap[13][72],bitmap[13][73],bitmap[13][74],bitmap[13][75],bitmap[13][76],bitmap[13][77],bitmap[13][78],bitmap[13][79],bitmap[13][80],bitmap[13][81],bitmap[13][82],bitmap[13][83],bitmap[13][84],bitmap[13][85],bitmap[13][86],bitmap[13][87],bitmap[13][88],bitmap[13][89],bitmap[13][90],bitmap[13][91],bitmap[13][92],bitmap[13][93],bitmap[13][94],bitmap[13][95],
					bitmap[14][0],bitmap[14][1],bitmap[14][2],bitmap[14][3],bitmap[14][4],bitmap[14][5],bitmap[14][6],bitmap[14][7],bitmap[14][8],bitmap[14][9],bitmap[14][10],bitmap[14][11],bitmap[14][12],bitmap[14][13],bitmap[14][14],bitmap[14][15],bitmap[14][16],bitmap[14][17],bitmap[14][18],bitmap[14][19],bitmap[14][20],bitmap[14][21],bitmap[14][22],bitmap[14][23],bitmap[14][24],bitmap[14][25],bitmap[14][26],bitmap[14][27],bitmap[14][28],bitmap[14][29],bitmap[14][30],bitmap[14][31],bitmap[14][32],bitmap[14][33],bitmap[14][34],bitmap[14][35],bitmap[14][36],bitmap[14][37],bitmap[14][38],bitmap[14][39],bitmap[14][40],bitmap[14][41],bitmap[14][42],bitmap[14][43],bitmap[14][44],bitmap[14][45],bitmap[14][46],bitmap[14][47],bitmap[14][48],bitmap[14][49],bitmap[14][50],bitmap[14][51],bitmap[14][52],bitmap[14][53],bitmap[14][54],bitmap[14][55],bitmap[14][56],bitmap[14][57],bitmap[14][58],bitmap[14][59],bitmap[14][60],bitmap[14][61],bitmap[14][62],bitmap[14][63],bitmap[14][64],bitmap[14][65],bitmap[14][66],bitmap[14][67],bitmap[14][68],bitmap[14][69],bitmap[14][70],bitmap[14][71],bitmap[14][72],bitmap[14][73],bitmap[14][74],bitmap[14][75],bitmap[14][76],bitmap[14][77],bitmap[14][78],bitmap[14][79],bitmap[14][80],bitmap[14][81],bitmap[14][82],bitmap[14][83],bitmap[14][84],bitmap[14][85],bitmap[14][86],bitmap[14][87],bitmap[14][88],bitmap[14][89],bitmap[14][90],bitmap[14][91],bitmap[14][92],bitmap[14][93],bitmap[14][94],bitmap[14][95],
					bitmap[15][0],bitmap[15][1],bitmap[15][2],bitmap[15][3],bitmap[15][4],bitmap[15][5],bitmap[15][6],bitmap[15][7],bitmap[15][8],bitmap[15][9],bitmap[15][10],bitmap[15][11],bitmap[15][12],bitmap[15][13],bitmap[15][14],bitmap[15][15],bitmap[15][16],bitmap[15][17],bitmap[15][18],bitmap[15][19],bitmap[15][20],bitmap[15][21],bitmap[15][22],bitmap[15][23],bitmap[15][24],bitmap[15][25],bitmap[15][26],bitmap[15][27],bitmap[15][28],bitmap[15][29],bitmap[15][30],bitmap[15][31],bitmap[15][32],bitmap[15][33],bitmap[15][34],bitmap[15][35],bitmap[15][36],bitmap[15][37],bitmap[15][38],bitmap[15][39],bitmap[15][40],bitmap[15][41],bitmap[15][42],bitmap[15][43],bitmap[15][44],bitmap[15][45],bitmap[15][46],bitmap[15][47],bitmap[15][48],bitmap[15][49],bitmap[15][50],bitmap[15][51],bitmap[15][52],bitmap[15][53],bitmap[15][54],bitmap[15][55],bitmap[15][56],bitmap[15][57],bitmap[15][58],bitmap[15][59],bitmap[15][60],bitmap[15][61],bitmap[15][62],bitmap[15][63],bitmap[15][64],bitmap[15][65],bitmap[15][66],bitmap[15][67],bitmap[15][68],bitmap[15][69],bitmap[15][70],bitmap[15][71],bitmap[15][72],bitmap[15][73],bitmap[15][74],bitmap[15][75],bitmap[15][76],bitmap[15][77],bitmap[15][78],bitmap[15][79],bitmap[15][80],bitmap[15][81],bitmap[15][82],bitmap[15][83],bitmap[15][84],bitmap[15][85],bitmap[15][86],bitmap[15][87],bitmap[15][88],bitmap[15][89],bitmap[15][90],bitmap[15][91],bitmap[15][92],bitmap[15][93],bitmap[15][94],bitmap[15][95],
					bitmap[16][0],bitmap[16][1],bitmap[16][2],bitmap[16][3],bitmap[16][4],bitmap[16][5],bitmap[16][6],bitmap[16][7],bitmap[16][8],bitmap[16][9],bitmap[16][10],bitmap[16][11],bitmap[16][12],bitmap[16][13],bitmap[16][14],bitmap[16][15],bitmap[16][16],bitmap[16][17],bitmap[16][18],bitmap[16][19],bitmap[16][20],bitmap[16][21],bitmap[16][22],bitmap[16][23],bitmap[16][24],bitmap[16][25],bitmap[16][26],bitmap[16][27],bitmap[16][28],bitmap[16][29],bitmap[16][30],bitmap[16][31],bitmap[16][32],bitmap[16][33],bitmap[16][34],bitmap[16][35],bitmap[16][36],bitmap[16][37],bitmap[16][38],bitmap[16][39],bitmap[16][40],bitmap[16][41],bitmap[16][42],bitmap[16][43],bitmap[16][44],bitmap[16][45],bitmap[16][46],bitmap[16][47],bitmap[16][48],bitmap[16][49],bitmap[16][50],bitmap[16][51],bitmap[16][52],bitmap[16][53],bitmap[16][54],bitmap[16][55],bitmap[16][56],bitmap[16][57],bitmap[16][58],bitmap[16][59],bitmap[16][60],bitmap[16][61],bitmap[16][62],bitmap[16][63],bitmap[16][64],bitmap[16][65],bitmap[16][66],bitmap[16][67],bitmap[16][68],bitmap[16][69],bitmap[16][70],bitmap[16][71],bitmap[16][72],bitmap[16][73],bitmap[16][74],bitmap[16][75],bitmap[16][76],bitmap[16][77],bitmap[16][78],bitmap[16][79],bitmap[16][80],bitmap[16][81],bitmap[16][82],bitmap[16][83],bitmap[16][84],bitmap[16][85],bitmap[16][86],bitmap[16][87],bitmap[16][88],bitmap[16][89],bitmap[16][90],bitmap[16][91],bitmap[16][92],bitmap[16][93],bitmap[16][94],bitmap[16][95],
					bitmap[17][0],bitmap[17][1],bitmap[17][2],bitmap[17][3],bitmap[17][4],bitmap[17][5],bitmap[17][6],bitmap[17][7],bitmap[17][8],bitmap[17][9],bitmap[17][10],bitmap[17][11],bitmap[17][12],bitmap[17][13],bitmap[17][14],bitmap[17][15],bitmap[17][16],bitmap[17][17],bitmap[17][18],bitmap[17][19],bitmap[17][20],bitmap[17][21],bitmap[17][22],bitmap[17][23],bitmap[17][24],bitmap[17][25],bitmap[17][26],bitmap[17][27],bitmap[17][28],bitmap[17][29],bitmap[17][30],bitmap[17][31],bitmap[17][32],bitmap[17][33],bitmap[17][34],bitmap[17][35],bitmap[17][36],bitmap[17][37],bitmap[17][38],bitmap[17][39],bitmap[17][40],bitmap[17][41],bitmap[17][42],bitmap[17][43],bitmap[17][44],bitmap[17][45],bitmap[17][46],bitmap[17][47],bitmap[17][48],bitmap[17][49],bitmap[17][50],bitmap[17][51],bitmap[17][52],bitmap[17][53],bitmap[17][54],bitmap[17][55],bitmap[17][56],bitmap[17][57],bitmap[17][58],bitmap[17][59],bitmap[17][60],bitmap[17][61],bitmap[17][62],bitmap[17][63],bitmap[17][64],bitmap[17][65],bitmap[17][66],bitmap[17][67],bitmap[17][68],bitmap[17][69],bitmap[17][70],bitmap[17][71],bitmap[17][72],bitmap[17][73],bitmap[17][74],bitmap[17][75],bitmap[17][76],bitmap[17][77],bitmap[17][78],bitmap[17][79],bitmap[17][80],bitmap[17][81],bitmap[17][82],bitmap[17][83],bitmap[17][84],bitmap[17][85],bitmap[17][86],bitmap[17][87],bitmap[17][88],bitmap[17][89],bitmap[17][90],bitmap[17][91],bitmap[17][92],bitmap[17][93],bitmap[17][94],bitmap[17][95],
					bitmap[18][0],bitmap[18][1],bitmap[18][2],bitmap[18][3],bitmap[18][4],bitmap[18][5],bitmap[18][6],bitmap[18][7],bitmap[18][8],bitmap[18][9],bitmap[18][10],bitmap[18][11],bitmap[18][12],bitmap[18][13],bitmap[18][14],bitmap[18][15],bitmap[18][16],bitmap[18][17],bitmap[18][18],bitmap[18][19],bitmap[18][20],bitmap[18][21],bitmap[18][22],bitmap[18][23],bitmap[18][24],bitmap[18][25],bitmap[18][26],bitmap[18][27],bitmap[18][28],bitmap[18][29],bitmap[18][30],bitmap[18][31],bitmap[18][32],bitmap[18][33],bitmap[18][34],bitmap[18][35],bitmap[18][36],bitmap[18][37],bitmap[18][38],bitmap[18][39],bitmap[18][40],bitmap[18][41],bitmap[18][42],bitmap[18][43],bitmap[18][44],bitmap[18][45],bitmap[18][46],bitmap[18][47],bitmap[18][48],bitmap[18][49],bitmap[18][50],bitmap[18][51],bitmap[18][52],bitmap[18][53],bitmap[18][54],bitmap[18][55],bitmap[18][56],bitmap[18][57],bitmap[18][58],bitmap[18][59],bitmap[18][60],bitmap[18][61],bitmap[18][62],bitmap[18][63],bitmap[18][64],bitmap[18][65],bitmap[18][66],bitmap[18][67],bitmap[18][68],bitmap[18][69],bitmap[18][70],bitmap[18][71],bitmap[18][72],bitmap[18][73],bitmap[18][74],bitmap[18][75],bitmap[18][76],bitmap[18][77],bitmap[18][78],bitmap[18][79],bitmap[18][80],bitmap[18][81],bitmap[18][82],bitmap[18][83],bitmap[18][84],bitmap[18][85],bitmap[18][86],bitmap[18][87],bitmap[18][88],bitmap[18][89],bitmap[18][90],bitmap[18][91],bitmap[18][92],bitmap[18][93],bitmap[18][94],bitmap[18][95],
					bitmap[19][0],bitmap[19][1],bitmap[19][2],bitmap[19][3],bitmap[19][4],bitmap[19][5],bitmap[19][6],bitmap[19][7],bitmap[19][8],bitmap[19][9],bitmap[19][10],bitmap[19][11],bitmap[19][12],bitmap[19][13],bitmap[19][14],bitmap[19][15],bitmap[19][16],bitmap[19][17],bitmap[19][18],bitmap[19][19],bitmap[19][20],bitmap[19][21],bitmap[19][22],bitmap[19][23],bitmap[19][24],bitmap[19][25],bitmap[19][26],bitmap[19][27],bitmap[19][28],bitmap[19][29],bitmap[19][30],bitmap[19][31],bitmap[19][32],bitmap[19][33],bitmap[19][34],bitmap[19][35],bitmap[19][36],bitmap[19][37],bitmap[19][38],bitmap[19][39],bitmap[19][40],bitmap[19][41],bitmap[19][42],bitmap[19][43],bitmap[19][44],bitmap[19][45],bitmap[19][46],bitmap[19][47],bitmap[19][48],bitmap[19][49],bitmap[19][50],bitmap[19][51],bitmap[19][52],bitmap[19][53],bitmap[19][54],bitmap[19][55],bitmap[19][56],bitmap[19][57],bitmap[19][58],bitmap[19][59],bitmap[19][60],bitmap[19][61],bitmap[19][62],bitmap[19][63],bitmap[19][64],bitmap[19][65],bitmap[19][66],bitmap[19][67],bitmap[19][68],bitmap[19][69],bitmap[19][70],bitmap[19][71],bitmap[19][72],bitmap[19][73],bitmap[19][74],bitmap[19][75],bitmap[19][76],bitmap[19][77],bitmap[19][78],bitmap[19][79],bitmap[19][80],bitmap[19][81],bitmap[19][82],bitmap[19][83],bitmap[19][84],bitmap[19][85],bitmap[19][86],bitmap[19][87],bitmap[19][88],bitmap[19][89],bitmap[19][90],bitmap[19][91],bitmap[19][92],bitmap[19][93],bitmap[19][94],bitmap[19][95],
					bitmap[20][0],bitmap[20][1],bitmap[20][2],bitmap[20][3],bitmap[20][4],bitmap[20][5],bitmap[20][6],bitmap[20][7],bitmap[20][8],bitmap[20][9],bitmap[20][10],bitmap[20][11],bitmap[20][12],bitmap[20][13],bitmap[20][14],bitmap[20][15],bitmap[20][16],bitmap[20][17],bitmap[20][18],bitmap[20][19],bitmap[20][20],bitmap[20][21],bitmap[20][22],bitmap[20][23],bitmap[20][24],bitmap[20][25],bitmap[20][26],bitmap[20][27],bitmap[20][28],bitmap[20][29],bitmap[20][30],bitmap[20][31],bitmap[20][32],bitmap[20][33],bitmap[20][34],bitmap[20][35],bitmap[20][36],bitmap[20][37],bitmap[20][38],bitmap[20][39],bitmap[20][40],bitmap[20][41],bitmap[20][42],bitmap[20][43],bitmap[20][44],bitmap[20][45],bitmap[20][46],bitmap[20][47],bitmap[20][48],bitmap[20][49],bitmap[20][50],bitmap[20][51],bitmap[20][52],bitmap[20][53],bitmap[20][54],bitmap[20][55],bitmap[20][56],bitmap[20][57],bitmap[20][58],bitmap[20][59],bitmap[20][60],bitmap[20][61],bitmap[20][62],bitmap[20][63],bitmap[20][64],bitmap[20][65],bitmap[20][66],bitmap[20][67],bitmap[20][68],bitmap[20][69],bitmap[20][70],bitmap[20][71],bitmap[20][72],bitmap[20][73],bitmap[20][74],bitmap[20][75],bitmap[20][76],bitmap[20][77],bitmap[20][78],bitmap[20][79],bitmap[20][80],bitmap[20][81],bitmap[20][82],bitmap[20][83],bitmap[20][84],bitmap[20][85],bitmap[20][86],bitmap[20][87],bitmap[20][88],bitmap[20][89],bitmap[20][90],bitmap[20][91],bitmap[20][92],bitmap[20][93],bitmap[20][94],bitmap[20][95],
					bitmap[21][0],bitmap[21][1],bitmap[21][2],bitmap[21][3],bitmap[21][4],bitmap[21][5],bitmap[21][6],bitmap[21][7],bitmap[21][8],bitmap[21][9],bitmap[21][10],bitmap[21][11],bitmap[21][12],bitmap[21][13],bitmap[21][14],bitmap[21][15],bitmap[21][16],bitmap[21][17],bitmap[21][18],bitmap[21][19],bitmap[21][20],bitmap[21][21],bitmap[21][22],bitmap[21][23],bitmap[21][24],bitmap[21][25],bitmap[21][26],bitmap[21][27],bitmap[21][28],bitmap[21][29],bitmap[21][30],bitmap[21][31],bitmap[21][32],bitmap[21][33],bitmap[21][34],bitmap[21][35],bitmap[21][36],bitmap[21][37],bitmap[21][38],bitmap[21][39],bitmap[21][40],bitmap[21][41],bitmap[21][42],bitmap[21][43],bitmap[21][44],bitmap[21][45],bitmap[21][46],bitmap[21][47],bitmap[21][48],bitmap[21][49],bitmap[21][50],bitmap[21][51],bitmap[21][52],bitmap[21][53],bitmap[21][54],bitmap[21][55],bitmap[21][56],bitmap[21][57],bitmap[21][58],bitmap[21][59],bitmap[21][60],bitmap[21][61],bitmap[21][62],bitmap[21][63],bitmap[21][64],bitmap[21][65],bitmap[21][66],bitmap[21][67],bitmap[21][68],bitmap[21][69],bitmap[21][70],bitmap[21][71],bitmap[21][72],bitmap[21][73],bitmap[21][74],bitmap[21][75],bitmap[21][76],bitmap[21][77],bitmap[21][78],bitmap[21][79],bitmap[21][80],bitmap[21][81],bitmap[21][82],bitmap[21][83],bitmap[21][84],bitmap[21][85],bitmap[21][86],bitmap[21][87],bitmap[21][88],bitmap[21][89],bitmap[21][90],bitmap[21][91],bitmap[21][92],bitmap[21][93],bitmap[21][94],bitmap[21][95],
					bitmap[22][0],bitmap[22][1],bitmap[22][2],bitmap[22][3],bitmap[22][4],bitmap[22][5],bitmap[22][6],bitmap[22][7],bitmap[22][8],bitmap[22][9],bitmap[22][10],bitmap[22][11],bitmap[22][12],bitmap[22][13],bitmap[22][14],bitmap[22][15],bitmap[22][16],bitmap[22][17],bitmap[22][18],bitmap[22][19],bitmap[22][20],bitmap[22][21],bitmap[22][22],bitmap[22][23],bitmap[22][24],bitmap[22][25],bitmap[22][26],bitmap[22][27],bitmap[22][28],bitmap[22][29],bitmap[22][30],bitmap[22][31],bitmap[22][32],bitmap[22][33],bitmap[22][34],bitmap[22][35],bitmap[22][36],bitmap[22][37],bitmap[22][38],bitmap[22][39],bitmap[22][40],bitmap[22][41],bitmap[22][42],bitmap[22][43],bitmap[22][44],bitmap[22][45],bitmap[22][46],bitmap[22][47],bitmap[22][48],bitmap[22][49],bitmap[22][50],bitmap[22][51],bitmap[22][52],bitmap[22][53],bitmap[22][54],bitmap[22][55],bitmap[22][56],bitmap[22][57],bitmap[22][58],bitmap[22][59],bitmap[22][60],bitmap[22][61],bitmap[22][62],bitmap[22][63],bitmap[22][64],bitmap[22][65],bitmap[22][66],bitmap[22][67],bitmap[22][68],bitmap[22][69],bitmap[22][70],bitmap[22][71],bitmap[22][72],bitmap[22][73],bitmap[22][74],bitmap[22][75],bitmap[22][76],bitmap[22][77],bitmap[22][78],bitmap[22][79],bitmap[22][80],bitmap[22][81],bitmap[22][82],bitmap[22][83],bitmap[22][84],bitmap[22][85],bitmap[22][86],bitmap[22][87],bitmap[22][88],bitmap[22][89],bitmap[22][90],bitmap[22][91],bitmap[22][92],bitmap[22][93],bitmap[22][94],bitmap[22][95],
					bitmap[23][0],bitmap[23][1],bitmap[23][2],bitmap[23][3],bitmap[23][4],bitmap[23][5],bitmap[23][6],bitmap[23][7],bitmap[23][8],bitmap[23][9],bitmap[23][10],bitmap[23][11],bitmap[23][12],bitmap[23][13],bitmap[23][14],bitmap[23][15],bitmap[23][16],bitmap[23][17],bitmap[23][18],bitmap[23][19],bitmap[23][20],bitmap[23][21],bitmap[23][22],bitmap[23][23],bitmap[23][24],bitmap[23][25],bitmap[23][26],bitmap[23][27],bitmap[23][28],bitmap[23][29],bitmap[23][30],bitmap[23][31],bitmap[23][32],bitmap[23][33],bitmap[23][34],bitmap[23][35],bitmap[23][36],bitmap[23][37],bitmap[23][38],bitmap[23][39],bitmap[23][40],bitmap[23][41],bitmap[23][42],bitmap[23][43],bitmap[23][44],bitmap[23][45],bitmap[23][46],bitmap[23][47],bitmap[23][48],bitmap[23][49],bitmap[23][50],bitmap[23][51],bitmap[23][52],bitmap[23][53],bitmap[23][54],bitmap[23][55],bitmap[23][56],bitmap[23][57],bitmap[23][58],bitmap[23][59],bitmap[23][60],bitmap[23][61],bitmap[23][62],bitmap[23][63],bitmap[23][64],bitmap[23][65],bitmap[23][66],bitmap[23][67],bitmap[23][68],bitmap[23][69],bitmap[23][70],bitmap[23][71],bitmap[23][72],bitmap[23][73],bitmap[23][74],bitmap[23][75],bitmap[23][76],bitmap[23][77],bitmap[23][78],bitmap[23][79],bitmap[23][80],bitmap[23][81],bitmap[23][82],bitmap[23][83],bitmap[23][84],bitmap[23][85],bitmap[23][86],bitmap[23][87],bitmap[23][88],bitmap[23][89],bitmap[23][90],bitmap[23][91],bitmap[23][92],bitmap[23][93],bitmap[23][94],bitmap[23][95],
					bitmap[24][0],bitmap[24][1],bitmap[24][2],bitmap[24][3],bitmap[24][4],bitmap[24][5],bitmap[24][6],bitmap[24][7],bitmap[24][8],bitmap[24][9],bitmap[24][10],bitmap[24][11],bitmap[24][12],bitmap[24][13],bitmap[24][14],bitmap[24][15],bitmap[24][16],bitmap[24][17],bitmap[24][18],bitmap[24][19],bitmap[24][20],bitmap[24][21],bitmap[24][22],bitmap[24][23],bitmap[24][24],bitmap[24][25],bitmap[24][26],bitmap[24][27],bitmap[24][28],bitmap[24][29],bitmap[24][30],bitmap[24][31],bitmap[24][32],bitmap[24][33],bitmap[24][34],bitmap[24][35],bitmap[24][36],bitmap[24][37],bitmap[24][38],bitmap[24][39],bitmap[24][40],bitmap[24][41],bitmap[24][42],bitmap[24][43],bitmap[24][44],bitmap[24][45],bitmap[24][46],bitmap[24][47],bitmap[24][48],bitmap[24][49],bitmap[24][50],bitmap[24][51],bitmap[24][52],bitmap[24][53],bitmap[24][54],bitmap[24][55],bitmap[24][56],bitmap[24][57],bitmap[24][58],bitmap[24][59],bitmap[24][60],bitmap[24][61],bitmap[24][62],bitmap[24][63],bitmap[24][64],bitmap[24][65],bitmap[24][66],bitmap[24][67],bitmap[24][68],bitmap[24][69],bitmap[24][70],bitmap[24][71],bitmap[24][72],bitmap[24][73],bitmap[24][74],bitmap[24][75],bitmap[24][76],bitmap[24][77],bitmap[24][78],bitmap[24][79],bitmap[24][80],bitmap[24][81],bitmap[24][82],bitmap[24][83],bitmap[24][84],bitmap[24][85],bitmap[24][86],bitmap[24][87],bitmap[24][88],bitmap[24][89],bitmap[24][90],bitmap[24][91],bitmap[24][92],bitmap[24][93],bitmap[24][94],bitmap[24][95],
					bitmap[25][0],bitmap[25][1],bitmap[25][2],bitmap[25][3],bitmap[25][4],bitmap[25][5],bitmap[25][6],bitmap[25][7],bitmap[25][8],bitmap[25][9],bitmap[25][10],bitmap[25][11],bitmap[25][12],bitmap[25][13],bitmap[25][14],bitmap[25][15],bitmap[25][16],bitmap[25][17],bitmap[25][18],bitmap[25][19],bitmap[25][20],bitmap[25][21],bitmap[25][22],bitmap[25][23],bitmap[25][24],bitmap[25][25],bitmap[25][26],bitmap[25][27],bitmap[25][28],bitmap[25][29],bitmap[25][30],bitmap[25][31],bitmap[25][32],bitmap[25][33],bitmap[25][34],bitmap[25][35],bitmap[25][36],bitmap[25][37],bitmap[25][38],bitmap[25][39],bitmap[25][40],bitmap[25][41],bitmap[25][42],bitmap[25][43],bitmap[25][44],bitmap[25][45],bitmap[25][46],bitmap[25][47],bitmap[25][48],bitmap[25][49],bitmap[25][50],bitmap[25][51],bitmap[25][52],bitmap[25][53],bitmap[25][54],bitmap[25][55],bitmap[25][56],bitmap[25][57],bitmap[25][58],bitmap[25][59],bitmap[25][60],bitmap[25][61],bitmap[25][62],bitmap[25][63],bitmap[25][64],bitmap[25][65],bitmap[25][66],bitmap[25][67],bitmap[25][68],bitmap[25][69],bitmap[25][70],bitmap[25][71],bitmap[25][72],bitmap[25][73],bitmap[25][74],bitmap[25][75],bitmap[25][76],bitmap[25][77],bitmap[25][78],bitmap[25][79],bitmap[25][80],bitmap[25][81],bitmap[25][82],bitmap[25][83],bitmap[25][84],bitmap[25][85],bitmap[25][86],bitmap[25][87],bitmap[25][88],bitmap[25][89],bitmap[25][90],bitmap[25][91],bitmap[25][92],bitmap[25][93],bitmap[25][94],bitmap[25][95],
					bitmap[26][0],bitmap[26][1],bitmap[26][2],bitmap[26][3],bitmap[26][4],bitmap[26][5],bitmap[26][6],bitmap[26][7],bitmap[26][8],bitmap[26][9],bitmap[26][10],bitmap[26][11],bitmap[26][12],bitmap[26][13],bitmap[26][14],bitmap[26][15],bitmap[26][16],bitmap[26][17],bitmap[26][18],bitmap[26][19],bitmap[26][20],bitmap[26][21],bitmap[26][22],bitmap[26][23],bitmap[26][24],bitmap[26][25],bitmap[26][26],bitmap[26][27],bitmap[26][28],bitmap[26][29],bitmap[26][30],bitmap[26][31],bitmap[26][32],bitmap[26][33],bitmap[26][34],bitmap[26][35],bitmap[26][36],bitmap[26][37],bitmap[26][38],bitmap[26][39],bitmap[26][40],bitmap[26][41],bitmap[26][42],bitmap[26][43],bitmap[26][44],bitmap[26][45],bitmap[26][46],bitmap[26][47],bitmap[26][48],bitmap[26][49],bitmap[26][50],bitmap[26][51],bitmap[26][52],bitmap[26][53],bitmap[26][54],bitmap[26][55],bitmap[26][56],bitmap[26][57],bitmap[26][58],bitmap[26][59],bitmap[26][60],bitmap[26][61],bitmap[26][62],bitmap[26][63],bitmap[26][64],bitmap[26][65],bitmap[26][66],bitmap[26][67],bitmap[26][68],bitmap[26][69],bitmap[26][70],bitmap[26][71],bitmap[26][72],bitmap[26][73],bitmap[26][74],bitmap[26][75],bitmap[26][76],bitmap[26][77],bitmap[26][78],bitmap[26][79],bitmap[26][80],bitmap[26][81],bitmap[26][82],bitmap[26][83],bitmap[26][84],bitmap[26][85],bitmap[26][86],bitmap[26][87],bitmap[26][88],bitmap[26][89],bitmap[26][90],bitmap[26][91],bitmap[26][92],bitmap[26][93],bitmap[26][94],bitmap[26][95],
					bitmap[27][0],bitmap[27][1],bitmap[27][2],bitmap[27][3],bitmap[27][4],bitmap[27][5],bitmap[27][6],bitmap[27][7],bitmap[27][8],bitmap[27][9],bitmap[27][10],bitmap[27][11],bitmap[27][12],bitmap[27][13],bitmap[27][14],bitmap[27][15],bitmap[27][16],bitmap[27][17],bitmap[27][18],bitmap[27][19],bitmap[27][20],bitmap[27][21],bitmap[27][22],bitmap[27][23],bitmap[27][24],bitmap[27][25],bitmap[27][26],bitmap[27][27],bitmap[27][28],bitmap[27][29],bitmap[27][30],bitmap[27][31],bitmap[27][32],bitmap[27][33],bitmap[27][34],bitmap[27][35],bitmap[27][36],bitmap[27][37],bitmap[27][38],bitmap[27][39],bitmap[27][40],bitmap[27][41],bitmap[27][42],bitmap[27][43],bitmap[27][44],bitmap[27][45],bitmap[27][46],bitmap[27][47],bitmap[27][48],bitmap[27][49],bitmap[27][50],bitmap[27][51],bitmap[27][52],bitmap[27][53],bitmap[27][54],bitmap[27][55],bitmap[27][56],bitmap[27][57],bitmap[27][58],bitmap[27][59],bitmap[27][60],bitmap[27][61],bitmap[27][62],bitmap[27][63],bitmap[27][64],bitmap[27][65],bitmap[27][66],bitmap[27][67],bitmap[27][68],bitmap[27][69],bitmap[27][70],bitmap[27][71],bitmap[27][72],bitmap[27][73],bitmap[27][74],bitmap[27][75],bitmap[27][76],bitmap[27][77],bitmap[27][78],bitmap[27][79],bitmap[27][80],bitmap[27][81],bitmap[27][82],bitmap[27][83],bitmap[27][84],bitmap[27][85],bitmap[27][86],bitmap[27][87],bitmap[27][88],bitmap[27][89],bitmap[27][90],bitmap[27][91],bitmap[27][92],bitmap[27][93],bitmap[27][94],bitmap[27][95],
					bitmap[28][0],bitmap[28][1],bitmap[28][2],bitmap[28][3],bitmap[28][4],bitmap[28][5],bitmap[28][6],bitmap[28][7],bitmap[28][8],bitmap[28][9],bitmap[28][10],bitmap[28][11],bitmap[28][12],bitmap[28][13],bitmap[28][14],bitmap[28][15],bitmap[28][16],bitmap[28][17],bitmap[28][18],bitmap[28][19],bitmap[28][20],bitmap[28][21],bitmap[28][22],bitmap[28][23],bitmap[28][24],bitmap[28][25],bitmap[28][26],bitmap[28][27],bitmap[28][28],bitmap[28][29],bitmap[28][30],bitmap[28][31],bitmap[28][32],bitmap[28][33],bitmap[28][34],bitmap[28][35],bitmap[28][36],bitmap[28][37],bitmap[28][38],bitmap[28][39],bitmap[28][40],bitmap[28][41],bitmap[28][42],bitmap[28][43],bitmap[28][44],bitmap[28][45],bitmap[28][46],bitmap[28][47],bitmap[28][48],bitmap[28][49],bitmap[28][50],bitmap[28][51],bitmap[28][52],bitmap[28][53],bitmap[28][54],bitmap[28][55],bitmap[28][56],bitmap[28][57],bitmap[28][58],bitmap[28][59],bitmap[28][60],bitmap[28][61],bitmap[28][62],bitmap[28][63],bitmap[28][64],bitmap[28][65],bitmap[28][66],bitmap[28][67],bitmap[28][68],bitmap[28][69],bitmap[28][70],bitmap[28][71],bitmap[28][72],bitmap[28][73],bitmap[28][74],bitmap[28][75],bitmap[28][76],bitmap[28][77],bitmap[28][78],bitmap[28][79],bitmap[28][80],bitmap[28][81],bitmap[28][82],bitmap[28][83],bitmap[28][84],bitmap[28][85],bitmap[28][86],bitmap[28][87],bitmap[28][88],bitmap[28][89],bitmap[28][90],bitmap[28][91],bitmap[28][92],bitmap[28][93],bitmap[28][94],bitmap[28][95],
					bitmap[29][0],bitmap[29][1],bitmap[29][2],bitmap[29][3],bitmap[29][4],bitmap[29][5],bitmap[29][6],bitmap[29][7],bitmap[29][8],bitmap[29][9],bitmap[29][10],bitmap[29][11],bitmap[29][12],bitmap[29][13],bitmap[29][14],bitmap[29][15],bitmap[29][16],bitmap[29][17],bitmap[29][18],bitmap[29][19],bitmap[29][20],bitmap[29][21],bitmap[29][22],bitmap[29][23],bitmap[29][24],bitmap[29][25],bitmap[29][26],bitmap[29][27],bitmap[29][28],bitmap[29][29],bitmap[29][30],bitmap[29][31],bitmap[29][32],bitmap[29][33],bitmap[29][34],bitmap[29][35],bitmap[29][36],bitmap[29][37],bitmap[29][38],bitmap[29][39],bitmap[29][40],bitmap[29][41],bitmap[29][42],bitmap[29][43],bitmap[29][44],bitmap[29][45],bitmap[29][46],bitmap[29][47],bitmap[29][48],bitmap[29][49],bitmap[29][50],bitmap[29][51],bitmap[29][52],bitmap[29][53],bitmap[29][54],bitmap[29][55],bitmap[29][56],bitmap[29][57],bitmap[29][58],bitmap[29][59],bitmap[29][60],bitmap[29][61],bitmap[29][62],bitmap[29][63],bitmap[29][64],bitmap[29][65],bitmap[29][66],bitmap[29][67],bitmap[29][68],bitmap[29][69],bitmap[29][70],bitmap[29][71],bitmap[29][72],bitmap[29][73],bitmap[29][74],bitmap[29][75],bitmap[29][76],bitmap[29][77],bitmap[29][78],bitmap[29][79],bitmap[29][80],bitmap[29][81],bitmap[29][82],bitmap[29][83],bitmap[29][84],bitmap[29][85],bitmap[29][86],bitmap[29][87],bitmap[29][88],bitmap[29][89],bitmap[29][90],bitmap[29][91],bitmap[29][92],bitmap[29][93],bitmap[29][94],bitmap[29][95],
					bitmap[30][0],bitmap[30][1],bitmap[30][2],bitmap[30][3],bitmap[30][4],bitmap[30][5],bitmap[30][6],bitmap[30][7],bitmap[30][8],bitmap[30][9],bitmap[30][10],bitmap[30][11],bitmap[30][12],bitmap[30][13],bitmap[30][14],bitmap[30][15],bitmap[30][16],bitmap[30][17],bitmap[30][18],bitmap[30][19],bitmap[30][20],bitmap[30][21],bitmap[30][22],bitmap[30][23],bitmap[30][24],bitmap[30][25],bitmap[30][26],bitmap[30][27],bitmap[30][28],bitmap[30][29],bitmap[30][30],bitmap[30][31],bitmap[30][32],bitmap[30][33],bitmap[30][34],bitmap[30][35],bitmap[30][36],bitmap[30][37],bitmap[30][38],bitmap[30][39],bitmap[30][40],bitmap[30][41],bitmap[30][42],bitmap[30][43],bitmap[30][44],bitmap[30][45],bitmap[30][46],bitmap[30][47],bitmap[30][48],bitmap[30][49],bitmap[30][50],bitmap[30][51],bitmap[30][52],bitmap[30][53],bitmap[30][54],bitmap[30][55],bitmap[30][56],bitmap[30][57],bitmap[30][58],bitmap[30][59],bitmap[30][60],bitmap[30][61],bitmap[30][62],bitmap[30][63],bitmap[30][64],bitmap[30][65],bitmap[30][66],bitmap[30][67],bitmap[30][68],bitmap[30][69],bitmap[30][70],bitmap[30][71],bitmap[30][72],bitmap[30][73],bitmap[30][74],bitmap[30][75],bitmap[30][76],bitmap[30][77],bitmap[30][78],bitmap[30][79],bitmap[30][80],bitmap[30][81],bitmap[30][82],bitmap[30][83],bitmap[30][84],bitmap[30][85],bitmap[30][86],bitmap[30][87],bitmap[30][88],bitmap[30][89],bitmap[30][90],bitmap[30][91],bitmap[30][92],bitmap[30][93],bitmap[30][94],bitmap[30][95],
					bitmap[31][0],bitmap[31][1],bitmap[31][2],bitmap[31][3],bitmap[31][4],bitmap[31][5],bitmap[31][6],bitmap[31][7],bitmap[31][8],bitmap[31][9],bitmap[31][10],bitmap[31][11],bitmap[31][12],bitmap[31][13],bitmap[31][14],bitmap[31][15],bitmap[31][16],bitmap[31][17],bitmap[31][18],bitmap[31][19],bitmap[31][20],bitmap[31][21],bitmap[31][22],bitmap[31][23],bitmap[31][24],bitmap[31][25],bitmap[31][26],bitmap[31][27],bitmap[31][28],bitmap[31][29],bitmap[31][30],bitmap[31][31],bitmap[31][32],bitmap[31][33],bitmap[31][34],bitmap[31][35],bitmap[31][36],bitmap[31][37],bitmap[31][38],bitmap[31][39],bitmap[31][40],bitmap[31][41],bitmap[31][42],bitmap[31][43],bitmap[31][44],bitmap[31][45],bitmap[31][46],bitmap[31][47],bitmap[31][48],bitmap[31][49],bitmap[31][50],bitmap[31][51],bitmap[31][52],bitmap[31][53],bitmap[31][54],bitmap[31][55],bitmap[31][56],bitmap[31][57],bitmap[31][58],bitmap[31][59],bitmap[31][60],bitmap[31][61],bitmap[31][62],bitmap[31][63],bitmap[31][64],bitmap[31][65],bitmap[31][66],bitmap[31][67],bitmap[31][68],bitmap[31][69],bitmap[31][70],bitmap[31][71],bitmap[31][72],bitmap[31][73],bitmap[31][74],bitmap[31][75],bitmap[31][76],bitmap[31][77],bitmap[31][78],bitmap[31][79],bitmap[31][80],bitmap[31][81],bitmap[31][82],bitmap[31][83],bitmap[31][84],bitmap[31][85],bitmap[31][86],bitmap[31][87],bitmap[31][88],bitmap[31][89],bitmap[31][90],bitmap[31][91],bitmap[31][92],bitmap[31][93],bitmap[31][94],bitmap[31][95],
					bitmap[32][0],bitmap[32][1],bitmap[32][2],bitmap[32][3],bitmap[32][4],bitmap[32][5],bitmap[32][6],bitmap[32][7],bitmap[32][8],bitmap[32][9],bitmap[32][10],bitmap[32][11],bitmap[32][12],bitmap[32][13],bitmap[32][14],bitmap[32][15],bitmap[32][16],bitmap[32][17],bitmap[32][18],bitmap[32][19],bitmap[32][20],bitmap[32][21],bitmap[32][22],bitmap[32][23],bitmap[32][24],bitmap[32][25],bitmap[32][26],bitmap[32][27],bitmap[32][28],bitmap[32][29],bitmap[32][30],bitmap[32][31],bitmap[32][32],bitmap[32][33],bitmap[32][34],bitmap[32][35],bitmap[32][36],bitmap[32][37],bitmap[32][38],bitmap[32][39],bitmap[32][40],bitmap[32][41],bitmap[32][42],bitmap[32][43],bitmap[32][44],bitmap[32][45],bitmap[32][46],bitmap[32][47],bitmap[32][48],bitmap[32][49],bitmap[32][50],bitmap[32][51],bitmap[32][52],bitmap[32][53],bitmap[32][54],bitmap[32][55],bitmap[32][56],bitmap[32][57],bitmap[32][58],bitmap[32][59],bitmap[32][60],bitmap[32][61],bitmap[32][62],bitmap[32][63],bitmap[32][64],bitmap[32][65],bitmap[32][66],bitmap[32][67],bitmap[32][68],bitmap[32][69],bitmap[32][70],bitmap[32][71],bitmap[32][72],bitmap[32][73],bitmap[32][74],bitmap[32][75],bitmap[32][76],bitmap[32][77],bitmap[32][78],bitmap[32][79],bitmap[32][80],bitmap[32][81],bitmap[32][82],bitmap[32][83],bitmap[32][84],bitmap[32][85],bitmap[32][86],bitmap[32][87],bitmap[32][88],bitmap[32][89],bitmap[32][90],bitmap[32][91],bitmap[32][92],bitmap[32][93],bitmap[32][94],bitmap[32][95],
					bitmap[33][0],bitmap[33][1],bitmap[33][2],bitmap[33][3],bitmap[33][4],bitmap[33][5],bitmap[33][6],bitmap[33][7],bitmap[33][8],bitmap[33][9],bitmap[33][10],bitmap[33][11],bitmap[33][12],bitmap[33][13],bitmap[33][14],bitmap[33][15],bitmap[33][16],bitmap[33][17],bitmap[33][18],bitmap[33][19],bitmap[33][20],bitmap[33][21],bitmap[33][22],bitmap[33][23],bitmap[33][24],bitmap[33][25],bitmap[33][26],bitmap[33][27],bitmap[33][28],bitmap[33][29],bitmap[33][30],bitmap[33][31],bitmap[33][32],bitmap[33][33],bitmap[33][34],bitmap[33][35],bitmap[33][36],bitmap[33][37],bitmap[33][38],bitmap[33][39],bitmap[33][40],bitmap[33][41],bitmap[33][42],bitmap[33][43],bitmap[33][44],bitmap[33][45],bitmap[33][46],bitmap[33][47],bitmap[33][48],bitmap[33][49],bitmap[33][50],bitmap[33][51],bitmap[33][52],bitmap[33][53],bitmap[33][54],bitmap[33][55],bitmap[33][56],bitmap[33][57],bitmap[33][58],bitmap[33][59],bitmap[33][60],bitmap[33][61],bitmap[33][62],bitmap[33][63],bitmap[33][64],bitmap[33][65],bitmap[33][66],bitmap[33][67],bitmap[33][68],bitmap[33][69],bitmap[33][70],bitmap[33][71],bitmap[33][72],bitmap[33][73],bitmap[33][74],bitmap[33][75],bitmap[33][76],bitmap[33][77],bitmap[33][78],bitmap[33][79],bitmap[33][80],bitmap[33][81],bitmap[33][82],bitmap[33][83],bitmap[33][84],bitmap[33][85],bitmap[33][86],bitmap[33][87],bitmap[33][88],bitmap[33][89],bitmap[33][90],bitmap[33][91],bitmap[33][92],bitmap[33][93],bitmap[33][94],bitmap[33][95],
					bitmap[34][0],bitmap[34][1],bitmap[34][2],bitmap[34][3],bitmap[34][4],bitmap[34][5],bitmap[34][6],bitmap[34][7],bitmap[34][8],bitmap[34][9],bitmap[34][10],bitmap[34][11],bitmap[34][12],bitmap[34][13],bitmap[34][14],bitmap[34][15],bitmap[34][16],bitmap[34][17],bitmap[34][18],bitmap[34][19],bitmap[34][20],bitmap[34][21],bitmap[34][22],bitmap[34][23],bitmap[34][24],bitmap[34][25],bitmap[34][26],bitmap[34][27],bitmap[34][28],bitmap[34][29],bitmap[34][30],bitmap[34][31],bitmap[34][32],bitmap[34][33],bitmap[34][34],bitmap[34][35],bitmap[34][36],bitmap[34][37],bitmap[34][38],bitmap[34][39],bitmap[34][40],bitmap[34][41],bitmap[34][42],bitmap[34][43],bitmap[34][44],bitmap[34][45],bitmap[34][46],bitmap[34][47],bitmap[34][48],bitmap[34][49],bitmap[34][50],bitmap[34][51],bitmap[34][52],bitmap[34][53],bitmap[34][54],bitmap[34][55],bitmap[34][56],bitmap[34][57],bitmap[34][58],bitmap[34][59],bitmap[34][60],bitmap[34][61],bitmap[34][62],bitmap[34][63],bitmap[34][64],bitmap[34][65],bitmap[34][66],bitmap[34][67],bitmap[34][68],bitmap[34][69],bitmap[34][70],bitmap[34][71],bitmap[34][72],bitmap[34][73],bitmap[34][74],bitmap[34][75],bitmap[34][76],bitmap[34][77],bitmap[34][78],bitmap[34][79],bitmap[34][80],bitmap[34][81],bitmap[34][82],bitmap[34][83],bitmap[34][84],bitmap[34][85],bitmap[34][86],bitmap[34][87],bitmap[34][88],bitmap[34][89],bitmap[34][90],bitmap[34][91],bitmap[34][92],bitmap[34][93],bitmap[34][94],bitmap[34][95],
					bitmap[35][0],bitmap[35][1],bitmap[35][2],bitmap[35][3],bitmap[35][4],bitmap[35][5],bitmap[35][6],bitmap[35][7],bitmap[35][8],bitmap[35][9],bitmap[35][10],bitmap[35][11],bitmap[35][12],bitmap[35][13],bitmap[35][14],bitmap[35][15],bitmap[35][16],bitmap[35][17],bitmap[35][18],bitmap[35][19],bitmap[35][20],bitmap[35][21],bitmap[35][22],bitmap[35][23],bitmap[35][24],bitmap[35][25],bitmap[35][26],bitmap[35][27],bitmap[35][28],bitmap[35][29],bitmap[35][30],bitmap[35][31],bitmap[35][32],bitmap[35][33],bitmap[35][34],bitmap[35][35],bitmap[35][36],bitmap[35][37],bitmap[35][38],bitmap[35][39],bitmap[35][40],bitmap[35][41],bitmap[35][42],bitmap[35][43],bitmap[35][44],bitmap[35][45],bitmap[35][46],bitmap[35][47],bitmap[35][48],bitmap[35][49],bitmap[35][50],bitmap[35][51],bitmap[35][52],bitmap[35][53],bitmap[35][54],bitmap[35][55],bitmap[35][56],bitmap[35][57],bitmap[35][58],bitmap[35][59],bitmap[35][60],bitmap[35][61],bitmap[35][62],bitmap[35][63],bitmap[35][64],bitmap[35][65],bitmap[35][66],bitmap[35][67],bitmap[35][68],bitmap[35][69],bitmap[35][70],bitmap[35][71],bitmap[35][72],bitmap[35][73],bitmap[35][74],bitmap[35][75],bitmap[35][76],bitmap[35][77],bitmap[35][78],bitmap[35][79],bitmap[35][80],bitmap[35][81],bitmap[35][82],bitmap[35][83],bitmap[35][84],bitmap[35][85],bitmap[35][86],bitmap[35][87],bitmap[35][88],bitmap[35][89],bitmap[35][90],bitmap[35][91],bitmap[35][92],bitmap[35][93],bitmap[35][94],bitmap[35][95],
					bitmap[36][0],bitmap[36][1],bitmap[36][2],bitmap[36][3],bitmap[36][4],bitmap[36][5],bitmap[36][6],bitmap[36][7],bitmap[36][8],bitmap[36][9],bitmap[36][10],bitmap[36][11],bitmap[36][12],bitmap[36][13],bitmap[36][14],bitmap[36][15],bitmap[36][16],bitmap[36][17],bitmap[36][18],bitmap[36][19],bitmap[36][20],bitmap[36][21],bitmap[36][22],bitmap[36][23],bitmap[36][24],bitmap[36][25],bitmap[36][26],bitmap[36][27],bitmap[36][28],bitmap[36][29],bitmap[36][30],bitmap[36][31],bitmap[36][32],bitmap[36][33],bitmap[36][34],bitmap[36][35],bitmap[36][36],bitmap[36][37],bitmap[36][38],bitmap[36][39],bitmap[36][40],bitmap[36][41],bitmap[36][42],bitmap[36][43],bitmap[36][44],bitmap[36][45],bitmap[36][46],bitmap[36][47],bitmap[36][48],bitmap[36][49],bitmap[36][50],bitmap[36][51],bitmap[36][52],bitmap[36][53],bitmap[36][54],bitmap[36][55],bitmap[36][56],bitmap[36][57],bitmap[36][58],bitmap[36][59],bitmap[36][60],bitmap[36][61],bitmap[36][62],bitmap[36][63],bitmap[36][64],bitmap[36][65],bitmap[36][66],bitmap[36][67],bitmap[36][68],bitmap[36][69],bitmap[36][70],bitmap[36][71],bitmap[36][72],bitmap[36][73],bitmap[36][74],bitmap[36][75],bitmap[36][76],bitmap[36][77],bitmap[36][78],bitmap[36][79],bitmap[36][80],bitmap[36][81],bitmap[36][82],bitmap[36][83],bitmap[36][84],bitmap[36][85],bitmap[36][86],bitmap[36][87],bitmap[36][88],bitmap[36][89],bitmap[36][90],bitmap[36][91],bitmap[36][92],bitmap[36][93],bitmap[36][94],bitmap[36][95],
					bitmap[37][0],bitmap[37][1],bitmap[37][2],bitmap[37][3],bitmap[37][4],bitmap[37][5],bitmap[37][6],bitmap[37][7],bitmap[37][8],bitmap[37][9],bitmap[37][10],bitmap[37][11],bitmap[37][12],bitmap[37][13],bitmap[37][14],bitmap[37][15],bitmap[37][16],bitmap[37][17],bitmap[37][18],bitmap[37][19],bitmap[37][20],bitmap[37][21],bitmap[37][22],bitmap[37][23],bitmap[37][24],bitmap[37][25],bitmap[37][26],bitmap[37][27],bitmap[37][28],bitmap[37][29],bitmap[37][30],bitmap[37][31],bitmap[37][32],bitmap[37][33],bitmap[37][34],bitmap[37][35],bitmap[37][36],bitmap[37][37],bitmap[37][38],bitmap[37][39],bitmap[37][40],bitmap[37][41],bitmap[37][42],bitmap[37][43],bitmap[37][44],bitmap[37][45],bitmap[37][46],bitmap[37][47],bitmap[37][48],bitmap[37][49],bitmap[37][50],bitmap[37][51],bitmap[37][52],bitmap[37][53],bitmap[37][54],bitmap[37][55],bitmap[37][56],bitmap[37][57],bitmap[37][58],bitmap[37][59],bitmap[37][60],bitmap[37][61],bitmap[37][62],bitmap[37][63],bitmap[37][64],bitmap[37][65],bitmap[37][66],bitmap[37][67],bitmap[37][68],bitmap[37][69],bitmap[37][70],bitmap[37][71],bitmap[37][72],bitmap[37][73],bitmap[37][74],bitmap[37][75],bitmap[37][76],bitmap[37][77],bitmap[37][78],bitmap[37][79],bitmap[37][80],bitmap[37][81],bitmap[37][82],bitmap[37][83],bitmap[37][84],bitmap[37][85],bitmap[37][86],bitmap[37][87],bitmap[37][88],bitmap[37][89],bitmap[37][90],bitmap[37][91],bitmap[37][92],bitmap[37][93],bitmap[37][94],bitmap[37][95],
					bitmap[38][0],bitmap[38][1],bitmap[38][2],bitmap[38][3],bitmap[38][4],bitmap[38][5],bitmap[38][6],bitmap[38][7],bitmap[38][8],bitmap[38][9],bitmap[38][10],bitmap[38][11],bitmap[38][12],bitmap[38][13],bitmap[38][14],bitmap[38][15],bitmap[38][16],bitmap[38][17],bitmap[38][18],bitmap[38][19],bitmap[38][20],bitmap[38][21],bitmap[38][22],bitmap[38][23],bitmap[38][24],bitmap[38][25],bitmap[38][26],bitmap[38][27],bitmap[38][28],bitmap[38][29],bitmap[38][30],bitmap[38][31],bitmap[38][32],bitmap[38][33],bitmap[38][34],bitmap[38][35],bitmap[38][36],bitmap[38][37],bitmap[38][38],bitmap[38][39],bitmap[38][40],bitmap[38][41],bitmap[38][42],bitmap[38][43],bitmap[38][44],bitmap[38][45],bitmap[38][46],bitmap[38][47],bitmap[38][48],bitmap[38][49],bitmap[38][50],bitmap[38][51],bitmap[38][52],bitmap[38][53],bitmap[38][54],bitmap[38][55],bitmap[38][56],bitmap[38][57],bitmap[38][58],bitmap[38][59],bitmap[38][60],bitmap[38][61],bitmap[38][62],bitmap[38][63],bitmap[38][64],bitmap[38][65],bitmap[38][66],bitmap[38][67],bitmap[38][68],bitmap[38][69],bitmap[38][70],bitmap[38][71],bitmap[38][72],bitmap[38][73],bitmap[38][74],bitmap[38][75],bitmap[38][76],bitmap[38][77],bitmap[38][78],bitmap[38][79],bitmap[38][80],bitmap[38][81],bitmap[38][82],bitmap[38][83],bitmap[38][84],bitmap[38][85],bitmap[38][86],bitmap[38][87],bitmap[38][88],bitmap[38][89],bitmap[38][90],bitmap[38][91],bitmap[38][92],bitmap[38][93],bitmap[38][94],bitmap[38][95],
					bitmap[39][0],bitmap[39][1],bitmap[39][2],bitmap[39][3],bitmap[39][4],bitmap[39][5],bitmap[39][6],bitmap[39][7],bitmap[39][8],bitmap[39][9],bitmap[39][10],bitmap[39][11],bitmap[39][12],bitmap[39][13],bitmap[39][14],bitmap[39][15],bitmap[39][16],bitmap[39][17],bitmap[39][18],bitmap[39][19],bitmap[39][20],bitmap[39][21],bitmap[39][22],bitmap[39][23],bitmap[39][24],bitmap[39][25],bitmap[39][26],bitmap[39][27],bitmap[39][28],bitmap[39][29],bitmap[39][30],bitmap[39][31],bitmap[39][32],bitmap[39][33],bitmap[39][34],bitmap[39][35],bitmap[39][36],bitmap[39][37],bitmap[39][38],bitmap[39][39],bitmap[39][40],bitmap[39][41],bitmap[39][42],bitmap[39][43],bitmap[39][44],bitmap[39][45],bitmap[39][46],bitmap[39][47],bitmap[39][48],bitmap[39][49],bitmap[39][50],bitmap[39][51],bitmap[39][52],bitmap[39][53],bitmap[39][54],bitmap[39][55],bitmap[39][56],bitmap[39][57],bitmap[39][58],bitmap[39][59],bitmap[39][60],bitmap[39][61],bitmap[39][62],bitmap[39][63],bitmap[39][64],bitmap[39][65],bitmap[39][66],bitmap[39][67],bitmap[39][68],bitmap[39][69],bitmap[39][70],bitmap[39][71],bitmap[39][72],bitmap[39][73],bitmap[39][74],bitmap[39][75],bitmap[39][76],bitmap[39][77],bitmap[39][78],bitmap[39][79],bitmap[39][80],bitmap[39][81],bitmap[39][82],bitmap[39][83],bitmap[39][84],bitmap[39][85],bitmap[39][86],bitmap[39][87],bitmap[39][88],bitmap[39][89],bitmap[39][90],bitmap[39][91],bitmap[39][92],bitmap[39][93],bitmap[39][94],bitmap[39][95],
					bitmap[40][0],bitmap[40][1],bitmap[40][2],bitmap[40][3],bitmap[40][4],bitmap[40][5],bitmap[40][6],bitmap[40][7],bitmap[40][8],bitmap[40][9],bitmap[40][10],bitmap[40][11],bitmap[40][12],bitmap[40][13],bitmap[40][14],bitmap[40][15],bitmap[40][16],bitmap[40][17],bitmap[40][18],bitmap[40][19],bitmap[40][20],bitmap[40][21],bitmap[40][22],bitmap[40][23],bitmap[40][24],bitmap[40][25],bitmap[40][26],bitmap[40][27],bitmap[40][28],bitmap[40][29],bitmap[40][30],bitmap[40][31],bitmap[40][32],bitmap[40][33],bitmap[40][34],bitmap[40][35],bitmap[40][36],bitmap[40][37],bitmap[40][38],bitmap[40][39],bitmap[40][40],bitmap[40][41],bitmap[40][42],bitmap[40][43],bitmap[40][44],bitmap[40][45],bitmap[40][46],bitmap[40][47],bitmap[40][48],bitmap[40][49],bitmap[40][50],bitmap[40][51],bitmap[40][52],bitmap[40][53],bitmap[40][54],bitmap[40][55],bitmap[40][56],bitmap[40][57],bitmap[40][58],bitmap[40][59],bitmap[40][60],bitmap[40][61],bitmap[40][62],bitmap[40][63],bitmap[40][64],bitmap[40][65],bitmap[40][66],bitmap[40][67],bitmap[40][68],bitmap[40][69],bitmap[40][70],bitmap[40][71],bitmap[40][72],bitmap[40][73],bitmap[40][74],bitmap[40][75],bitmap[40][76],bitmap[40][77],bitmap[40][78],bitmap[40][79],bitmap[40][80],bitmap[40][81],bitmap[40][82],bitmap[40][83],bitmap[40][84],bitmap[40][85],bitmap[40][86],bitmap[40][87],bitmap[40][88],bitmap[40][89],bitmap[40][90],bitmap[40][91],bitmap[40][92],bitmap[40][93],bitmap[40][94],bitmap[40][95],
					bitmap[41][0],bitmap[41][1],bitmap[41][2],bitmap[41][3],bitmap[41][4],bitmap[41][5],bitmap[41][6],bitmap[41][7],bitmap[41][8],bitmap[41][9],bitmap[41][10],bitmap[41][11],bitmap[41][12],bitmap[41][13],bitmap[41][14],bitmap[41][15],bitmap[41][16],bitmap[41][17],bitmap[41][18],bitmap[41][19],bitmap[41][20],bitmap[41][21],bitmap[41][22],bitmap[41][23],bitmap[41][24],bitmap[41][25],bitmap[41][26],bitmap[41][27],bitmap[41][28],bitmap[41][29],bitmap[41][30],bitmap[41][31],bitmap[41][32],bitmap[41][33],bitmap[41][34],bitmap[41][35],bitmap[41][36],bitmap[41][37],bitmap[41][38],bitmap[41][39],bitmap[41][40],bitmap[41][41],bitmap[41][42],bitmap[41][43],bitmap[41][44],bitmap[41][45],bitmap[41][46],bitmap[41][47],bitmap[41][48],bitmap[41][49],bitmap[41][50],bitmap[41][51],bitmap[41][52],bitmap[41][53],bitmap[41][54],bitmap[41][55],bitmap[41][56],bitmap[41][57],bitmap[41][58],bitmap[41][59],bitmap[41][60],bitmap[41][61],bitmap[41][62],bitmap[41][63],bitmap[41][64],bitmap[41][65],bitmap[41][66],bitmap[41][67],bitmap[41][68],bitmap[41][69],bitmap[41][70],bitmap[41][71],bitmap[41][72],bitmap[41][73],bitmap[41][74],bitmap[41][75],bitmap[41][76],bitmap[41][77],bitmap[41][78],bitmap[41][79],bitmap[41][80],bitmap[41][81],bitmap[41][82],bitmap[41][83],bitmap[41][84],bitmap[41][85],bitmap[41][86],bitmap[41][87],bitmap[41][88],bitmap[41][89],bitmap[41][90],bitmap[41][91],bitmap[41][92],bitmap[41][93],bitmap[41][94],bitmap[41][95],
					bitmap[42][0],bitmap[42][1],bitmap[42][2],bitmap[42][3],bitmap[42][4],bitmap[42][5],bitmap[42][6],bitmap[42][7],bitmap[42][8],bitmap[42][9],bitmap[42][10],bitmap[42][11],bitmap[42][12],bitmap[42][13],bitmap[42][14],bitmap[42][15],bitmap[42][16],bitmap[42][17],bitmap[42][18],bitmap[42][19],bitmap[42][20],bitmap[42][21],bitmap[42][22],bitmap[42][23],bitmap[42][24],bitmap[42][25],bitmap[42][26],bitmap[42][27],bitmap[42][28],bitmap[42][29],bitmap[42][30],bitmap[42][31],bitmap[42][32],bitmap[42][33],bitmap[42][34],bitmap[42][35],bitmap[42][36],bitmap[42][37],bitmap[42][38],bitmap[42][39],bitmap[42][40],bitmap[42][41],bitmap[42][42],bitmap[42][43],bitmap[42][44],bitmap[42][45],bitmap[42][46],bitmap[42][47],bitmap[42][48],bitmap[42][49],bitmap[42][50],bitmap[42][51],bitmap[42][52],bitmap[42][53],bitmap[42][54],bitmap[42][55],bitmap[42][56],bitmap[42][57],bitmap[42][58],bitmap[42][59],bitmap[42][60],bitmap[42][61],bitmap[42][62],bitmap[42][63],bitmap[42][64],bitmap[42][65],bitmap[42][66],bitmap[42][67],bitmap[42][68],bitmap[42][69],bitmap[42][70],bitmap[42][71],bitmap[42][72],bitmap[42][73],bitmap[42][74],bitmap[42][75],bitmap[42][76],bitmap[42][77],bitmap[42][78],bitmap[42][79],bitmap[42][80],bitmap[42][81],bitmap[42][82],bitmap[42][83],bitmap[42][84],bitmap[42][85],bitmap[42][86],bitmap[42][87],bitmap[42][88],bitmap[42][89],bitmap[42][90],bitmap[42][91],bitmap[42][92],bitmap[42][93],bitmap[42][94],bitmap[42][95],
					bitmap[43][0],bitmap[43][1],bitmap[43][2],bitmap[43][3],bitmap[43][4],bitmap[43][5],bitmap[43][6],bitmap[43][7],bitmap[43][8],bitmap[43][9],bitmap[43][10],bitmap[43][11],bitmap[43][12],bitmap[43][13],bitmap[43][14],bitmap[43][15],bitmap[43][16],bitmap[43][17],bitmap[43][18],bitmap[43][19],bitmap[43][20],bitmap[43][21],bitmap[43][22],bitmap[43][23],bitmap[43][24],bitmap[43][25],bitmap[43][26],bitmap[43][27],bitmap[43][28],bitmap[43][29],bitmap[43][30],bitmap[43][31],bitmap[43][32],bitmap[43][33],bitmap[43][34],bitmap[43][35],bitmap[43][36],bitmap[43][37],bitmap[43][38],bitmap[43][39],bitmap[43][40],bitmap[43][41],bitmap[43][42],bitmap[43][43],bitmap[43][44],bitmap[43][45],bitmap[43][46],bitmap[43][47],bitmap[43][48],bitmap[43][49],bitmap[43][50],bitmap[43][51],bitmap[43][52],bitmap[43][53],bitmap[43][54],bitmap[43][55],bitmap[43][56],bitmap[43][57],bitmap[43][58],bitmap[43][59],bitmap[43][60],bitmap[43][61],bitmap[43][62],bitmap[43][63],bitmap[43][64],bitmap[43][65],bitmap[43][66],bitmap[43][67],bitmap[43][68],bitmap[43][69],bitmap[43][70],bitmap[43][71],bitmap[43][72],bitmap[43][73],bitmap[43][74],bitmap[43][75],bitmap[43][76],bitmap[43][77],bitmap[43][78],bitmap[43][79],bitmap[43][80],bitmap[43][81],bitmap[43][82],bitmap[43][83],bitmap[43][84],bitmap[43][85],bitmap[43][86],bitmap[43][87],bitmap[43][88],bitmap[43][89],bitmap[43][90],bitmap[43][91],bitmap[43][92],bitmap[43][93],bitmap[43][94],bitmap[43][95],
					bitmap[44][0],bitmap[44][1],bitmap[44][2],bitmap[44][3],bitmap[44][4],bitmap[44][5],bitmap[44][6],bitmap[44][7],bitmap[44][8],bitmap[44][9],bitmap[44][10],bitmap[44][11],bitmap[44][12],bitmap[44][13],bitmap[44][14],bitmap[44][15],bitmap[44][16],bitmap[44][17],bitmap[44][18],bitmap[44][19],bitmap[44][20],bitmap[44][21],bitmap[44][22],bitmap[44][23],bitmap[44][24],bitmap[44][25],bitmap[44][26],bitmap[44][27],bitmap[44][28],bitmap[44][29],bitmap[44][30],bitmap[44][31],bitmap[44][32],bitmap[44][33],bitmap[44][34],bitmap[44][35],bitmap[44][36],bitmap[44][37],bitmap[44][38],bitmap[44][39],bitmap[44][40],bitmap[44][41],bitmap[44][42],bitmap[44][43],bitmap[44][44],bitmap[44][45],bitmap[44][46],bitmap[44][47],bitmap[44][48],bitmap[44][49],bitmap[44][50],bitmap[44][51],bitmap[44][52],bitmap[44][53],bitmap[44][54],bitmap[44][55],bitmap[44][56],bitmap[44][57],bitmap[44][58],bitmap[44][59],bitmap[44][60],bitmap[44][61],bitmap[44][62],bitmap[44][63],bitmap[44][64],bitmap[44][65],bitmap[44][66],bitmap[44][67],bitmap[44][68],bitmap[44][69],bitmap[44][70],bitmap[44][71],bitmap[44][72],bitmap[44][73],bitmap[44][74],bitmap[44][75],bitmap[44][76],bitmap[44][77],bitmap[44][78],bitmap[44][79],bitmap[44][80],bitmap[44][81],bitmap[44][82],bitmap[44][83],bitmap[44][84],bitmap[44][85],bitmap[44][86],bitmap[44][87],bitmap[44][88],bitmap[44][89],bitmap[44][90],bitmap[44][91],bitmap[44][92],bitmap[44][93],bitmap[44][94],bitmap[44][95],
					bitmap[45][0],bitmap[45][1],bitmap[45][2],bitmap[45][3],bitmap[45][4],bitmap[45][5],bitmap[45][6],bitmap[45][7],bitmap[45][8],bitmap[45][9],bitmap[45][10],bitmap[45][11],bitmap[45][12],bitmap[45][13],bitmap[45][14],bitmap[45][15],bitmap[45][16],bitmap[45][17],bitmap[45][18],bitmap[45][19],bitmap[45][20],bitmap[45][21],bitmap[45][22],bitmap[45][23],bitmap[45][24],bitmap[45][25],bitmap[45][26],bitmap[45][27],bitmap[45][28],bitmap[45][29],bitmap[45][30],bitmap[45][31],bitmap[45][32],bitmap[45][33],bitmap[45][34],bitmap[45][35],bitmap[45][36],bitmap[45][37],bitmap[45][38],bitmap[45][39],bitmap[45][40],bitmap[45][41],bitmap[45][42],bitmap[45][43],bitmap[45][44],bitmap[45][45],bitmap[45][46],bitmap[45][47],bitmap[45][48],bitmap[45][49],bitmap[45][50],bitmap[45][51],bitmap[45][52],bitmap[45][53],bitmap[45][54],bitmap[45][55],bitmap[45][56],bitmap[45][57],bitmap[45][58],bitmap[45][59],bitmap[45][60],bitmap[45][61],bitmap[45][62],bitmap[45][63],bitmap[45][64],bitmap[45][65],bitmap[45][66],bitmap[45][67],bitmap[45][68],bitmap[45][69],bitmap[45][70],bitmap[45][71],bitmap[45][72],bitmap[45][73],bitmap[45][74],bitmap[45][75],bitmap[45][76],bitmap[45][77],bitmap[45][78],bitmap[45][79],bitmap[45][80],bitmap[45][81],bitmap[45][82],bitmap[45][83],bitmap[45][84],bitmap[45][85],bitmap[45][86],bitmap[45][87],bitmap[45][88],bitmap[45][89],bitmap[45][90],bitmap[45][91],bitmap[45][92],bitmap[45][93],bitmap[45][94],bitmap[45][95],
					bitmap[46][0],bitmap[46][1],bitmap[46][2],bitmap[46][3],bitmap[46][4],bitmap[46][5],bitmap[46][6],bitmap[46][7],bitmap[46][8],bitmap[46][9],bitmap[46][10],bitmap[46][11],bitmap[46][12],bitmap[46][13],bitmap[46][14],bitmap[46][15],bitmap[46][16],bitmap[46][17],bitmap[46][18],bitmap[46][19],bitmap[46][20],bitmap[46][21],bitmap[46][22],bitmap[46][23],bitmap[46][24],bitmap[46][25],bitmap[46][26],bitmap[46][27],bitmap[46][28],bitmap[46][29],bitmap[46][30],bitmap[46][31],bitmap[46][32],bitmap[46][33],bitmap[46][34],bitmap[46][35],bitmap[46][36],bitmap[46][37],bitmap[46][38],bitmap[46][39],bitmap[46][40],bitmap[46][41],bitmap[46][42],bitmap[46][43],bitmap[46][44],bitmap[46][45],bitmap[46][46],bitmap[46][47],bitmap[46][48],bitmap[46][49],bitmap[46][50],bitmap[46][51],bitmap[46][52],bitmap[46][53],bitmap[46][54],bitmap[46][55],bitmap[46][56],bitmap[46][57],bitmap[46][58],bitmap[46][59],bitmap[46][60],bitmap[46][61],bitmap[46][62],bitmap[46][63],bitmap[46][64],bitmap[46][65],bitmap[46][66],bitmap[46][67],bitmap[46][68],bitmap[46][69],bitmap[46][70],bitmap[46][71],bitmap[46][72],bitmap[46][73],bitmap[46][74],bitmap[46][75],bitmap[46][76],bitmap[46][77],bitmap[46][78],bitmap[46][79],bitmap[46][80],bitmap[46][81],bitmap[46][82],bitmap[46][83],bitmap[46][84],bitmap[46][85],bitmap[46][86],bitmap[46][87],bitmap[46][88],bitmap[46][89],bitmap[46][90],bitmap[46][91],bitmap[46][92],bitmap[46][93],bitmap[46][94],bitmap[46][95],
					bitmap[47][0],bitmap[47][1],bitmap[47][2],bitmap[47][3],bitmap[47][4],bitmap[47][5],bitmap[47][6],bitmap[47][7],bitmap[47][8],bitmap[47][9],bitmap[47][10],bitmap[47][11],bitmap[47][12],bitmap[47][13],bitmap[47][14],bitmap[47][15],bitmap[47][16],bitmap[47][17],bitmap[47][18],bitmap[47][19],bitmap[47][20],bitmap[47][21],bitmap[47][22],bitmap[47][23],bitmap[47][24],bitmap[47][25],bitmap[47][26],bitmap[47][27],bitmap[47][28],bitmap[47][29],bitmap[47][30],bitmap[47][31],bitmap[47][32],bitmap[47][33],bitmap[47][34],bitmap[47][35],bitmap[47][36],bitmap[47][37],bitmap[47][38],bitmap[47][39],bitmap[47][40],bitmap[47][41],bitmap[47][42],bitmap[47][43],bitmap[47][44],bitmap[47][45],bitmap[47][46],bitmap[47][47],bitmap[47][48],bitmap[47][49],bitmap[47][50],bitmap[47][51],bitmap[47][52],bitmap[47][53],bitmap[47][54],bitmap[47][55],bitmap[47][56],bitmap[47][57],bitmap[47][58],bitmap[47][59],bitmap[47][60],bitmap[47][61],bitmap[47][62],bitmap[47][63],bitmap[47][64],bitmap[47][65],bitmap[47][66],bitmap[47][67],bitmap[47][68],bitmap[47][69],bitmap[47][70],bitmap[47][71],bitmap[47][72],bitmap[47][73],bitmap[47][74],bitmap[47][75],bitmap[47][76],bitmap[47][77],bitmap[47][78],bitmap[47][79],bitmap[47][80],bitmap[47][81],bitmap[47][82],bitmap[47][83],bitmap[47][84],bitmap[47][85],bitmap[47][86],bitmap[47][87],bitmap[47][88],bitmap[47][89],bitmap[47][90],bitmap[47][91],bitmap[47][92],bitmap[47][93],bitmap[47][94],bitmap[47][95]
			);*/
			
			fwrite(enregistrement,lengthSave,1,fichier);
			fclose(fichier); // On ferme le fichier
			return true;
		}
		// Si l'ouverture n'a pas fonctionné
		return false;
	}
	return false;
}

bool chargerBitmap() {
	FILE *fichier = NULL;
	fichier = fopen("fat:/BitmapWifi.sav"); //On ouvre le fichier

	//Si l'ouverture a fonctionnée
	if (fichier != NULL)
	{
		//int nombreFile[653];
		int temp;
		
		fscanf(fichier,"%01d %s ",&temp,&bitmap);
		
		/*fscanf(fichier, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s ",
					&bitmap[0],&bitmap[1],&bitmap[2],&bitmap[3],&bitmap[4],&bitmap[5],&bitmap[6],&bitmap[7],&bitmap[8],&bitmap[9],&bitmap[10],&bitmap[11],&bitmap[12],&bitmap[13],&bitmap[14],&bitmap[15],&bitmap[16],&bitmap[17],&bitmap[18],&bitmap[19],&bitmap[20],&bitmap[21],&bitmap[22],&bitmap[23],&bitmap[24],&bitmap[25],&bitmap[26],&bitmap[27],&bitmap[28],&bitmap[29],&bitmap[30],&bitmap[31],&bitmap[32],&bitmap[33],&bitmap[34],&bitmap[35],&bitmap[36],&bitmap[37],&bitmap[38],&bitmap[39],&bitmap[40],&bitmap[41],&bitmap[42],&bitmap[43],&bitmap[44],&bitmap[45],&bitmap[46],&bitmap[47]
		);*/
		
		/*fscanf(fichier, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c ",
					&bitmap[0][0],&bitmap[0][1],&bitmap[0][2],&bitmap[0][3],&bitmap[0][4],&bitmap[0][5],&bitmap[0][6],&bitmap[0][7],&bitmap[0][8],&bitmap[0][9],&bitmap[0][10],&bitmap[0][11],&bitmap[0][12],&bitmap[0][13],&bitmap[0][14],&bitmap[0][15],&bitmap[0][16],&bitmap[0][17],&bitmap[0][18],&bitmap[0][19],&bitmap[0][20],&bitmap[0][21],&bitmap[0][22],&bitmap[0][23],&bitmap[0][24],&bitmap[0][25],&bitmap[0][26],&bitmap[0][27],&bitmap[0][28],&bitmap[0][29],&bitmap[0][30],&bitmap[0][31],&bitmap[0][32],&bitmap[0][33],&bitmap[0][34],&bitmap[0][35],&bitmap[0][36],&bitmap[0][37],&bitmap[0][38],&bitmap[0][39],&bitmap[0][40],&bitmap[0][41],&bitmap[0][42],&bitmap[0][43],&bitmap[0][44],&bitmap[0][45],&bitmap[0][46],&bitmap[0][47],&bitmap[0][48],&bitmap[0][49],&bitmap[0][50],&bitmap[0][51],&bitmap[0][52],&bitmap[0][53],&bitmap[0][54],&bitmap[0][55],&bitmap[0][56],&bitmap[0][57],&bitmap[0][58],&bitmap[0][59],&bitmap[0][60],&bitmap[0][61],&bitmap[0][62],&bitmap[0][63],&bitmap[0][64],&bitmap[0][65],&bitmap[0][66],&bitmap[0][67],&bitmap[0][68],&bitmap[0][69],&bitmap[0][70],&bitmap[0][71],&bitmap[0][72],&bitmap[0][73],&bitmap[0][74],&bitmap[0][75],&bitmap[0][76],&bitmap[0][77],&bitmap[0][78],&bitmap[0][79],&bitmap[0][80],&bitmap[0][81],&bitmap[0][82],&bitmap[0][83],&bitmap[0][84],&bitmap[0][85],&bitmap[0][86],&bitmap[0][87],&bitmap[0][88],&bitmap[0][89],&bitmap[0][90],&bitmap[0][91],&bitmap[0][92],&bitmap[0][93],&bitmap[0][94],&bitmap[0][95],
					&bitmap[1][0],&bitmap[1][1],&bitmap[1][2],&bitmap[1][3],&bitmap[1][4],&bitmap[1][5],&bitmap[1][6],&bitmap[1][7],&bitmap[1][8],&bitmap[1][9],&bitmap[1][10],&bitmap[1][11],&bitmap[1][12],&bitmap[1][13],&bitmap[1][14],&bitmap[1][15],&bitmap[1][16],&bitmap[1][17],&bitmap[1][18],&bitmap[1][19],&bitmap[1][20],&bitmap[1][21],&bitmap[1][22],&bitmap[1][23],&bitmap[1][24],&bitmap[1][25],&bitmap[1][26],&bitmap[1][27],&bitmap[1][28],&bitmap[1][29],&bitmap[1][30],&bitmap[1][31],&bitmap[1][32],&bitmap[1][33],&bitmap[1][34],&bitmap[1][35],&bitmap[1][36],&bitmap[1][37],&bitmap[1][38],&bitmap[1][39],&bitmap[1][40],&bitmap[1][41],&bitmap[1][42],&bitmap[1][43],&bitmap[1][44],&bitmap[1][45],&bitmap[1][46],&bitmap[1][47],&bitmap[1][48],&bitmap[1][49],&bitmap[1][50],&bitmap[1][51],&bitmap[1][52],&bitmap[1][53],&bitmap[1][54],&bitmap[1][55],&bitmap[1][56],&bitmap[1][57],&bitmap[1][58],&bitmap[1][59],&bitmap[1][60],&bitmap[1][61],&bitmap[1][62],&bitmap[1][63],&bitmap[1][64],&bitmap[1][65],&bitmap[1][66],&bitmap[1][67],&bitmap[1][68],&bitmap[1][69],&bitmap[1][70],&bitmap[1][71],&bitmap[1][72],&bitmap[1][73],&bitmap[1][74],&bitmap[1][75],&bitmap[1][76],&bitmap[1][77],&bitmap[1][78],&bitmap[1][79],&bitmap[1][80],&bitmap[1][81],&bitmap[1][82],&bitmap[1][83],&bitmap[1][84],&bitmap[1][85],&bitmap[1][86],&bitmap[1][87],&bitmap[1][88],&bitmap[1][89],&bitmap[1][90],&bitmap[1][91],&bitmap[1][92],&bitmap[1][93],&bitmap[1][94],&bitmap[1][95],
					&bitmap[2][0],&bitmap[2][1],&bitmap[2][2],&bitmap[2][3],&bitmap[2][4],&bitmap[2][5],&bitmap[2][6],&bitmap[2][7],&bitmap[2][8],&bitmap[2][9],&bitmap[2][10],&bitmap[2][11],&bitmap[2][12],&bitmap[2][13],&bitmap[2][14],&bitmap[2][15],&bitmap[2][16],&bitmap[2][17],&bitmap[2][18],&bitmap[2][19],&bitmap[2][20],&bitmap[2][21],&bitmap[2][22],&bitmap[2][23],&bitmap[2][24],&bitmap[2][25],&bitmap[2][26],&bitmap[2][27],&bitmap[2][28],&bitmap[2][29],&bitmap[2][30],&bitmap[2][31],&bitmap[2][32],&bitmap[2][33],&bitmap[2][34],&bitmap[2][35],&bitmap[2][36],&bitmap[2][37],&bitmap[2][38],&bitmap[2][39],&bitmap[2][40],&bitmap[2][41],&bitmap[2][42],&bitmap[2][43],&bitmap[2][44],&bitmap[2][45],&bitmap[2][46],&bitmap[2][47],&bitmap[2][48],&bitmap[2][49],&bitmap[2][50],&bitmap[2][51],&bitmap[2][52],&bitmap[2][53],&bitmap[2][54],&bitmap[2][55],&bitmap[2][56],&bitmap[2][57],&bitmap[2][58],&bitmap[2][59],&bitmap[2][60],&bitmap[2][61],&bitmap[2][62],&bitmap[2][63],&bitmap[2][64],&bitmap[2][65],&bitmap[2][66],&bitmap[2][67],&bitmap[2][68],&bitmap[2][69],&bitmap[2][70],&bitmap[2][71],&bitmap[2][72],&bitmap[2][73],&bitmap[2][74],&bitmap[2][75],&bitmap[2][76],&bitmap[2][77],&bitmap[2][78],&bitmap[2][79],&bitmap[2][80],&bitmap[2][81],&bitmap[2][82],&bitmap[2][83],&bitmap[2][84],&bitmap[2][85],&bitmap[2][86],&bitmap[2][87],&bitmap[2][88],&bitmap[2][89],&bitmap[2][90],&bitmap[2][91],&bitmap[2][92],&bitmap[2][93],&bitmap[2][94],&bitmap[2][95],
					&bitmap[3][0],&bitmap[3][1],&bitmap[3][2],&bitmap[3][3],&bitmap[3][4],&bitmap[3][5],&bitmap[3][6],&bitmap[3][7],&bitmap[3][8],&bitmap[3][9],&bitmap[3][10],&bitmap[3][11],&bitmap[3][12],&bitmap[3][13],&bitmap[3][14],&bitmap[3][15],&bitmap[3][16],&bitmap[3][17],&bitmap[3][18],&bitmap[3][19],&bitmap[3][20],&bitmap[3][21],&bitmap[3][22],&bitmap[3][23],&bitmap[3][24],&bitmap[3][25],&bitmap[3][26],&bitmap[3][27],&bitmap[3][28],&bitmap[3][29],&bitmap[3][30],&bitmap[3][31],&bitmap[3][32],&bitmap[3][33],&bitmap[3][34],&bitmap[3][35],&bitmap[3][36],&bitmap[3][37],&bitmap[3][38],&bitmap[3][39],&bitmap[3][40],&bitmap[3][41],&bitmap[3][42],&bitmap[3][43],&bitmap[3][44],&bitmap[3][45],&bitmap[3][46],&bitmap[3][47],&bitmap[3][48],&bitmap[3][49],&bitmap[3][50],&bitmap[3][51],&bitmap[3][52],&bitmap[3][53],&bitmap[3][54],&bitmap[3][55],&bitmap[3][56],&bitmap[3][57],&bitmap[3][58],&bitmap[3][59],&bitmap[3][60],&bitmap[3][61],&bitmap[3][62],&bitmap[3][63],&bitmap[3][64],&bitmap[3][65],&bitmap[3][66],&bitmap[3][67],&bitmap[3][68],&bitmap[3][69],&bitmap[3][70],&bitmap[3][71],&bitmap[3][72],&bitmap[3][73],&bitmap[3][74],&bitmap[3][75],&bitmap[3][76],&bitmap[3][77],&bitmap[3][78],&bitmap[3][79],&bitmap[3][80],&bitmap[3][81],&bitmap[3][82],&bitmap[3][83],&bitmap[3][84],&bitmap[3][85],&bitmap[3][86],&bitmap[3][87],&bitmap[3][88],&bitmap[3][89],&bitmap[3][90],&bitmap[3][91],&bitmap[3][92],&bitmap[3][93],&bitmap[3][94],&bitmap[3][95],
					&bitmap[4][0],&bitmap[4][1],&bitmap[4][2],&bitmap[4][3],&bitmap[4][4],&bitmap[4][5],&bitmap[4][6],&bitmap[4][7],&bitmap[4][8],&bitmap[4][9],&bitmap[4][10],&bitmap[4][11],&bitmap[4][12],&bitmap[4][13],&bitmap[4][14],&bitmap[4][15],&bitmap[4][16],&bitmap[4][17],&bitmap[4][18],&bitmap[4][19],&bitmap[4][20],&bitmap[4][21],&bitmap[4][22],&bitmap[4][23],&bitmap[4][24],&bitmap[4][25],&bitmap[4][26],&bitmap[4][27],&bitmap[4][28],&bitmap[4][29],&bitmap[4][30],&bitmap[4][31],&bitmap[4][32],&bitmap[4][33],&bitmap[4][34],&bitmap[4][35],&bitmap[4][36],&bitmap[4][37],&bitmap[4][38],&bitmap[4][39],&bitmap[4][40],&bitmap[4][41],&bitmap[4][42],&bitmap[4][43],&bitmap[4][44],&bitmap[4][45],&bitmap[4][46],&bitmap[4][47],&bitmap[4][48],&bitmap[4][49],&bitmap[4][50],&bitmap[4][51],&bitmap[4][52],&bitmap[4][53],&bitmap[4][54],&bitmap[4][55],&bitmap[4][56],&bitmap[4][57],&bitmap[4][58],&bitmap[4][59],&bitmap[4][60],&bitmap[4][61],&bitmap[4][62],&bitmap[4][63],&bitmap[4][64],&bitmap[4][65],&bitmap[4][66],&bitmap[4][67],&bitmap[4][68],&bitmap[4][69],&bitmap[4][70],&bitmap[4][71],&bitmap[4][72],&bitmap[4][73],&bitmap[4][74],&bitmap[4][75],&bitmap[4][76],&bitmap[4][77],&bitmap[4][78],&bitmap[4][79],&bitmap[4][80],&bitmap[4][81],&bitmap[4][82],&bitmap[4][83],&bitmap[4][84],&bitmap[4][85],&bitmap[4][86],&bitmap[4][87],&bitmap[4][88],&bitmap[4][89],&bitmap[4][90],&bitmap[4][91],&bitmap[4][92],&bitmap[4][93],&bitmap[4][94],&bitmap[4][95],
					&bitmap[5][0],&bitmap[5][1],&bitmap[5][2],&bitmap[5][3],&bitmap[5][4],&bitmap[5][5],&bitmap[5][6],&bitmap[5][7],&bitmap[5][8],&bitmap[5][9],&bitmap[5][10],&bitmap[5][11],&bitmap[5][12],&bitmap[5][13],&bitmap[5][14],&bitmap[5][15],&bitmap[5][16],&bitmap[5][17],&bitmap[5][18],&bitmap[5][19],&bitmap[5][20],&bitmap[5][21],&bitmap[5][22],&bitmap[5][23],&bitmap[5][24],&bitmap[5][25],&bitmap[5][26],&bitmap[5][27],&bitmap[5][28],&bitmap[5][29],&bitmap[5][30],&bitmap[5][31],&bitmap[5][32],&bitmap[5][33],&bitmap[5][34],&bitmap[5][35],&bitmap[5][36],&bitmap[5][37],&bitmap[5][38],&bitmap[5][39],&bitmap[5][40],&bitmap[5][41],&bitmap[5][42],&bitmap[5][43],&bitmap[5][44],&bitmap[5][45],&bitmap[5][46],&bitmap[5][47],&bitmap[5][48],&bitmap[5][49],&bitmap[5][50],&bitmap[5][51],&bitmap[5][52],&bitmap[5][53],&bitmap[5][54],&bitmap[5][55],&bitmap[5][56],&bitmap[5][57],&bitmap[5][58],&bitmap[5][59],&bitmap[5][60],&bitmap[5][61],&bitmap[5][62],&bitmap[5][63],&bitmap[5][64],&bitmap[5][65],&bitmap[5][66],&bitmap[5][67],&bitmap[5][68],&bitmap[5][69],&bitmap[5][70],&bitmap[5][71],&bitmap[5][72],&bitmap[5][73],&bitmap[5][74],&bitmap[5][75],&bitmap[5][76],&bitmap[5][77],&bitmap[5][78],&bitmap[5][79],&bitmap[5][80],&bitmap[5][81],&bitmap[5][82],&bitmap[5][83],&bitmap[5][84],&bitmap[5][85],&bitmap[5][86],&bitmap[5][87],&bitmap[5][88],&bitmap[5][89],&bitmap[5][90],&bitmap[5][91],&bitmap[5][92],&bitmap[5][93],&bitmap[5][94],&bitmap[5][95],
					&bitmap[6][0],&bitmap[6][1],&bitmap[6][2],&bitmap[6][3],&bitmap[6][4],&bitmap[6][5],&bitmap[6][6],&bitmap[6][7],&bitmap[6][8],&bitmap[6][9],&bitmap[6][10],&bitmap[6][11],&bitmap[6][12],&bitmap[6][13],&bitmap[6][14],&bitmap[6][15],&bitmap[6][16],&bitmap[6][17],&bitmap[6][18],&bitmap[6][19],&bitmap[6][20],&bitmap[6][21],&bitmap[6][22],&bitmap[6][23],&bitmap[6][24],&bitmap[6][25],&bitmap[6][26],&bitmap[6][27],&bitmap[6][28],&bitmap[6][29],&bitmap[6][30],&bitmap[6][31],&bitmap[6][32],&bitmap[6][33],&bitmap[6][34],&bitmap[6][35],&bitmap[6][36],&bitmap[6][37],&bitmap[6][38],&bitmap[6][39],&bitmap[6][40],&bitmap[6][41],&bitmap[6][42],&bitmap[6][43],&bitmap[6][44],&bitmap[6][45],&bitmap[6][46],&bitmap[6][47],&bitmap[6][48],&bitmap[6][49],&bitmap[6][50],&bitmap[6][51],&bitmap[6][52],&bitmap[6][53],&bitmap[6][54],&bitmap[6][55],&bitmap[6][56],&bitmap[6][57],&bitmap[6][58],&bitmap[6][59],&bitmap[6][60],&bitmap[6][61],&bitmap[6][62],&bitmap[6][63],&bitmap[6][64],&bitmap[6][65],&bitmap[6][66],&bitmap[6][67],&bitmap[6][68],&bitmap[6][69],&bitmap[6][70],&bitmap[6][71],&bitmap[6][72],&bitmap[6][73],&bitmap[6][74],&bitmap[6][75],&bitmap[6][76],&bitmap[6][77],&bitmap[6][78],&bitmap[6][79],&bitmap[6][80],&bitmap[6][81],&bitmap[6][82],&bitmap[6][83],&bitmap[6][84],&bitmap[6][85],&bitmap[6][86],&bitmap[6][87],&bitmap[6][88],&bitmap[6][89],&bitmap[6][90],&bitmap[6][91],&bitmap[6][92],&bitmap[6][93],&bitmap[6][94],&bitmap[6][95],
					&bitmap[7][0],&bitmap[7][1],&bitmap[7][2],&bitmap[7][3],&bitmap[7][4],&bitmap[7][5],&bitmap[7][6],&bitmap[7][7],&bitmap[7][8],&bitmap[7][9],&bitmap[7][10],&bitmap[7][11],&bitmap[7][12],&bitmap[7][13],&bitmap[7][14],&bitmap[7][15],&bitmap[7][16],&bitmap[7][17],&bitmap[7][18],&bitmap[7][19],&bitmap[7][20],&bitmap[7][21],&bitmap[7][22],&bitmap[7][23],&bitmap[7][24],&bitmap[7][25],&bitmap[7][26],&bitmap[7][27],&bitmap[7][28],&bitmap[7][29],&bitmap[7][30],&bitmap[7][31],&bitmap[7][32],&bitmap[7][33],&bitmap[7][34],&bitmap[7][35],&bitmap[7][36],&bitmap[7][37],&bitmap[7][38],&bitmap[7][39],&bitmap[7][40],&bitmap[7][41],&bitmap[7][42],&bitmap[7][43],&bitmap[7][44],&bitmap[7][45],&bitmap[7][46],&bitmap[7][47],&bitmap[7][48],&bitmap[7][49],&bitmap[7][50],&bitmap[7][51],&bitmap[7][52],&bitmap[7][53],&bitmap[7][54],&bitmap[7][55],&bitmap[7][56],&bitmap[7][57],&bitmap[7][58],&bitmap[7][59],&bitmap[7][60],&bitmap[7][61],&bitmap[7][62],&bitmap[7][63],&bitmap[7][64],&bitmap[7][65],&bitmap[7][66],&bitmap[7][67],&bitmap[7][68],&bitmap[7][69],&bitmap[7][70],&bitmap[7][71],&bitmap[7][72],&bitmap[7][73],&bitmap[7][74],&bitmap[7][75],&bitmap[7][76],&bitmap[7][77],&bitmap[7][78],&bitmap[7][79],&bitmap[7][80],&bitmap[7][81],&bitmap[7][82],&bitmap[7][83],&bitmap[7][84],&bitmap[7][85],&bitmap[7][86],&bitmap[7][87],&bitmap[7][88],&bitmap[7][89],&bitmap[7][90],&bitmap[7][91],&bitmap[7][92],&bitmap[7][93],&bitmap[7][94],&bitmap[7][95],
					&bitmap[8][0],&bitmap[8][1],&bitmap[8][2],&bitmap[8][3],&bitmap[8][4],&bitmap[8][5],&bitmap[8][6],&bitmap[8][7],&bitmap[8][8],&bitmap[8][9],&bitmap[8][10],&bitmap[8][11],&bitmap[8][12],&bitmap[8][13],&bitmap[8][14],&bitmap[8][15],&bitmap[8][16],&bitmap[8][17],&bitmap[8][18],&bitmap[8][19],&bitmap[8][20],&bitmap[8][21],&bitmap[8][22],&bitmap[8][23],&bitmap[8][24],&bitmap[8][25],&bitmap[8][26],&bitmap[8][27],&bitmap[8][28],&bitmap[8][29],&bitmap[8][30],&bitmap[8][31],&bitmap[8][32],&bitmap[8][33],&bitmap[8][34],&bitmap[8][35],&bitmap[8][36],&bitmap[8][37],&bitmap[8][38],&bitmap[8][39],&bitmap[8][40],&bitmap[8][41],&bitmap[8][42],&bitmap[8][43],&bitmap[8][44],&bitmap[8][45],&bitmap[8][46],&bitmap[8][47],&bitmap[8][48],&bitmap[8][49],&bitmap[8][50],&bitmap[8][51],&bitmap[8][52],&bitmap[8][53],&bitmap[8][54],&bitmap[8][55],&bitmap[8][56],&bitmap[8][57],&bitmap[8][58],&bitmap[8][59],&bitmap[8][60],&bitmap[8][61],&bitmap[8][62],&bitmap[8][63],&bitmap[8][64],&bitmap[8][65],&bitmap[8][66],&bitmap[8][67],&bitmap[8][68],&bitmap[8][69],&bitmap[8][70],&bitmap[8][71],&bitmap[8][72],&bitmap[8][73],&bitmap[8][74],&bitmap[8][75],&bitmap[8][76],&bitmap[8][77],&bitmap[8][78],&bitmap[8][79],&bitmap[8][80],&bitmap[8][81],&bitmap[8][82],&bitmap[8][83],&bitmap[8][84],&bitmap[8][85],&bitmap[8][86],&bitmap[8][87],&bitmap[8][88],&bitmap[8][89],&bitmap[8][90],&bitmap[8][91],&bitmap[8][92],&bitmap[8][93],&bitmap[8][94],&bitmap[8][95],
					&bitmap[9][0],&bitmap[9][1],&bitmap[9][2],&bitmap[9][3],&bitmap[9][4],&bitmap[9][5],&bitmap[9][6],&bitmap[9][7],&bitmap[9][8],&bitmap[9][9],&bitmap[9][10],&bitmap[9][11],&bitmap[9][12],&bitmap[9][13],&bitmap[9][14],&bitmap[9][15],&bitmap[9][16],&bitmap[9][17],&bitmap[9][18],&bitmap[9][19],&bitmap[9][20],&bitmap[9][21],&bitmap[9][22],&bitmap[9][23],&bitmap[9][24],&bitmap[9][25],&bitmap[9][26],&bitmap[9][27],&bitmap[9][28],&bitmap[9][29],&bitmap[9][30],&bitmap[9][31],&bitmap[9][32],&bitmap[9][33],&bitmap[9][34],&bitmap[9][35],&bitmap[9][36],&bitmap[9][37],&bitmap[9][38],&bitmap[9][39],&bitmap[9][40],&bitmap[9][41],&bitmap[9][42],&bitmap[9][43],&bitmap[9][44],&bitmap[9][45],&bitmap[9][46],&bitmap[9][47],&bitmap[9][48],&bitmap[9][49],&bitmap[9][50],&bitmap[9][51],&bitmap[9][52],&bitmap[9][53],&bitmap[9][54],&bitmap[9][55],&bitmap[9][56],&bitmap[9][57],&bitmap[9][58],&bitmap[9][59],&bitmap[9][60],&bitmap[9][61],&bitmap[9][62],&bitmap[9][63],&bitmap[9][64],&bitmap[9][65],&bitmap[9][66],&bitmap[9][67],&bitmap[9][68],&bitmap[9][69],&bitmap[9][70],&bitmap[9][71],&bitmap[9][72],&bitmap[9][73],&bitmap[9][74],&bitmap[9][75],&bitmap[9][76],&bitmap[9][77],&bitmap[9][78],&bitmap[9][79],&bitmap[9][80],&bitmap[9][81],&bitmap[9][82],&bitmap[9][83],&bitmap[9][84],&bitmap[9][85],&bitmap[9][86],&bitmap[9][87],&bitmap[9][88],&bitmap[9][89],&bitmap[9][90],&bitmap[9][91],&bitmap[9][92],&bitmap[9][93],&bitmap[9][94],&bitmap[9][95],
					&bitmap[10][0],&bitmap[10][1],&bitmap[10][2],&bitmap[10][3],&bitmap[10][4],&bitmap[10][5],&bitmap[10][6],&bitmap[10][7],&bitmap[10][8],&bitmap[10][9],&bitmap[10][10],&bitmap[10][11],&bitmap[10][12],&bitmap[10][13],&bitmap[10][14],&bitmap[10][15],&bitmap[10][16],&bitmap[10][17],&bitmap[10][18],&bitmap[10][19],&bitmap[10][20],&bitmap[10][21],&bitmap[10][22],&bitmap[10][23],&bitmap[10][24],&bitmap[10][25],&bitmap[10][26],&bitmap[10][27],&bitmap[10][28],&bitmap[10][29],&bitmap[10][30],&bitmap[10][31],&bitmap[10][32],&bitmap[10][33],&bitmap[10][34],&bitmap[10][35],&bitmap[10][36],&bitmap[10][37],&bitmap[10][38],&bitmap[10][39],&bitmap[10][40],&bitmap[10][41],&bitmap[10][42],&bitmap[10][43],&bitmap[10][44],&bitmap[10][45],&bitmap[10][46],&bitmap[10][47],&bitmap[10][48],&bitmap[10][49],&bitmap[10][50],&bitmap[10][51],&bitmap[10][52],&bitmap[10][53],&bitmap[10][54],&bitmap[10][55],&bitmap[10][56],&bitmap[10][57],&bitmap[10][58],&bitmap[10][59],&bitmap[10][60],&bitmap[10][61],&bitmap[10][62],&bitmap[10][63],&bitmap[10][64],&bitmap[10][65],&bitmap[10][66],&bitmap[10][67],&bitmap[10][68],&bitmap[10][69],&bitmap[10][70],&bitmap[10][71],&bitmap[10][72],&bitmap[10][73],&bitmap[10][74],&bitmap[10][75],&bitmap[10][76],&bitmap[10][77],&bitmap[10][78],&bitmap[10][79],&bitmap[10][80],&bitmap[10][81],&bitmap[10][82],&bitmap[10][83],&bitmap[10][84],&bitmap[10][85],&bitmap[10][86],&bitmap[10][87],&bitmap[10][88],&bitmap[10][89],&bitmap[10][90],&bitmap[10][91],&bitmap[10][92],&bitmap[10][93],&bitmap[10][94],&bitmap[10][95],
					&bitmap[11][0],&bitmap[11][1],&bitmap[11][2],&bitmap[11][3],&bitmap[11][4],&bitmap[11][5],&bitmap[11][6],&bitmap[11][7],&bitmap[11][8],&bitmap[11][9],&bitmap[11][10],&bitmap[11][11],&bitmap[11][12],&bitmap[11][13],&bitmap[11][14],&bitmap[11][15],&bitmap[11][16],&bitmap[11][17],&bitmap[11][18],&bitmap[11][19],&bitmap[11][20],&bitmap[11][21],&bitmap[11][22],&bitmap[11][23],&bitmap[11][24],&bitmap[11][25],&bitmap[11][26],&bitmap[11][27],&bitmap[11][28],&bitmap[11][29],&bitmap[11][30],&bitmap[11][31],&bitmap[11][32],&bitmap[11][33],&bitmap[11][34],&bitmap[11][35],&bitmap[11][36],&bitmap[11][37],&bitmap[11][38],&bitmap[11][39],&bitmap[11][40],&bitmap[11][41],&bitmap[11][42],&bitmap[11][43],&bitmap[11][44],&bitmap[11][45],&bitmap[11][46],&bitmap[11][47],&bitmap[11][48],&bitmap[11][49],&bitmap[11][50],&bitmap[11][51],&bitmap[11][52],&bitmap[11][53],&bitmap[11][54],&bitmap[11][55],&bitmap[11][56],&bitmap[11][57],&bitmap[11][58],&bitmap[11][59],&bitmap[11][60],&bitmap[11][61],&bitmap[11][62],&bitmap[11][63],&bitmap[11][64],&bitmap[11][65],&bitmap[11][66],&bitmap[11][67],&bitmap[11][68],&bitmap[11][69],&bitmap[11][70],&bitmap[11][71],&bitmap[11][72],&bitmap[11][73],&bitmap[11][74],&bitmap[11][75],&bitmap[11][76],&bitmap[11][77],&bitmap[11][78],&bitmap[11][79],&bitmap[11][80],&bitmap[11][81],&bitmap[11][82],&bitmap[11][83],&bitmap[11][84],&bitmap[11][85],&bitmap[11][86],&bitmap[11][87],&bitmap[11][88],&bitmap[11][89],&bitmap[11][90],&bitmap[11][91],&bitmap[11][92],&bitmap[11][93],&bitmap[11][94],&bitmap[11][95],
					&bitmap[12][0],&bitmap[12][1],&bitmap[12][2],&bitmap[12][3],&bitmap[12][4],&bitmap[12][5],&bitmap[12][6],&bitmap[12][7],&bitmap[12][8],&bitmap[12][9],&bitmap[12][10],&bitmap[12][11],&bitmap[12][12],&bitmap[12][13],&bitmap[12][14],&bitmap[12][15],&bitmap[12][16],&bitmap[12][17],&bitmap[12][18],&bitmap[12][19],&bitmap[12][20],&bitmap[12][21],&bitmap[12][22],&bitmap[12][23],&bitmap[12][24],&bitmap[12][25],&bitmap[12][26],&bitmap[12][27],&bitmap[12][28],&bitmap[12][29],&bitmap[12][30],&bitmap[12][31],&bitmap[12][32],&bitmap[12][33],&bitmap[12][34],&bitmap[12][35],&bitmap[12][36],&bitmap[12][37],&bitmap[12][38],&bitmap[12][39],&bitmap[12][40],&bitmap[12][41],&bitmap[12][42],&bitmap[12][43],&bitmap[12][44],&bitmap[12][45],&bitmap[12][46],&bitmap[12][47],&bitmap[12][48],&bitmap[12][49],&bitmap[12][50],&bitmap[12][51],&bitmap[12][52],&bitmap[12][53],&bitmap[12][54],&bitmap[12][55],&bitmap[12][56],&bitmap[12][57],&bitmap[12][58],&bitmap[12][59],&bitmap[12][60],&bitmap[12][61],&bitmap[12][62],&bitmap[12][63],&bitmap[12][64],&bitmap[12][65],&bitmap[12][66],&bitmap[12][67],&bitmap[12][68],&bitmap[12][69],&bitmap[12][70],&bitmap[12][71],&bitmap[12][72],&bitmap[12][73],&bitmap[12][74],&bitmap[12][75],&bitmap[12][76],&bitmap[12][77],&bitmap[12][78],&bitmap[12][79],&bitmap[12][80],&bitmap[12][81],&bitmap[12][82],&bitmap[12][83],&bitmap[12][84],&bitmap[12][85],&bitmap[12][86],&bitmap[12][87],&bitmap[12][88],&bitmap[12][89],&bitmap[12][90],&bitmap[12][91],&bitmap[12][92],&bitmap[12][93],&bitmap[12][94],&bitmap[12][95],
					&bitmap[13][0],&bitmap[13][1],&bitmap[13][2],&bitmap[13][3],&bitmap[13][4],&bitmap[13][5],&bitmap[13][6],&bitmap[13][7],&bitmap[13][8],&bitmap[13][9],&bitmap[13][10],&bitmap[13][11],&bitmap[13][12],&bitmap[13][13],&bitmap[13][14],&bitmap[13][15],&bitmap[13][16],&bitmap[13][17],&bitmap[13][18],&bitmap[13][19],&bitmap[13][20],&bitmap[13][21],&bitmap[13][22],&bitmap[13][23],&bitmap[13][24],&bitmap[13][25],&bitmap[13][26],&bitmap[13][27],&bitmap[13][28],&bitmap[13][29],&bitmap[13][30],&bitmap[13][31],&bitmap[13][32],&bitmap[13][33],&bitmap[13][34],&bitmap[13][35],&bitmap[13][36],&bitmap[13][37],&bitmap[13][38],&bitmap[13][39],&bitmap[13][40],&bitmap[13][41],&bitmap[13][42],&bitmap[13][43],&bitmap[13][44],&bitmap[13][45],&bitmap[13][46],&bitmap[13][47],&bitmap[13][48],&bitmap[13][49],&bitmap[13][50],&bitmap[13][51],&bitmap[13][52],&bitmap[13][53],&bitmap[13][54],&bitmap[13][55],&bitmap[13][56],&bitmap[13][57],&bitmap[13][58],&bitmap[13][59],&bitmap[13][60],&bitmap[13][61],&bitmap[13][62],&bitmap[13][63],&bitmap[13][64],&bitmap[13][65],&bitmap[13][66],&bitmap[13][67],&bitmap[13][68],&bitmap[13][69],&bitmap[13][70],&bitmap[13][71],&bitmap[13][72],&bitmap[13][73],&bitmap[13][74],&bitmap[13][75],&bitmap[13][76],&bitmap[13][77],&bitmap[13][78],&bitmap[13][79],&bitmap[13][80],&bitmap[13][81],&bitmap[13][82],&bitmap[13][83],&bitmap[13][84],&bitmap[13][85],&bitmap[13][86],&bitmap[13][87],&bitmap[13][88],&bitmap[13][89],&bitmap[13][90],&bitmap[13][91],&bitmap[13][92],&bitmap[13][93],&bitmap[13][94],&bitmap[13][95],
					&bitmap[14][0],&bitmap[14][1],&bitmap[14][2],&bitmap[14][3],&bitmap[14][4],&bitmap[14][5],&bitmap[14][6],&bitmap[14][7],&bitmap[14][8],&bitmap[14][9],&bitmap[14][10],&bitmap[14][11],&bitmap[14][12],&bitmap[14][13],&bitmap[14][14],&bitmap[14][15],&bitmap[14][16],&bitmap[14][17],&bitmap[14][18],&bitmap[14][19],&bitmap[14][20],&bitmap[14][21],&bitmap[14][22],&bitmap[14][23],&bitmap[14][24],&bitmap[14][25],&bitmap[14][26],&bitmap[14][27],&bitmap[14][28],&bitmap[14][29],&bitmap[14][30],&bitmap[14][31],&bitmap[14][32],&bitmap[14][33],&bitmap[14][34],&bitmap[14][35],&bitmap[14][36],&bitmap[14][37],&bitmap[14][38],&bitmap[14][39],&bitmap[14][40],&bitmap[14][41],&bitmap[14][42],&bitmap[14][43],&bitmap[14][44],&bitmap[14][45],&bitmap[14][46],&bitmap[14][47],&bitmap[14][48],&bitmap[14][49],&bitmap[14][50],&bitmap[14][51],&bitmap[14][52],&bitmap[14][53],&bitmap[14][54],&bitmap[14][55],&bitmap[14][56],&bitmap[14][57],&bitmap[14][58],&bitmap[14][59],&bitmap[14][60],&bitmap[14][61],&bitmap[14][62],&bitmap[14][63],&bitmap[14][64],&bitmap[14][65],&bitmap[14][66],&bitmap[14][67],&bitmap[14][68],&bitmap[14][69],&bitmap[14][70],&bitmap[14][71],&bitmap[14][72],&bitmap[14][73],&bitmap[14][74],&bitmap[14][75],&bitmap[14][76],&bitmap[14][77],&bitmap[14][78],&bitmap[14][79],&bitmap[14][80],&bitmap[14][81],&bitmap[14][82],&bitmap[14][83],&bitmap[14][84],&bitmap[14][85],&bitmap[14][86],&bitmap[14][87],&bitmap[14][88],&bitmap[14][89],&bitmap[14][90],&bitmap[14][91],&bitmap[14][92],&bitmap[14][93],&bitmap[14][94],&bitmap[14][95],
					&bitmap[15][0],&bitmap[15][1],&bitmap[15][2],&bitmap[15][3],&bitmap[15][4],&bitmap[15][5],&bitmap[15][6],&bitmap[15][7],&bitmap[15][8],&bitmap[15][9],&bitmap[15][10],&bitmap[15][11],&bitmap[15][12],&bitmap[15][13],&bitmap[15][14],&bitmap[15][15],&bitmap[15][16],&bitmap[15][17],&bitmap[15][18],&bitmap[15][19],&bitmap[15][20],&bitmap[15][21],&bitmap[15][22],&bitmap[15][23],&bitmap[15][24],&bitmap[15][25],&bitmap[15][26],&bitmap[15][27],&bitmap[15][28],&bitmap[15][29],&bitmap[15][30],&bitmap[15][31],&bitmap[15][32],&bitmap[15][33],&bitmap[15][34],&bitmap[15][35],&bitmap[15][36],&bitmap[15][37],&bitmap[15][38],&bitmap[15][39],&bitmap[15][40],&bitmap[15][41],&bitmap[15][42],&bitmap[15][43],&bitmap[15][44],&bitmap[15][45],&bitmap[15][46],&bitmap[15][47],&bitmap[15][48],&bitmap[15][49],&bitmap[15][50],&bitmap[15][51],&bitmap[15][52],&bitmap[15][53],&bitmap[15][54],&bitmap[15][55],&bitmap[15][56],&bitmap[15][57],&bitmap[15][58],&bitmap[15][59],&bitmap[15][60],&bitmap[15][61],&bitmap[15][62],&bitmap[15][63],&bitmap[15][64],&bitmap[15][65],&bitmap[15][66],&bitmap[15][67],&bitmap[15][68],&bitmap[15][69],&bitmap[15][70],&bitmap[15][71],&bitmap[15][72],&bitmap[15][73],&bitmap[15][74],&bitmap[15][75],&bitmap[15][76],&bitmap[15][77],&bitmap[15][78],&bitmap[15][79],&bitmap[15][80],&bitmap[15][81],&bitmap[15][82],&bitmap[15][83],&bitmap[15][84],&bitmap[15][85],&bitmap[15][86],&bitmap[15][87],&bitmap[15][88],&bitmap[15][89],&bitmap[15][90],&bitmap[15][91],&bitmap[15][92],&bitmap[15][93],&bitmap[15][94],&bitmap[15][95],
					&bitmap[16][0],&bitmap[16][1],&bitmap[16][2],&bitmap[16][3],&bitmap[16][4],&bitmap[16][5],&bitmap[16][6],&bitmap[16][7],&bitmap[16][8],&bitmap[16][9],&bitmap[16][10],&bitmap[16][11],&bitmap[16][12],&bitmap[16][13],&bitmap[16][14],&bitmap[16][15],&bitmap[16][16],&bitmap[16][17],&bitmap[16][18],&bitmap[16][19],&bitmap[16][20],&bitmap[16][21],&bitmap[16][22],&bitmap[16][23],&bitmap[16][24],&bitmap[16][25],&bitmap[16][26],&bitmap[16][27],&bitmap[16][28],&bitmap[16][29],&bitmap[16][30],&bitmap[16][31],&bitmap[16][32],&bitmap[16][33],&bitmap[16][34],&bitmap[16][35],&bitmap[16][36],&bitmap[16][37],&bitmap[16][38],&bitmap[16][39],&bitmap[16][40],&bitmap[16][41],&bitmap[16][42],&bitmap[16][43],&bitmap[16][44],&bitmap[16][45],&bitmap[16][46],&bitmap[16][47],&bitmap[16][48],&bitmap[16][49],&bitmap[16][50],&bitmap[16][51],&bitmap[16][52],&bitmap[16][53],&bitmap[16][54],&bitmap[16][55],&bitmap[16][56],&bitmap[16][57],&bitmap[16][58],&bitmap[16][59],&bitmap[16][60],&bitmap[16][61],&bitmap[16][62],&bitmap[16][63],&bitmap[16][64],&bitmap[16][65],&bitmap[16][66],&bitmap[16][67],&bitmap[16][68],&bitmap[16][69],&bitmap[16][70],&bitmap[16][71],&bitmap[16][72],&bitmap[16][73],&bitmap[16][74],&bitmap[16][75],&bitmap[16][76],&bitmap[16][77],&bitmap[16][78],&bitmap[16][79],&bitmap[16][80],&bitmap[16][81],&bitmap[16][82],&bitmap[16][83],&bitmap[16][84],&bitmap[16][85],&bitmap[16][86],&bitmap[16][87],&bitmap[16][88],&bitmap[16][89],&bitmap[16][90],&bitmap[16][91],&bitmap[16][92],&bitmap[16][93],&bitmap[16][94],&bitmap[16][95],
					&bitmap[17][0],&bitmap[17][1],&bitmap[17][2],&bitmap[17][3],&bitmap[17][4],&bitmap[17][5],&bitmap[17][6],&bitmap[17][7],&bitmap[17][8],&bitmap[17][9],&bitmap[17][10],&bitmap[17][11],&bitmap[17][12],&bitmap[17][13],&bitmap[17][14],&bitmap[17][15],&bitmap[17][16],&bitmap[17][17],&bitmap[17][18],&bitmap[17][19],&bitmap[17][20],&bitmap[17][21],&bitmap[17][22],&bitmap[17][23],&bitmap[17][24],&bitmap[17][25],&bitmap[17][26],&bitmap[17][27],&bitmap[17][28],&bitmap[17][29],&bitmap[17][30],&bitmap[17][31],&bitmap[17][32],&bitmap[17][33],&bitmap[17][34],&bitmap[17][35],&bitmap[17][36],&bitmap[17][37],&bitmap[17][38],&bitmap[17][39],&bitmap[17][40],&bitmap[17][41],&bitmap[17][42],&bitmap[17][43],&bitmap[17][44],&bitmap[17][45],&bitmap[17][46],&bitmap[17][47],&bitmap[17][48],&bitmap[17][49],&bitmap[17][50],&bitmap[17][51],&bitmap[17][52],&bitmap[17][53],&bitmap[17][54],&bitmap[17][55],&bitmap[17][56],&bitmap[17][57],&bitmap[17][58],&bitmap[17][59],&bitmap[17][60],&bitmap[17][61],&bitmap[17][62],&bitmap[17][63],&bitmap[17][64],&bitmap[17][65],&bitmap[17][66],&bitmap[17][67],&bitmap[17][68],&bitmap[17][69],&bitmap[17][70],&bitmap[17][71],&bitmap[17][72],&bitmap[17][73],&bitmap[17][74],&bitmap[17][75],&bitmap[17][76],&bitmap[17][77],&bitmap[17][78],&bitmap[17][79],&bitmap[17][80],&bitmap[17][81],&bitmap[17][82],&bitmap[17][83],&bitmap[17][84],&bitmap[17][85],&bitmap[17][86],&bitmap[17][87],&bitmap[17][88],&bitmap[17][89],&bitmap[17][90],&bitmap[17][91],&bitmap[17][92],&bitmap[17][93],&bitmap[17][94],&bitmap[17][95],
					&bitmap[18][0],&bitmap[18][1],&bitmap[18][2],&bitmap[18][3],&bitmap[18][4],&bitmap[18][5],&bitmap[18][6],&bitmap[18][7],&bitmap[18][8],&bitmap[18][9],&bitmap[18][10],&bitmap[18][11],&bitmap[18][12],&bitmap[18][13],&bitmap[18][14],&bitmap[18][15],&bitmap[18][16],&bitmap[18][17],&bitmap[18][18],&bitmap[18][19],&bitmap[18][20],&bitmap[18][21],&bitmap[18][22],&bitmap[18][23],&bitmap[18][24],&bitmap[18][25],&bitmap[18][26],&bitmap[18][27],&bitmap[18][28],&bitmap[18][29],&bitmap[18][30],&bitmap[18][31],&bitmap[18][32],&bitmap[18][33],&bitmap[18][34],&bitmap[18][35],&bitmap[18][36],&bitmap[18][37],&bitmap[18][38],&bitmap[18][39],&bitmap[18][40],&bitmap[18][41],&bitmap[18][42],&bitmap[18][43],&bitmap[18][44],&bitmap[18][45],&bitmap[18][46],&bitmap[18][47],&bitmap[18][48],&bitmap[18][49],&bitmap[18][50],&bitmap[18][51],&bitmap[18][52],&bitmap[18][53],&bitmap[18][54],&bitmap[18][55],&bitmap[18][56],&bitmap[18][57],&bitmap[18][58],&bitmap[18][59],&bitmap[18][60],&bitmap[18][61],&bitmap[18][62],&bitmap[18][63],&bitmap[18][64],&bitmap[18][65],&bitmap[18][66],&bitmap[18][67],&bitmap[18][68],&bitmap[18][69],&bitmap[18][70],&bitmap[18][71],&bitmap[18][72],&bitmap[18][73],&bitmap[18][74],&bitmap[18][75],&bitmap[18][76],&bitmap[18][77],&bitmap[18][78],&bitmap[18][79],&bitmap[18][80],&bitmap[18][81],&bitmap[18][82],&bitmap[18][83],&bitmap[18][84],&bitmap[18][85],&bitmap[18][86],&bitmap[18][87],&bitmap[18][88],&bitmap[18][89],&bitmap[18][90],&bitmap[18][91],&bitmap[18][92],&bitmap[18][93],&bitmap[18][94],&bitmap[18][95],
					&bitmap[19][0],&bitmap[19][1],&bitmap[19][2],&bitmap[19][3],&bitmap[19][4],&bitmap[19][5],&bitmap[19][6],&bitmap[19][7],&bitmap[19][8],&bitmap[19][9],&bitmap[19][10],&bitmap[19][11],&bitmap[19][12],&bitmap[19][13],&bitmap[19][14],&bitmap[19][15],&bitmap[19][16],&bitmap[19][17],&bitmap[19][18],&bitmap[19][19],&bitmap[19][20],&bitmap[19][21],&bitmap[19][22],&bitmap[19][23],&bitmap[19][24],&bitmap[19][25],&bitmap[19][26],&bitmap[19][27],&bitmap[19][28],&bitmap[19][29],&bitmap[19][30],&bitmap[19][31],&bitmap[19][32],&bitmap[19][33],&bitmap[19][34],&bitmap[19][35],&bitmap[19][36],&bitmap[19][37],&bitmap[19][38],&bitmap[19][39],&bitmap[19][40],&bitmap[19][41],&bitmap[19][42],&bitmap[19][43],&bitmap[19][44],&bitmap[19][45],&bitmap[19][46],&bitmap[19][47],&bitmap[19][48],&bitmap[19][49],&bitmap[19][50],&bitmap[19][51],&bitmap[19][52],&bitmap[19][53],&bitmap[19][54],&bitmap[19][55],&bitmap[19][56],&bitmap[19][57],&bitmap[19][58],&bitmap[19][59],&bitmap[19][60],&bitmap[19][61],&bitmap[19][62],&bitmap[19][63],&bitmap[19][64],&bitmap[19][65],&bitmap[19][66],&bitmap[19][67],&bitmap[19][68],&bitmap[19][69],&bitmap[19][70],&bitmap[19][71],&bitmap[19][72],&bitmap[19][73],&bitmap[19][74],&bitmap[19][75],&bitmap[19][76],&bitmap[19][77],&bitmap[19][78],&bitmap[19][79],&bitmap[19][80],&bitmap[19][81],&bitmap[19][82],&bitmap[19][83],&bitmap[19][84],&bitmap[19][85],&bitmap[19][86],&bitmap[19][87],&bitmap[19][88],&bitmap[19][89],&bitmap[19][90],&bitmap[19][91],&bitmap[19][92],&bitmap[19][93],&bitmap[19][94],&bitmap[19][95],
					&bitmap[20][0],&bitmap[20][1],&bitmap[20][2],&bitmap[20][3],&bitmap[20][4],&bitmap[20][5],&bitmap[20][6],&bitmap[20][7],&bitmap[20][8],&bitmap[20][9],&bitmap[20][10],&bitmap[20][11],&bitmap[20][12],&bitmap[20][13],&bitmap[20][14],&bitmap[20][15],&bitmap[20][16],&bitmap[20][17],&bitmap[20][18],&bitmap[20][19],&bitmap[20][20],&bitmap[20][21],&bitmap[20][22],&bitmap[20][23],&bitmap[20][24],&bitmap[20][25],&bitmap[20][26],&bitmap[20][27],&bitmap[20][28],&bitmap[20][29],&bitmap[20][30],&bitmap[20][31],&bitmap[20][32],&bitmap[20][33],&bitmap[20][34],&bitmap[20][35],&bitmap[20][36],&bitmap[20][37],&bitmap[20][38],&bitmap[20][39],&bitmap[20][40],&bitmap[20][41],&bitmap[20][42],&bitmap[20][43],&bitmap[20][44],&bitmap[20][45],&bitmap[20][46],&bitmap[20][47],&bitmap[20][48],&bitmap[20][49],&bitmap[20][50],&bitmap[20][51],&bitmap[20][52],&bitmap[20][53],&bitmap[20][54],&bitmap[20][55],&bitmap[20][56],&bitmap[20][57],&bitmap[20][58],&bitmap[20][59],&bitmap[20][60],&bitmap[20][61],&bitmap[20][62],&bitmap[20][63],&bitmap[20][64],&bitmap[20][65],&bitmap[20][66],&bitmap[20][67],&bitmap[20][68],&bitmap[20][69],&bitmap[20][70],&bitmap[20][71],&bitmap[20][72],&bitmap[20][73],&bitmap[20][74],&bitmap[20][75],&bitmap[20][76],&bitmap[20][77],&bitmap[20][78],&bitmap[20][79],&bitmap[20][80],&bitmap[20][81],&bitmap[20][82],&bitmap[20][83],&bitmap[20][84],&bitmap[20][85],&bitmap[20][86],&bitmap[20][87],&bitmap[20][88],&bitmap[20][89],&bitmap[20][90],&bitmap[20][91],&bitmap[20][92],&bitmap[20][93],&bitmap[20][94],&bitmap[20][95],
					&bitmap[21][0],&bitmap[21][1],&bitmap[21][2],&bitmap[21][3],&bitmap[21][4],&bitmap[21][5],&bitmap[21][6],&bitmap[21][7],&bitmap[21][8],&bitmap[21][9],&bitmap[21][10],&bitmap[21][11],&bitmap[21][12],&bitmap[21][13],&bitmap[21][14],&bitmap[21][15],&bitmap[21][16],&bitmap[21][17],&bitmap[21][18],&bitmap[21][19],&bitmap[21][20],&bitmap[21][21],&bitmap[21][22],&bitmap[21][23],&bitmap[21][24],&bitmap[21][25],&bitmap[21][26],&bitmap[21][27],&bitmap[21][28],&bitmap[21][29],&bitmap[21][30],&bitmap[21][31],&bitmap[21][32],&bitmap[21][33],&bitmap[21][34],&bitmap[21][35],&bitmap[21][36],&bitmap[21][37],&bitmap[21][38],&bitmap[21][39],&bitmap[21][40],&bitmap[21][41],&bitmap[21][42],&bitmap[21][43],&bitmap[21][44],&bitmap[21][45],&bitmap[21][46],&bitmap[21][47],&bitmap[21][48],&bitmap[21][49],&bitmap[21][50],&bitmap[21][51],&bitmap[21][52],&bitmap[21][53],&bitmap[21][54],&bitmap[21][55],&bitmap[21][56],&bitmap[21][57],&bitmap[21][58],&bitmap[21][59],&bitmap[21][60],&bitmap[21][61],&bitmap[21][62],&bitmap[21][63],&bitmap[21][64],&bitmap[21][65],&bitmap[21][66],&bitmap[21][67],&bitmap[21][68],&bitmap[21][69],&bitmap[21][70],&bitmap[21][71],&bitmap[21][72],&bitmap[21][73],&bitmap[21][74],&bitmap[21][75],&bitmap[21][76],&bitmap[21][77],&bitmap[21][78],&bitmap[21][79],&bitmap[21][80],&bitmap[21][81],&bitmap[21][82],&bitmap[21][83],&bitmap[21][84],&bitmap[21][85],&bitmap[21][86],&bitmap[21][87],&bitmap[21][88],&bitmap[21][89],&bitmap[21][90],&bitmap[21][91],&bitmap[21][92],&bitmap[21][93],&bitmap[21][94],&bitmap[21][95],
					&bitmap[22][0],&bitmap[22][1],&bitmap[22][2],&bitmap[22][3],&bitmap[22][4],&bitmap[22][5],&bitmap[22][6],&bitmap[22][7],&bitmap[22][8],&bitmap[22][9],&bitmap[22][10],&bitmap[22][11],&bitmap[22][12],&bitmap[22][13],&bitmap[22][14],&bitmap[22][15],&bitmap[22][16],&bitmap[22][17],&bitmap[22][18],&bitmap[22][19],&bitmap[22][20],&bitmap[22][21],&bitmap[22][22],&bitmap[22][23],&bitmap[22][24],&bitmap[22][25],&bitmap[22][26],&bitmap[22][27],&bitmap[22][28],&bitmap[22][29],&bitmap[22][30],&bitmap[22][31],&bitmap[22][32],&bitmap[22][33],&bitmap[22][34],&bitmap[22][35],&bitmap[22][36],&bitmap[22][37],&bitmap[22][38],&bitmap[22][39],&bitmap[22][40],&bitmap[22][41],&bitmap[22][42],&bitmap[22][43],&bitmap[22][44],&bitmap[22][45],&bitmap[22][46],&bitmap[22][47],&bitmap[22][48],&bitmap[22][49],&bitmap[22][50],&bitmap[22][51],&bitmap[22][52],&bitmap[22][53],&bitmap[22][54],&bitmap[22][55],&bitmap[22][56],&bitmap[22][57],&bitmap[22][58],&bitmap[22][59],&bitmap[22][60],&bitmap[22][61],&bitmap[22][62],&bitmap[22][63],&bitmap[22][64],&bitmap[22][65],&bitmap[22][66],&bitmap[22][67],&bitmap[22][68],&bitmap[22][69],&bitmap[22][70],&bitmap[22][71],&bitmap[22][72],&bitmap[22][73],&bitmap[22][74],&bitmap[22][75],&bitmap[22][76],&bitmap[22][77],&bitmap[22][78],&bitmap[22][79],&bitmap[22][80],&bitmap[22][81],&bitmap[22][82],&bitmap[22][83],&bitmap[22][84],&bitmap[22][85],&bitmap[22][86],&bitmap[22][87],&bitmap[22][88],&bitmap[22][89],&bitmap[22][90],&bitmap[22][91],&bitmap[22][92],&bitmap[22][93],&bitmap[22][94],&bitmap[22][95],
					&bitmap[23][0],&bitmap[23][1],&bitmap[23][2],&bitmap[23][3],&bitmap[23][4],&bitmap[23][5],&bitmap[23][6],&bitmap[23][7],&bitmap[23][8],&bitmap[23][9],&bitmap[23][10],&bitmap[23][11],&bitmap[23][12],&bitmap[23][13],&bitmap[23][14],&bitmap[23][15],&bitmap[23][16],&bitmap[23][17],&bitmap[23][18],&bitmap[23][19],&bitmap[23][20],&bitmap[23][21],&bitmap[23][22],&bitmap[23][23],&bitmap[23][24],&bitmap[23][25],&bitmap[23][26],&bitmap[23][27],&bitmap[23][28],&bitmap[23][29],&bitmap[23][30],&bitmap[23][31],&bitmap[23][32],&bitmap[23][33],&bitmap[23][34],&bitmap[23][35],&bitmap[23][36],&bitmap[23][37],&bitmap[23][38],&bitmap[23][39],&bitmap[23][40],&bitmap[23][41],&bitmap[23][42],&bitmap[23][43],&bitmap[23][44],&bitmap[23][45],&bitmap[23][46],&bitmap[23][47],&bitmap[23][48],&bitmap[23][49],&bitmap[23][50],&bitmap[23][51],&bitmap[23][52],&bitmap[23][53],&bitmap[23][54],&bitmap[23][55],&bitmap[23][56],&bitmap[23][57],&bitmap[23][58],&bitmap[23][59],&bitmap[23][60],&bitmap[23][61],&bitmap[23][62],&bitmap[23][63],&bitmap[23][64],&bitmap[23][65],&bitmap[23][66],&bitmap[23][67],&bitmap[23][68],&bitmap[23][69],&bitmap[23][70],&bitmap[23][71],&bitmap[23][72],&bitmap[23][73],&bitmap[23][74],&bitmap[23][75],&bitmap[23][76],&bitmap[23][77],&bitmap[23][78],&bitmap[23][79],&bitmap[23][80],&bitmap[23][81],&bitmap[23][82],&bitmap[23][83],&bitmap[23][84],&bitmap[23][85],&bitmap[23][86],&bitmap[23][87],&bitmap[23][88],&bitmap[23][89],&bitmap[23][90],&bitmap[23][91],&bitmap[23][92],&bitmap[23][93],&bitmap[23][94],&bitmap[23][95],
					&bitmap[24][0],&bitmap[24][1],&bitmap[24][2],&bitmap[24][3],&bitmap[24][4],&bitmap[24][5],&bitmap[24][6],&bitmap[24][7],&bitmap[24][8],&bitmap[24][9],&bitmap[24][10],&bitmap[24][11],&bitmap[24][12],&bitmap[24][13],&bitmap[24][14],&bitmap[24][15],&bitmap[24][16],&bitmap[24][17],&bitmap[24][18],&bitmap[24][19],&bitmap[24][20],&bitmap[24][21],&bitmap[24][22],&bitmap[24][23],&bitmap[24][24],&bitmap[24][25],&bitmap[24][26],&bitmap[24][27],&bitmap[24][28],&bitmap[24][29],&bitmap[24][30],&bitmap[24][31],&bitmap[24][32],&bitmap[24][33],&bitmap[24][34],&bitmap[24][35],&bitmap[24][36],&bitmap[24][37],&bitmap[24][38],&bitmap[24][39],&bitmap[24][40],&bitmap[24][41],&bitmap[24][42],&bitmap[24][43],&bitmap[24][44],&bitmap[24][45],&bitmap[24][46],&bitmap[24][47],&bitmap[24][48],&bitmap[24][49],&bitmap[24][50],&bitmap[24][51],&bitmap[24][52],&bitmap[24][53],&bitmap[24][54],&bitmap[24][55],&bitmap[24][56],&bitmap[24][57],&bitmap[24][58],&bitmap[24][59],&bitmap[24][60],&bitmap[24][61],&bitmap[24][62],&bitmap[24][63],&bitmap[24][64],&bitmap[24][65],&bitmap[24][66],&bitmap[24][67],&bitmap[24][68],&bitmap[24][69],&bitmap[24][70],&bitmap[24][71],&bitmap[24][72],&bitmap[24][73],&bitmap[24][74],&bitmap[24][75],&bitmap[24][76],&bitmap[24][77],&bitmap[24][78],&bitmap[24][79],&bitmap[24][80],&bitmap[24][81],&bitmap[24][82],&bitmap[24][83],&bitmap[24][84],&bitmap[24][85],&bitmap[24][86],&bitmap[24][87],&bitmap[24][88],&bitmap[24][89],&bitmap[24][90],&bitmap[24][91],&bitmap[24][92],&bitmap[24][93],&bitmap[24][94],&bitmap[24][95],
					&bitmap[25][0],&bitmap[25][1],&bitmap[25][2],&bitmap[25][3],&bitmap[25][4],&bitmap[25][5],&bitmap[25][6],&bitmap[25][7],&bitmap[25][8],&bitmap[25][9],&bitmap[25][10],&bitmap[25][11],&bitmap[25][12],&bitmap[25][13],&bitmap[25][14],&bitmap[25][15],&bitmap[25][16],&bitmap[25][17],&bitmap[25][18],&bitmap[25][19],&bitmap[25][20],&bitmap[25][21],&bitmap[25][22],&bitmap[25][23],&bitmap[25][24],&bitmap[25][25],&bitmap[25][26],&bitmap[25][27],&bitmap[25][28],&bitmap[25][29],&bitmap[25][30],&bitmap[25][31],&bitmap[25][32],&bitmap[25][33],&bitmap[25][34],&bitmap[25][35],&bitmap[25][36],&bitmap[25][37],&bitmap[25][38],&bitmap[25][39],&bitmap[25][40],&bitmap[25][41],&bitmap[25][42],&bitmap[25][43],&bitmap[25][44],&bitmap[25][45],&bitmap[25][46],&bitmap[25][47],&bitmap[25][48],&bitmap[25][49],&bitmap[25][50],&bitmap[25][51],&bitmap[25][52],&bitmap[25][53],&bitmap[25][54],&bitmap[25][55],&bitmap[25][56],&bitmap[25][57],&bitmap[25][58],&bitmap[25][59],&bitmap[25][60],&bitmap[25][61],&bitmap[25][62],&bitmap[25][63],&bitmap[25][64],&bitmap[25][65],&bitmap[25][66],&bitmap[25][67],&bitmap[25][68],&bitmap[25][69],&bitmap[25][70],&bitmap[25][71],&bitmap[25][72],&bitmap[25][73],&bitmap[25][74],&bitmap[25][75],&bitmap[25][76],&bitmap[25][77],&bitmap[25][78],&bitmap[25][79],&bitmap[25][80],&bitmap[25][81],&bitmap[25][82],&bitmap[25][83],&bitmap[25][84],&bitmap[25][85],&bitmap[25][86],&bitmap[25][87],&bitmap[25][88],&bitmap[25][89],&bitmap[25][90],&bitmap[25][91],&bitmap[25][92],&bitmap[25][93],&bitmap[25][94],&bitmap[25][95],
					&bitmap[26][0],&bitmap[26][1],&bitmap[26][2],&bitmap[26][3],&bitmap[26][4],&bitmap[26][5],&bitmap[26][6],&bitmap[26][7],&bitmap[26][8],&bitmap[26][9],&bitmap[26][10],&bitmap[26][11],&bitmap[26][12],&bitmap[26][13],&bitmap[26][14],&bitmap[26][15],&bitmap[26][16],&bitmap[26][17],&bitmap[26][18],&bitmap[26][19],&bitmap[26][20],&bitmap[26][21],&bitmap[26][22],&bitmap[26][23],&bitmap[26][24],&bitmap[26][25],&bitmap[26][26],&bitmap[26][27],&bitmap[26][28],&bitmap[26][29],&bitmap[26][30],&bitmap[26][31],&bitmap[26][32],&bitmap[26][33],&bitmap[26][34],&bitmap[26][35],&bitmap[26][36],&bitmap[26][37],&bitmap[26][38],&bitmap[26][39],&bitmap[26][40],&bitmap[26][41],&bitmap[26][42],&bitmap[26][43],&bitmap[26][44],&bitmap[26][45],&bitmap[26][46],&bitmap[26][47],&bitmap[26][48],&bitmap[26][49],&bitmap[26][50],&bitmap[26][51],&bitmap[26][52],&bitmap[26][53],&bitmap[26][54],&bitmap[26][55],&bitmap[26][56],&bitmap[26][57],&bitmap[26][58],&bitmap[26][59],&bitmap[26][60],&bitmap[26][61],&bitmap[26][62],&bitmap[26][63],&bitmap[26][64],&bitmap[26][65],&bitmap[26][66],&bitmap[26][67],&bitmap[26][68],&bitmap[26][69],&bitmap[26][70],&bitmap[26][71],&bitmap[26][72],&bitmap[26][73],&bitmap[26][74],&bitmap[26][75],&bitmap[26][76],&bitmap[26][77],&bitmap[26][78],&bitmap[26][79],&bitmap[26][80],&bitmap[26][81],&bitmap[26][82],&bitmap[26][83],&bitmap[26][84],&bitmap[26][85],&bitmap[26][86],&bitmap[26][87],&bitmap[26][88],&bitmap[26][89],&bitmap[26][90],&bitmap[26][91],&bitmap[26][92],&bitmap[26][93],&bitmap[26][94],&bitmap[26][95],
					&bitmap[27][0],&bitmap[27][1],&bitmap[27][2],&bitmap[27][3],&bitmap[27][4],&bitmap[27][5],&bitmap[27][6],&bitmap[27][7],&bitmap[27][8],&bitmap[27][9],&bitmap[27][10],&bitmap[27][11],&bitmap[27][12],&bitmap[27][13],&bitmap[27][14],&bitmap[27][15],&bitmap[27][16],&bitmap[27][17],&bitmap[27][18],&bitmap[27][19],&bitmap[27][20],&bitmap[27][21],&bitmap[27][22],&bitmap[27][23],&bitmap[27][24],&bitmap[27][25],&bitmap[27][26],&bitmap[27][27],&bitmap[27][28],&bitmap[27][29],&bitmap[27][30],&bitmap[27][31],&bitmap[27][32],&bitmap[27][33],&bitmap[27][34],&bitmap[27][35],&bitmap[27][36],&bitmap[27][37],&bitmap[27][38],&bitmap[27][39],&bitmap[27][40],&bitmap[27][41],&bitmap[27][42],&bitmap[27][43],&bitmap[27][44],&bitmap[27][45],&bitmap[27][46],&bitmap[27][47],&bitmap[27][48],&bitmap[27][49],&bitmap[27][50],&bitmap[27][51],&bitmap[27][52],&bitmap[27][53],&bitmap[27][54],&bitmap[27][55],&bitmap[27][56],&bitmap[27][57],&bitmap[27][58],&bitmap[27][59],&bitmap[27][60],&bitmap[27][61],&bitmap[27][62],&bitmap[27][63],&bitmap[27][64],&bitmap[27][65],&bitmap[27][66],&bitmap[27][67],&bitmap[27][68],&bitmap[27][69],&bitmap[27][70],&bitmap[27][71],&bitmap[27][72],&bitmap[27][73],&bitmap[27][74],&bitmap[27][75],&bitmap[27][76],&bitmap[27][77],&bitmap[27][78],&bitmap[27][79],&bitmap[27][80],&bitmap[27][81],&bitmap[27][82],&bitmap[27][83],&bitmap[27][84],&bitmap[27][85],&bitmap[27][86],&bitmap[27][87],&bitmap[27][88],&bitmap[27][89],&bitmap[27][90],&bitmap[27][91],&bitmap[27][92],&bitmap[27][93],&bitmap[27][94],&bitmap[27][95],
					&bitmap[28][0],&bitmap[28][1],&bitmap[28][2],&bitmap[28][3],&bitmap[28][4],&bitmap[28][5],&bitmap[28][6],&bitmap[28][7],&bitmap[28][8],&bitmap[28][9],&bitmap[28][10],&bitmap[28][11],&bitmap[28][12],&bitmap[28][13],&bitmap[28][14],&bitmap[28][15],&bitmap[28][16],&bitmap[28][17],&bitmap[28][18],&bitmap[28][19],&bitmap[28][20],&bitmap[28][21],&bitmap[28][22],&bitmap[28][23],&bitmap[28][24],&bitmap[28][25],&bitmap[28][26],&bitmap[28][27],&bitmap[28][28],&bitmap[28][29],&bitmap[28][30],&bitmap[28][31],&bitmap[28][32],&bitmap[28][33],&bitmap[28][34],&bitmap[28][35],&bitmap[28][36],&bitmap[28][37],&bitmap[28][38],&bitmap[28][39],&bitmap[28][40],&bitmap[28][41],&bitmap[28][42],&bitmap[28][43],&bitmap[28][44],&bitmap[28][45],&bitmap[28][46],&bitmap[28][47],&bitmap[28][48],&bitmap[28][49],&bitmap[28][50],&bitmap[28][51],&bitmap[28][52],&bitmap[28][53],&bitmap[28][54],&bitmap[28][55],&bitmap[28][56],&bitmap[28][57],&bitmap[28][58],&bitmap[28][59],&bitmap[28][60],&bitmap[28][61],&bitmap[28][62],&bitmap[28][63],&bitmap[28][64],&bitmap[28][65],&bitmap[28][66],&bitmap[28][67],&bitmap[28][68],&bitmap[28][69],&bitmap[28][70],&bitmap[28][71],&bitmap[28][72],&bitmap[28][73],&bitmap[28][74],&bitmap[28][75],&bitmap[28][76],&bitmap[28][77],&bitmap[28][78],&bitmap[28][79],&bitmap[28][80],&bitmap[28][81],&bitmap[28][82],&bitmap[28][83],&bitmap[28][84],&bitmap[28][85],&bitmap[28][86],&bitmap[28][87],&bitmap[28][88],&bitmap[28][89],&bitmap[28][90],&bitmap[28][91],&bitmap[28][92],&bitmap[28][93],&bitmap[28][94],&bitmap[28][95],
					&bitmap[29][0],&bitmap[29][1],&bitmap[29][2],&bitmap[29][3],&bitmap[29][4],&bitmap[29][5],&bitmap[29][6],&bitmap[29][7],&bitmap[29][8],&bitmap[29][9],&bitmap[29][10],&bitmap[29][11],&bitmap[29][12],&bitmap[29][13],&bitmap[29][14],&bitmap[29][15],&bitmap[29][16],&bitmap[29][17],&bitmap[29][18],&bitmap[29][19],&bitmap[29][20],&bitmap[29][21],&bitmap[29][22],&bitmap[29][23],&bitmap[29][24],&bitmap[29][25],&bitmap[29][26],&bitmap[29][27],&bitmap[29][28],&bitmap[29][29],&bitmap[29][30],&bitmap[29][31],&bitmap[29][32],&bitmap[29][33],&bitmap[29][34],&bitmap[29][35],&bitmap[29][36],&bitmap[29][37],&bitmap[29][38],&bitmap[29][39],&bitmap[29][40],&bitmap[29][41],&bitmap[29][42],&bitmap[29][43],&bitmap[29][44],&bitmap[29][45],&bitmap[29][46],&bitmap[29][47],&bitmap[29][48],&bitmap[29][49],&bitmap[29][50],&bitmap[29][51],&bitmap[29][52],&bitmap[29][53],&bitmap[29][54],&bitmap[29][55],&bitmap[29][56],&bitmap[29][57],&bitmap[29][58],&bitmap[29][59],&bitmap[29][60],&bitmap[29][61],&bitmap[29][62],&bitmap[29][63],&bitmap[29][64],&bitmap[29][65],&bitmap[29][66],&bitmap[29][67],&bitmap[29][68],&bitmap[29][69],&bitmap[29][70],&bitmap[29][71],&bitmap[29][72],&bitmap[29][73],&bitmap[29][74],&bitmap[29][75],&bitmap[29][76],&bitmap[29][77],&bitmap[29][78],&bitmap[29][79],&bitmap[29][80],&bitmap[29][81],&bitmap[29][82],&bitmap[29][83],&bitmap[29][84],&bitmap[29][85],&bitmap[29][86],&bitmap[29][87],&bitmap[29][88],&bitmap[29][89],&bitmap[29][90],&bitmap[29][91],&bitmap[29][92],&bitmap[29][93],&bitmap[29][94],&bitmap[29][95],
					&bitmap[30][0],&bitmap[30][1],&bitmap[30][2],&bitmap[30][3],&bitmap[30][4],&bitmap[30][5],&bitmap[30][6],&bitmap[30][7],&bitmap[30][8],&bitmap[30][9],&bitmap[30][10],&bitmap[30][11],&bitmap[30][12],&bitmap[30][13],&bitmap[30][14],&bitmap[30][15],&bitmap[30][16],&bitmap[30][17],&bitmap[30][18],&bitmap[30][19],&bitmap[30][20],&bitmap[30][21],&bitmap[30][22],&bitmap[30][23],&bitmap[30][24],&bitmap[30][25],&bitmap[30][26],&bitmap[30][27],&bitmap[30][28],&bitmap[30][29],&bitmap[30][30],&bitmap[30][31],&bitmap[30][32],&bitmap[30][33],&bitmap[30][34],&bitmap[30][35],&bitmap[30][36],&bitmap[30][37],&bitmap[30][38],&bitmap[30][39],&bitmap[30][40],&bitmap[30][41],&bitmap[30][42],&bitmap[30][43],&bitmap[30][44],&bitmap[30][45],&bitmap[30][46],&bitmap[30][47],&bitmap[30][48],&bitmap[30][49],&bitmap[30][50],&bitmap[30][51],&bitmap[30][52],&bitmap[30][53],&bitmap[30][54],&bitmap[30][55],&bitmap[30][56],&bitmap[30][57],&bitmap[30][58],&bitmap[30][59],&bitmap[30][60],&bitmap[30][61],&bitmap[30][62],&bitmap[30][63],&bitmap[30][64],&bitmap[30][65],&bitmap[30][66],&bitmap[30][67],&bitmap[30][68],&bitmap[30][69],&bitmap[30][70],&bitmap[30][71],&bitmap[30][72],&bitmap[30][73],&bitmap[30][74],&bitmap[30][75],&bitmap[30][76],&bitmap[30][77],&bitmap[30][78],&bitmap[30][79],&bitmap[30][80],&bitmap[30][81],&bitmap[30][82],&bitmap[30][83],&bitmap[30][84],&bitmap[30][85],&bitmap[30][86],&bitmap[30][87],&bitmap[30][88],&bitmap[30][89],&bitmap[30][90],&bitmap[30][91],&bitmap[30][92],&bitmap[30][93],&bitmap[30][94],&bitmap[30][95],
					&bitmap[31][0],&bitmap[31][1],&bitmap[31][2],&bitmap[31][3],&bitmap[31][4],&bitmap[31][5],&bitmap[31][6],&bitmap[31][7],&bitmap[31][8],&bitmap[31][9],&bitmap[31][10],&bitmap[31][11],&bitmap[31][12],&bitmap[31][13],&bitmap[31][14],&bitmap[31][15],&bitmap[31][16],&bitmap[31][17],&bitmap[31][18],&bitmap[31][19],&bitmap[31][20],&bitmap[31][21],&bitmap[31][22],&bitmap[31][23],&bitmap[31][24],&bitmap[31][25],&bitmap[31][26],&bitmap[31][27],&bitmap[31][28],&bitmap[31][29],&bitmap[31][30],&bitmap[31][31],&bitmap[31][32],&bitmap[31][33],&bitmap[31][34],&bitmap[31][35],&bitmap[31][36],&bitmap[31][37],&bitmap[31][38],&bitmap[31][39],&bitmap[31][40],&bitmap[31][41],&bitmap[31][42],&bitmap[31][43],&bitmap[31][44],&bitmap[31][45],&bitmap[31][46],&bitmap[31][47],&bitmap[31][48],&bitmap[31][49],&bitmap[31][50],&bitmap[31][51],&bitmap[31][52],&bitmap[31][53],&bitmap[31][54],&bitmap[31][55],&bitmap[31][56],&bitmap[31][57],&bitmap[31][58],&bitmap[31][59],&bitmap[31][60],&bitmap[31][61],&bitmap[31][62],&bitmap[31][63],&bitmap[31][64],&bitmap[31][65],&bitmap[31][66],&bitmap[31][67],&bitmap[31][68],&bitmap[31][69],&bitmap[31][70],&bitmap[31][71],&bitmap[31][72],&bitmap[31][73],&bitmap[31][74],&bitmap[31][75],&bitmap[31][76],&bitmap[31][77],&bitmap[31][78],&bitmap[31][79],&bitmap[31][80],&bitmap[31][81],&bitmap[31][82],&bitmap[31][83],&bitmap[31][84],&bitmap[31][85],&bitmap[31][86],&bitmap[31][87],&bitmap[31][88],&bitmap[31][89],&bitmap[31][90],&bitmap[31][91],&bitmap[31][92],&bitmap[31][93],&bitmap[31][94],&bitmap[31][95],
					&bitmap[32][0],&bitmap[32][1],&bitmap[32][2],&bitmap[32][3],&bitmap[32][4],&bitmap[32][5],&bitmap[32][6],&bitmap[32][7],&bitmap[32][8],&bitmap[32][9],&bitmap[32][10],&bitmap[32][11],&bitmap[32][12],&bitmap[32][13],&bitmap[32][14],&bitmap[32][15],&bitmap[32][16],&bitmap[32][17],&bitmap[32][18],&bitmap[32][19],&bitmap[32][20],&bitmap[32][21],&bitmap[32][22],&bitmap[32][23],&bitmap[32][24],&bitmap[32][25],&bitmap[32][26],&bitmap[32][27],&bitmap[32][28],&bitmap[32][29],&bitmap[32][30],&bitmap[32][31],&bitmap[32][32],&bitmap[32][33],&bitmap[32][34],&bitmap[32][35],&bitmap[32][36],&bitmap[32][37],&bitmap[32][38],&bitmap[32][39],&bitmap[32][40],&bitmap[32][41],&bitmap[32][42],&bitmap[32][43],&bitmap[32][44],&bitmap[32][45],&bitmap[32][46],&bitmap[32][47],&bitmap[32][48],&bitmap[32][49],&bitmap[32][50],&bitmap[32][51],&bitmap[32][52],&bitmap[32][53],&bitmap[32][54],&bitmap[32][55],&bitmap[32][56],&bitmap[32][57],&bitmap[32][58],&bitmap[32][59],&bitmap[32][60],&bitmap[32][61],&bitmap[32][62],&bitmap[32][63],&bitmap[32][64],&bitmap[32][65],&bitmap[32][66],&bitmap[32][67],&bitmap[32][68],&bitmap[32][69],&bitmap[32][70],&bitmap[32][71],&bitmap[32][72],&bitmap[32][73],&bitmap[32][74],&bitmap[32][75],&bitmap[32][76],&bitmap[32][77],&bitmap[32][78],&bitmap[32][79],&bitmap[32][80],&bitmap[32][81],&bitmap[32][82],&bitmap[32][83],&bitmap[32][84],&bitmap[32][85],&bitmap[32][86],&bitmap[32][87],&bitmap[32][88],&bitmap[32][89],&bitmap[32][90],&bitmap[32][91],&bitmap[32][92],&bitmap[32][93],&bitmap[32][94],&bitmap[32][95],
					&bitmap[33][0],&bitmap[33][1],&bitmap[33][2],&bitmap[33][3],&bitmap[33][4],&bitmap[33][5],&bitmap[33][6],&bitmap[33][7],&bitmap[33][8],&bitmap[33][9],&bitmap[33][10],&bitmap[33][11],&bitmap[33][12],&bitmap[33][13],&bitmap[33][14],&bitmap[33][15],&bitmap[33][16],&bitmap[33][17],&bitmap[33][18],&bitmap[33][19],&bitmap[33][20],&bitmap[33][21],&bitmap[33][22],&bitmap[33][23],&bitmap[33][24],&bitmap[33][25],&bitmap[33][26],&bitmap[33][27],&bitmap[33][28],&bitmap[33][29],&bitmap[33][30],&bitmap[33][31],&bitmap[33][32],&bitmap[33][33],&bitmap[33][34],&bitmap[33][35],&bitmap[33][36],&bitmap[33][37],&bitmap[33][38],&bitmap[33][39],&bitmap[33][40],&bitmap[33][41],&bitmap[33][42],&bitmap[33][43],&bitmap[33][44],&bitmap[33][45],&bitmap[33][46],&bitmap[33][47],&bitmap[33][48],&bitmap[33][49],&bitmap[33][50],&bitmap[33][51],&bitmap[33][52],&bitmap[33][53],&bitmap[33][54],&bitmap[33][55],&bitmap[33][56],&bitmap[33][57],&bitmap[33][58],&bitmap[33][59],&bitmap[33][60],&bitmap[33][61],&bitmap[33][62],&bitmap[33][63],&bitmap[33][64],&bitmap[33][65],&bitmap[33][66],&bitmap[33][67],&bitmap[33][68],&bitmap[33][69],&bitmap[33][70],&bitmap[33][71],&bitmap[33][72],&bitmap[33][73],&bitmap[33][74],&bitmap[33][75],&bitmap[33][76],&bitmap[33][77],&bitmap[33][78],&bitmap[33][79],&bitmap[33][80],&bitmap[33][81],&bitmap[33][82],&bitmap[33][83],&bitmap[33][84],&bitmap[33][85],&bitmap[33][86],&bitmap[33][87],&bitmap[33][88],&bitmap[33][89],&bitmap[33][90],&bitmap[33][91],&bitmap[33][92],&bitmap[33][93],&bitmap[33][94],&bitmap[33][95],
					&bitmap[34][0],&bitmap[34][1],&bitmap[34][2],&bitmap[34][3],&bitmap[34][4],&bitmap[34][5],&bitmap[34][6],&bitmap[34][7],&bitmap[34][8],&bitmap[34][9],&bitmap[34][10],&bitmap[34][11],&bitmap[34][12],&bitmap[34][13],&bitmap[34][14],&bitmap[34][15],&bitmap[34][16],&bitmap[34][17],&bitmap[34][18],&bitmap[34][19],&bitmap[34][20],&bitmap[34][21],&bitmap[34][22],&bitmap[34][23],&bitmap[34][24],&bitmap[34][25],&bitmap[34][26],&bitmap[34][27],&bitmap[34][28],&bitmap[34][29],&bitmap[34][30],&bitmap[34][31],&bitmap[34][32],&bitmap[34][33],&bitmap[34][34],&bitmap[34][35],&bitmap[34][36],&bitmap[34][37],&bitmap[34][38],&bitmap[34][39],&bitmap[34][40],&bitmap[34][41],&bitmap[34][42],&bitmap[34][43],&bitmap[34][44],&bitmap[34][45],&bitmap[34][46],&bitmap[34][47],&bitmap[34][48],&bitmap[34][49],&bitmap[34][50],&bitmap[34][51],&bitmap[34][52],&bitmap[34][53],&bitmap[34][54],&bitmap[34][55],&bitmap[34][56],&bitmap[34][57],&bitmap[34][58],&bitmap[34][59],&bitmap[34][60],&bitmap[34][61],&bitmap[34][62],&bitmap[34][63],&bitmap[34][64],&bitmap[34][65],&bitmap[34][66],&bitmap[34][67],&bitmap[34][68],&bitmap[34][69],&bitmap[34][70],&bitmap[34][71],&bitmap[34][72],&bitmap[34][73],&bitmap[34][74],&bitmap[34][75],&bitmap[34][76],&bitmap[34][77],&bitmap[34][78],&bitmap[34][79],&bitmap[34][80],&bitmap[34][81],&bitmap[34][82],&bitmap[34][83],&bitmap[34][84],&bitmap[34][85],&bitmap[34][86],&bitmap[34][87],&bitmap[34][88],&bitmap[34][89],&bitmap[34][90],&bitmap[34][91],&bitmap[34][92],&bitmap[34][93],&bitmap[34][94],&bitmap[34][95],
					&bitmap[35][0],&bitmap[35][1],&bitmap[35][2],&bitmap[35][3],&bitmap[35][4],&bitmap[35][5],&bitmap[35][6],&bitmap[35][7],&bitmap[35][8],&bitmap[35][9],&bitmap[35][10],&bitmap[35][11],&bitmap[35][12],&bitmap[35][13],&bitmap[35][14],&bitmap[35][15],&bitmap[35][16],&bitmap[35][17],&bitmap[35][18],&bitmap[35][19],&bitmap[35][20],&bitmap[35][21],&bitmap[35][22],&bitmap[35][23],&bitmap[35][24],&bitmap[35][25],&bitmap[35][26],&bitmap[35][27],&bitmap[35][28],&bitmap[35][29],&bitmap[35][30],&bitmap[35][31],&bitmap[35][32],&bitmap[35][33],&bitmap[35][34],&bitmap[35][35],&bitmap[35][36],&bitmap[35][37],&bitmap[35][38],&bitmap[35][39],&bitmap[35][40],&bitmap[35][41],&bitmap[35][42],&bitmap[35][43],&bitmap[35][44],&bitmap[35][45],&bitmap[35][46],&bitmap[35][47],&bitmap[35][48],&bitmap[35][49],&bitmap[35][50],&bitmap[35][51],&bitmap[35][52],&bitmap[35][53],&bitmap[35][54],&bitmap[35][55],&bitmap[35][56],&bitmap[35][57],&bitmap[35][58],&bitmap[35][59],&bitmap[35][60],&bitmap[35][61],&bitmap[35][62],&bitmap[35][63],&bitmap[35][64],&bitmap[35][65],&bitmap[35][66],&bitmap[35][67],&bitmap[35][68],&bitmap[35][69],&bitmap[35][70],&bitmap[35][71],&bitmap[35][72],&bitmap[35][73],&bitmap[35][74],&bitmap[35][75],&bitmap[35][76],&bitmap[35][77],&bitmap[35][78],&bitmap[35][79],&bitmap[35][80],&bitmap[35][81],&bitmap[35][82],&bitmap[35][83],&bitmap[35][84],&bitmap[35][85],&bitmap[35][86],&bitmap[35][87],&bitmap[35][88],&bitmap[35][89],&bitmap[35][90],&bitmap[35][91],&bitmap[35][92],&bitmap[35][93],&bitmap[35][94],&bitmap[35][95],
					&bitmap[36][0],&bitmap[36][1],&bitmap[36][2],&bitmap[36][3],&bitmap[36][4],&bitmap[36][5],&bitmap[36][6],&bitmap[36][7],&bitmap[36][8],&bitmap[36][9],&bitmap[36][10],&bitmap[36][11],&bitmap[36][12],&bitmap[36][13],&bitmap[36][14],&bitmap[36][15],&bitmap[36][16],&bitmap[36][17],&bitmap[36][18],&bitmap[36][19],&bitmap[36][20],&bitmap[36][21],&bitmap[36][22],&bitmap[36][23],&bitmap[36][24],&bitmap[36][25],&bitmap[36][26],&bitmap[36][27],&bitmap[36][28],&bitmap[36][29],&bitmap[36][30],&bitmap[36][31],&bitmap[36][32],&bitmap[36][33],&bitmap[36][34],&bitmap[36][35],&bitmap[36][36],&bitmap[36][37],&bitmap[36][38],&bitmap[36][39],&bitmap[36][40],&bitmap[36][41],&bitmap[36][42],&bitmap[36][43],&bitmap[36][44],&bitmap[36][45],&bitmap[36][46],&bitmap[36][47],&bitmap[36][48],&bitmap[36][49],&bitmap[36][50],&bitmap[36][51],&bitmap[36][52],&bitmap[36][53],&bitmap[36][54],&bitmap[36][55],&bitmap[36][56],&bitmap[36][57],&bitmap[36][58],&bitmap[36][59],&bitmap[36][60],&bitmap[36][61],&bitmap[36][62],&bitmap[36][63],&bitmap[36][64],&bitmap[36][65],&bitmap[36][66],&bitmap[36][67],&bitmap[36][68],&bitmap[36][69],&bitmap[36][70],&bitmap[36][71],&bitmap[36][72],&bitmap[36][73],&bitmap[36][74],&bitmap[36][75],&bitmap[36][76],&bitmap[36][77],&bitmap[36][78],&bitmap[36][79],&bitmap[36][80],&bitmap[36][81],&bitmap[36][82],&bitmap[36][83],&bitmap[36][84],&bitmap[36][85],&bitmap[36][86],&bitmap[36][87],&bitmap[36][88],&bitmap[36][89],&bitmap[36][90],&bitmap[36][91],&bitmap[36][92],&bitmap[36][93],&bitmap[36][94],&bitmap[36][95],
					&bitmap[37][0],&bitmap[37][1],&bitmap[37][2],&bitmap[37][3],&bitmap[37][4],&bitmap[37][5],&bitmap[37][6],&bitmap[37][7],&bitmap[37][8],&bitmap[37][9],&bitmap[37][10],&bitmap[37][11],&bitmap[37][12],&bitmap[37][13],&bitmap[37][14],&bitmap[37][15],&bitmap[37][16],&bitmap[37][17],&bitmap[37][18],&bitmap[37][19],&bitmap[37][20],&bitmap[37][21],&bitmap[37][22],&bitmap[37][23],&bitmap[37][24],&bitmap[37][25],&bitmap[37][26],&bitmap[37][27],&bitmap[37][28],&bitmap[37][29],&bitmap[37][30],&bitmap[37][31],&bitmap[37][32],&bitmap[37][33],&bitmap[37][34],&bitmap[37][35],&bitmap[37][36],&bitmap[37][37],&bitmap[37][38],&bitmap[37][39],&bitmap[37][40],&bitmap[37][41],&bitmap[37][42],&bitmap[37][43],&bitmap[37][44],&bitmap[37][45],&bitmap[37][46],&bitmap[37][47],&bitmap[37][48],&bitmap[37][49],&bitmap[37][50],&bitmap[37][51],&bitmap[37][52],&bitmap[37][53],&bitmap[37][54],&bitmap[37][55],&bitmap[37][56],&bitmap[37][57],&bitmap[37][58],&bitmap[37][59],&bitmap[37][60],&bitmap[37][61],&bitmap[37][62],&bitmap[37][63],&bitmap[37][64],&bitmap[37][65],&bitmap[37][66],&bitmap[37][67],&bitmap[37][68],&bitmap[37][69],&bitmap[37][70],&bitmap[37][71],&bitmap[37][72],&bitmap[37][73],&bitmap[37][74],&bitmap[37][75],&bitmap[37][76],&bitmap[37][77],&bitmap[37][78],&bitmap[37][79],&bitmap[37][80],&bitmap[37][81],&bitmap[37][82],&bitmap[37][83],&bitmap[37][84],&bitmap[37][85],&bitmap[37][86],&bitmap[37][87],&bitmap[37][88],&bitmap[37][89],&bitmap[37][90],&bitmap[37][91],&bitmap[37][92],&bitmap[37][93],&bitmap[37][94],&bitmap[37][95],
					&bitmap[38][0],&bitmap[38][1],&bitmap[38][2],&bitmap[38][3],&bitmap[38][4],&bitmap[38][5],&bitmap[38][6],&bitmap[38][7],&bitmap[38][8],&bitmap[38][9],&bitmap[38][10],&bitmap[38][11],&bitmap[38][12],&bitmap[38][13],&bitmap[38][14],&bitmap[38][15],&bitmap[38][16],&bitmap[38][17],&bitmap[38][18],&bitmap[38][19],&bitmap[38][20],&bitmap[38][21],&bitmap[38][22],&bitmap[38][23],&bitmap[38][24],&bitmap[38][25],&bitmap[38][26],&bitmap[38][27],&bitmap[38][28],&bitmap[38][29],&bitmap[38][30],&bitmap[38][31],&bitmap[38][32],&bitmap[38][33],&bitmap[38][34],&bitmap[38][35],&bitmap[38][36],&bitmap[38][37],&bitmap[38][38],&bitmap[38][39],&bitmap[38][40],&bitmap[38][41],&bitmap[38][42],&bitmap[38][43],&bitmap[38][44],&bitmap[38][45],&bitmap[38][46],&bitmap[38][47],&bitmap[38][48],&bitmap[38][49],&bitmap[38][50],&bitmap[38][51],&bitmap[38][52],&bitmap[38][53],&bitmap[38][54],&bitmap[38][55],&bitmap[38][56],&bitmap[38][57],&bitmap[38][58],&bitmap[38][59],&bitmap[38][60],&bitmap[38][61],&bitmap[38][62],&bitmap[38][63],&bitmap[38][64],&bitmap[38][65],&bitmap[38][66],&bitmap[38][67],&bitmap[38][68],&bitmap[38][69],&bitmap[38][70],&bitmap[38][71],&bitmap[38][72],&bitmap[38][73],&bitmap[38][74],&bitmap[38][75],&bitmap[38][76],&bitmap[38][77],&bitmap[38][78],&bitmap[38][79],&bitmap[38][80],&bitmap[38][81],&bitmap[38][82],&bitmap[38][83],&bitmap[38][84],&bitmap[38][85],&bitmap[38][86],&bitmap[38][87],&bitmap[38][88],&bitmap[38][89],&bitmap[38][90],&bitmap[38][91],&bitmap[38][92],&bitmap[38][93],&bitmap[38][94],&bitmap[38][95],
					&bitmap[39][0],&bitmap[39][1],&bitmap[39][2],&bitmap[39][3],&bitmap[39][4],&bitmap[39][5],&bitmap[39][6],&bitmap[39][7],&bitmap[39][8],&bitmap[39][9],&bitmap[39][10],&bitmap[39][11],&bitmap[39][12],&bitmap[39][13],&bitmap[39][14],&bitmap[39][15],&bitmap[39][16],&bitmap[39][17],&bitmap[39][18],&bitmap[39][19],&bitmap[39][20],&bitmap[39][21],&bitmap[39][22],&bitmap[39][23],&bitmap[39][24],&bitmap[39][25],&bitmap[39][26],&bitmap[39][27],&bitmap[39][28],&bitmap[39][29],&bitmap[39][30],&bitmap[39][31],&bitmap[39][32],&bitmap[39][33],&bitmap[39][34],&bitmap[39][35],&bitmap[39][36],&bitmap[39][37],&bitmap[39][38],&bitmap[39][39],&bitmap[39][40],&bitmap[39][41],&bitmap[39][42],&bitmap[39][43],&bitmap[39][44],&bitmap[39][45],&bitmap[39][46],&bitmap[39][47],&bitmap[39][48],&bitmap[39][49],&bitmap[39][50],&bitmap[39][51],&bitmap[39][52],&bitmap[39][53],&bitmap[39][54],&bitmap[39][55],&bitmap[39][56],&bitmap[39][57],&bitmap[39][58],&bitmap[39][59],&bitmap[39][60],&bitmap[39][61],&bitmap[39][62],&bitmap[39][63],&bitmap[39][64],&bitmap[39][65],&bitmap[39][66],&bitmap[39][67],&bitmap[39][68],&bitmap[39][69],&bitmap[39][70],&bitmap[39][71],&bitmap[39][72],&bitmap[39][73],&bitmap[39][74],&bitmap[39][75],&bitmap[39][76],&bitmap[39][77],&bitmap[39][78],&bitmap[39][79],&bitmap[39][80],&bitmap[39][81],&bitmap[39][82],&bitmap[39][83],&bitmap[39][84],&bitmap[39][85],&bitmap[39][86],&bitmap[39][87],&bitmap[39][88],&bitmap[39][89],&bitmap[39][90],&bitmap[39][91],&bitmap[39][92],&bitmap[39][93],&bitmap[39][94],&bitmap[39][95],
					&bitmap[40][0],&bitmap[40][1],&bitmap[40][2],&bitmap[40][3],&bitmap[40][4],&bitmap[40][5],&bitmap[40][6],&bitmap[40][7],&bitmap[40][8],&bitmap[40][9],&bitmap[40][10],&bitmap[40][11],&bitmap[40][12],&bitmap[40][13],&bitmap[40][14],&bitmap[40][15],&bitmap[40][16],&bitmap[40][17],&bitmap[40][18],&bitmap[40][19],&bitmap[40][20],&bitmap[40][21],&bitmap[40][22],&bitmap[40][23],&bitmap[40][24],&bitmap[40][25],&bitmap[40][26],&bitmap[40][27],&bitmap[40][28],&bitmap[40][29],&bitmap[40][30],&bitmap[40][31],&bitmap[40][32],&bitmap[40][33],&bitmap[40][34],&bitmap[40][35],&bitmap[40][36],&bitmap[40][37],&bitmap[40][38],&bitmap[40][39],&bitmap[40][40],&bitmap[40][41],&bitmap[40][42],&bitmap[40][43],&bitmap[40][44],&bitmap[40][45],&bitmap[40][46],&bitmap[40][47],&bitmap[40][48],&bitmap[40][49],&bitmap[40][50],&bitmap[40][51],&bitmap[40][52],&bitmap[40][53],&bitmap[40][54],&bitmap[40][55],&bitmap[40][56],&bitmap[40][57],&bitmap[40][58],&bitmap[40][59],&bitmap[40][60],&bitmap[40][61],&bitmap[40][62],&bitmap[40][63],&bitmap[40][64],&bitmap[40][65],&bitmap[40][66],&bitmap[40][67],&bitmap[40][68],&bitmap[40][69],&bitmap[40][70],&bitmap[40][71],&bitmap[40][72],&bitmap[40][73],&bitmap[40][74],&bitmap[40][75],&bitmap[40][76],&bitmap[40][77],&bitmap[40][78],&bitmap[40][79],&bitmap[40][80],&bitmap[40][81],&bitmap[40][82],&bitmap[40][83],&bitmap[40][84],&bitmap[40][85],&bitmap[40][86],&bitmap[40][87],&bitmap[40][88],&bitmap[40][89],&bitmap[40][90],&bitmap[40][91],&bitmap[40][92],&bitmap[40][93],&bitmap[40][94],&bitmap[40][95],
					&bitmap[41][0],&bitmap[41][1],&bitmap[41][2],&bitmap[41][3],&bitmap[41][4],&bitmap[41][5],&bitmap[41][6],&bitmap[41][7],&bitmap[41][8],&bitmap[41][9],&bitmap[41][10],&bitmap[41][11],&bitmap[41][12],&bitmap[41][13],&bitmap[41][14],&bitmap[41][15],&bitmap[41][16],&bitmap[41][17],&bitmap[41][18],&bitmap[41][19],&bitmap[41][20],&bitmap[41][21],&bitmap[41][22],&bitmap[41][23],&bitmap[41][24],&bitmap[41][25],&bitmap[41][26],&bitmap[41][27],&bitmap[41][28],&bitmap[41][29],&bitmap[41][30],&bitmap[41][31],&bitmap[41][32],&bitmap[41][33],&bitmap[41][34],&bitmap[41][35],&bitmap[41][36],&bitmap[41][37],&bitmap[41][38],&bitmap[41][39],&bitmap[41][40],&bitmap[41][41],&bitmap[41][42],&bitmap[41][43],&bitmap[41][44],&bitmap[41][45],&bitmap[41][46],&bitmap[41][47],&bitmap[41][48],&bitmap[41][49],&bitmap[41][50],&bitmap[41][51],&bitmap[41][52],&bitmap[41][53],&bitmap[41][54],&bitmap[41][55],&bitmap[41][56],&bitmap[41][57],&bitmap[41][58],&bitmap[41][59],&bitmap[41][60],&bitmap[41][61],&bitmap[41][62],&bitmap[41][63],&bitmap[41][64],&bitmap[41][65],&bitmap[41][66],&bitmap[41][67],&bitmap[41][68],&bitmap[41][69],&bitmap[41][70],&bitmap[41][71],&bitmap[41][72],&bitmap[41][73],&bitmap[41][74],&bitmap[41][75],&bitmap[41][76],&bitmap[41][77],&bitmap[41][78],&bitmap[41][79],&bitmap[41][80],&bitmap[41][81],&bitmap[41][82],&bitmap[41][83],&bitmap[41][84],&bitmap[41][85],&bitmap[41][86],&bitmap[41][87],&bitmap[41][88],&bitmap[41][89],&bitmap[41][90],&bitmap[41][91],&bitmap[41][92],&bitmap[41][93],&bitmap[41][94],&bitmap[41][95],
					&bitmap[42][0],&bitmap[42][1],&bitmap[42][2],&bitmap[42][3],&bitmap[42][4],&bitmap[42][5],&bitmap[42][6],&bitmap[42][7],&bitmap[42][8],&bitmap[42][9],&bitmap[42][10],&bitmap[42][11],&bitmap[42][12],&bitmap[42][13],&bitmap[42][14],&bitmap[42][15],&bitmap[42][16],&bitmap[42][17],&bitmap[42][18],&bitmap[42][19],&bitmap[42][20],&bitmap[42][21],&bitmap[42][22],&bitmap[42][23],&bitmap[42][24],&bitmap[42][25],&bitmap[42][26],&bitmap[42][27],&bitmap[42][28],&bitmap[42][29],&bitmap[42][30],&bitmap[42][31],&bitmap[42][32],&bitmap[42][33],&bitmap[42][34],&bitmap[42][35],&bitmap[42][36],&bitmap[42][37],&bitmap[42][38],&bitmap[42][39],&bitmap[42][40],&bitmap[42][41],&bitmap[42][42],&bitmap[42][43],&bitmap[42][44],&bitmap[42][45],&bitmap[42][46],&bitmap[42][47],&bitmap[42][48],&bitmap[42][49],&bitmap[42][50],&bitmap[42][51],&bitmap[42][52],&bitmap[42][53],&bitmap[42][54],&bitmap[42][55],&bitmap[42][56],&bitmap[42][57],&bitmap[42][58],&bitmap[42][59],&bitmap[42][60],&bitmap[42][61],&bitmap[42][62],&bitmap[42][63],&bitmap[42][64],&bitmap[42][65],&bitmap[42][66],&bitmap[42][67],&bitmap[42][68],&bitmap[42][69],&bitmap[42][70],&bitmap[42][71],&bitmap[42][72],&bitmap[42][73],&bitmap[42][74],&bitmap[42][75],&bitmap[42][76],&bitmap[42][77],&bitmap[42][78],&bitmap[42][79],&bitmap[42][80],&bitmap[42][81],&bitmap[42][82],&bitmap[42][83],&bitmap[42][84],&bitmap[42][85],&bitmap[42][86],&bitmap[42][87],&bitmap[42][88],&bitmap[42][89],&bitmap[42][90],&bitmap[42][91],&bitmap[42][92],&bitmap[42][93],&bitmap[42][94],&bitmap[42][95],
					&bitmap[43][0],&bitmap[43][1],&bitmap[43][2],&bitmap[43][3],&bitmap[43][4],&bitmap[43][5],&bitmap[43][6],&bitmap[43][7],&bitmap[43][8],&bitmap[43][9],&bitmap[43][10],&bitmap[43][11],&bitmap[43][12],&bitmap[43][13],&bitmap[43][14],&bitmap[43][15],&bitmap[43][16],&bitmap[43][17],&bitmap[43][18],&bitmap[43][19],&bitmap[43][20],&bitmap[43][21],&bitmap[43][22],&bitmap[43][23],&bitmap[43][24],&bitmap[43][25],&bitmap[43][26],&bitmap[43][27],&bitmap[43][28],&bitmap[43][29],&bitmap[43][30],&bitmap[43][31],&bitmap[43][32],&bitmap[43][33],&bitmap[43][34],&bitmap[43][35],&bitmap[43][36],&bitmap[43][37],&bitmap[43][38],&bitmap[43][39],&bitmap[43][40],&bitmap[43][41],&bitmap[43][42],&bitmap[43][43],&bitmap[43][44],&bitmap[43][45],&bitmap[43][46],&bitmap[43][47],&bitmap[43][48],&bitmap[43][49],&bitmap[43][50],&bitmap[43][51],&bitmap[43][52],&bitmap[43][53],&bitmap[43][54],&bitmap[43][55],&bitmap[43][56],&bitmap[43][57],&bitmap[43][58],&bitmap[43][59],&bitmap[43][60],&bitmap[43][61],&bitmap[43][62],&bitmap[43][63],&bitmap[43][64],&bitmap[43][65],&bitmap[43][66],&bitmap[43][67],&bitmap[43][68],&bitmap[43][69],&bitmap[43][70],&bitmap[43][71],&bitmap[43][72],&bitmap[43][73],&bitmap[43][74],&bitmap[43][75],&bitmap[43][76],&bitmap[43][77],&bitmap[43][78],&bitmap[43][79],&bitmap[43][80],&bitmap[43][81],&bitmap[43][82],&bitmap[43][83],&bitmap[43][84],&bitmap[43][85],&bitmap[43][86],&bitmap[43][87],&bitmap[43][88],&bitmap[43][89],&bitmap[43][90],&bitmap[43][91],&bitmap[43][92],&bitmap[43][93],&bitmap[43][94],&bitmap[43][95],
					&bitmap[44][0],&bitmap[44][1],&bitmap[44][2],&bitmap[44][3],&bitmap[44][4],&bitmap[44][5],&bitmap[44][6],&bitmap[44][7],&bitmap[44][8],&bitmap[44][9],&bitmap[44][10],&bitmap[44][11],&bitmap[44][12],&bitmap[44][13],&bitmap[44][14],&bitmap[44][15],&bitmap[44][16],&bitmap[44][17],&bitmap[44][18],&bitmap[44][19],&bitmap[44][20],&bitmap[44][21],&bitmap[44][22],&bitmap[44][23],&bitmap[44][24],&bitmap[44][25],&bitmap[44][26],&bitmap[44][27],&bitmap[44][28],&bitmap[44][29],&bitmap[44][30],&bitmap[44][31],&bitmap[44][32],&bitmap[44][33],&bitmap[44][34],&bitmap[44][35],&bitmap[44][36],&bitmap[44][37],&bitmap[44][38],&bitmap[44][39],&bitmap[44][40],&bitmap[44][41],&bitmap[44][42],&bitmap[44][43],&bitmap[44][44],&bitmap[44][45],&bitmap[44][46],&bitmap[44][47],&bitmap[44][48],&bitmap[44][49],&bitmap[44][50],&bitmap[44][51],&bitmap[44][52],&bitmap[44][53],&bitmap[44][54],&bitmap[44][55],&bitmap[44][56],&bitmap[44][57],&bitmap[44][58],&bitmap[44][59],&bitmap[44][60],&bitmap[44][61],&bitmap[44][62],&bitmap[44][63],&bitmap[44][64],&bitmap[44][65],&bitmap[44][66],&bitmap[44][67],&bitmap[44][68],&bitmap[44][69],&bitmap[44][70],&bitmap[44][71],&bitmap[44][72],&bitmap[44][73],&bitmap[44][74],&bitmap[44][75],&bitmap[44][76],&bitmap[44][77],&bitmap[44][78],&bitmap[44][79],&bitmap[44][80],&bitmap[44][81],&bitmap[44][82],&bitmap[44][83],&bitmap[44][84],&bitmap[44][85],&bitmap[44][86],&bitmap[44][87],&bitmap[44][88],&bitmap[44][89],&bitmap[44][90],&bitmap[44][91],&bitmap[44][92],&bitmap[44][93],&bitmap[44][94],&bitmap[44][95],
					&bitmap[45][0],&bitmap[45][1],&bitmap[45][2],&bitmap[45][3],&bitmap[45][4],&bitmap[45][5],&bitmap[45][6],&bitmap[45][7],&bitmap[45][8],&bitmap[45][9],&bitmap[45][10],&bitmap[45][11],&bitmap[45][12],&bitmap[45][13],&bitmap[45][14],&bitmap[45][15],&bitmap[45][16],&bitmap[45][17],&bitmap[45][18],&bitmap[45][19],&bitmap[45][20],&bitmap[45][21],&bitmap[45][22],&bitmap[45][23],&bitmap[45][24],&bitmap[45][25],&bitmap[45][26],&bitmap[45][27],&bitmap[45][28],&bitmap[45][29],&bitmap[45][30],&bitmap[45][31],&bitmap[45][32],&bitmap[45][33],&bitmap[45][34],&bitmap[45][35],&bitmap[45][36],&bitmap[45][37],&bitmap[45][38],&bitmap[45][39],&bitmap[45][40],&bitmap[45][41],&bitmap[45][42],&bitmap[45][43],&bitmap[45][44],&bitmap[45][45],&bitmap[45][46],&bitmap[45][47],&bitmap[45][48],&bitmap[45][49],&bitmap[45][50],&bitmap[45][51],&bitmap[45][52],&bitmap[45][53],&bitmap[45][54],&bitmap[45][55],&bitmap[45][56],&bitmap[45][57],&bitmap[45][58],&bitmap[45][59],&bitmap[45][60],&bitmap[45][61],&bitmap[45][62],&bitmap[45][63],&bitmap[45][64],&bitmap[45][65],&bitmap[45][66],&bitmap[45][67],&bitmap[45][68],&bitmap[45][69],&bitmap[45][70],&bitmap[45][71],&bitmap[45][72],&bitmap[45][73],&bitmap[45][74],&bitmap[45][75],&bitmap[45][76],&bitmap[45][77],&bitmap[45][78],&bitmap[45][79],&bitmap[45][80],&bitmap[45][81],&bitmap[45][82],&bitmap[45][83],&bitmap[45][84],&bitmap[45][85],&bitmap[45][86],&bitmap[45][87],&bitmap[45][88],&bitmap[45][89],&bitmap[45][90],&bitmap[45][91],&bitmap[45][92],&bitmap[45][93],&bitmap[45][94],&bitmap[45][95],
					&bitmap[46][0],&bitmap[46][1],&bitmap[46][2],&bitmap[46][3],&bitmap[46][4],&bitmap[46][5],&bitmap[46][6],&bitmap[46][7],&bitmap[46][8],&bitmap[46][9],&bitmap[46][10],&bitmap[46][11],&bitmap[46][12],&bitmap[46][13],&bitmap[46][14],&bitmap[46][15],&bitmap[46][16],&bitmap[46][17],&bitmap[46][18],&bitmap[46][19],&bitmap[46][20],&bitmap[46][21],&bitmap[46][22],&bitmap[46][23],&bitmap[46][24],&bitmap[46][25],&bitmap[46][26],&bitmap[46][27],&bitmap[46][28],&bitmap[46][29],&bitmap[46][30],&bitmap[46][31],&bitmap[46][32],&bitmap[46][33],&bitmap[46][34],&bitmap[46][35],&bitmap[46][36],&bitmap[46][37],&bitmap[46][38],&bitmap[46][39],&bitmap[46][40],&bitmap[46][41],&bitmap[46][42],&bitmap[46][43],&bitmap[46][44],&bitmap[46][45],&bitmap[46][46],&bitmap[46][47],&bitmap[46][48],&bitmap[46][49],&bitmap[46][50],&bitmap[46][51],&bitmap[46][52],&bitmap[46][53],&bitmap[46][54],&bitmap[46][55],&bitmap[46][56],&bitmap[46][57],&bitmap[46][58],&bitmap[46][59],&bitmap[46][60],&bitmap[46][61],&bitmap[46][62],&bitmap[46][63],&bitmap[46][64],&bitmap[46][65],&bitmap[46][66],&bitmap[46][67],&bitmap[46][68],&bitmap[46][69],&bitmap[46][70],&bitmap[46][71],&bitmap[46][72],&bitmap[46][73],&bitmap[46][74],&bitmap[46][75],&bitmap[46][76],&bitmap[46][77],&bitmap[46][78],&bitmap[46][79],&bitmap[46][80],&bitmap[46][81],&bitmap[46][82],&bitmap[46][83],&bitmap[46][84],&bitmap[46][85],&bitmap[46][86],&bitmap[46][87],&bitmap[46][88],&bitmap[46][89],&bitmap[46][90],&bitmap[46][91],&bitmap[46][92],&bitmap[46][93],&bitmap[46][94],&bitmap[46][95],
					&bitmap[47][0],&bitmap[47][1],&bitmap[47][2],&bitmap[47][3],&bitmap[47][4],&bitmap[47][5],&bitmap[47][6],&bitmap[47][7],&bitmap[47][8],&bitmap[47][9],&bitmap[47][10],&bitmap[47][11],&bitmap[47][12],&bitmap[47][13],&bitmap[47][14],&bitmap[47][15],&bitmap[47][16],&bitmap[47][17],&bitmap[47][18],&bitmap[47][19],&bitmap[47][20],&bitmap[47][21],&bitmap[47][22],&bitmap[47][23],&bitmap[47][24],&bitmap[47][25],&bitmap[47][26],&bitmap[47][27],&bitmap[47][28],&bitmap[47][29],&bitmap[47][30],&bitmap[47][31],&bitmap[47][32],&bitmap[47][33],&bitmap[47][34],&bitmap[47][35],&bitmap[47][36],&bitmap[47][37],&bitmap[47][38],&bitmap[47][39],&bitmap[47][40],&bitmap[47][41],&bitmap[47][42],&bitmap[47][43],&bitmap[47][44],&bitmap[47][45],&bitmap[47][46],&bitmap[47][47],&bitmap[47][48],&bitmap[47][49],&bitmap[47][50],&bitmap[47][51],&bitmap[47][52],&bitmap[47][53],&bitmap[47][54],&bitmap[47][55],&bitmap[47][56],&bitmap[47][57],&bitmap[47][58],&bitmap[47][59],&bitmap[47][60],&bitmap[47][61],&bitmap[47][62],&bitmap[47][63],&bitmap[47][64],&bitmap[47][65],&bitmap[47][66],&bitmap[47][67],&bitmap[47][68],&bitmap[47][69],&bitmap[47][70],&bitmap[47][71],&bitmap[47][72],&bitmap[47][73],&bitmap[47][74],&bitmap[47][75],&bitmap[47][76],&bitmap[47][77],&bitmap[47][78],&bitmap[47][79],&bitmap[47][80],&bitmap[47][81],&bitmap[47][82],&bitmap[47][83],&bitmap[47][84],&bitmap[47][85],&bitmap[47][86],&bitmap[47][87],&bitmap[47][88],&bitmap[47][89],&bitmap[47][90],&bitmap[47][91],&bitmap[47][92],&bitmap[47][93],&bitmap[47][94],&bitmap[47][95]
		);*/
		
		fclose(fichier); //On ferme le fichier
		
		return (temp == 1);
	}
	//Si l'ouverture n'a pas fonctionnée
	return false;
}

void effacerEcran() {
	PA_Clear16bitBg(0);
	PA_Clear16bitBg(1);
	PA_16cErase(0);
	PA_16cErase(1);
	PA_ResetSpriteSys();
}

void retour2D() {
	PA_Reset3DSprites();
	PA_Init2D();
	
	PA_Init16bitBg(0,3);
	PA_Init16bitBg(1,3);
	PA_Init16cBg(0,1);
	PA_Init16cBg(1,1);
	
	effacerEcran();
}

/* ANCIENNES FONCTIONS
void EFS_LoadSprite(u8 screen, u8 number, const char* name, u8  obj_shape, u8 obj_size,  u8 color_mode, s16 x, s16 y) {
 
	if (color_mode == 0) {
		char filenamePal[16];
		sprintf ( filenamePal, "/%s_Pal.bin", name);
	 
		EFS_FILE* filePal;
		filePal= EFS_fopen (filenamePal);
		char* paletteBuffer;
		 
		paletteBuffer = (char*)malloc(EFS_GetFileSize(filePal));	//allocates memory for file
		EFS_fread(paletteBuffer, 1, EFS_GetFileSize(filePal), filePal);	//reads file to that memory
		EFS_fclose(filePal);	//closes file
		
		PA_LoadPal16(PAL_SPRITE0,number,paletteBuffer);	// On va dire qu'on charge un sprite 4bits que sur l'écran du bas... ^^'
	}
	else {
		char filenamePal[256];
		sprintf ( filenamePal, "/%s_Pal.bin", name);
	 
		EFS_FILE* filePal;
		filePal= EFS_fopen (filenamePal);
		char* paletteBuffer;
		
		paletteBuffer = (char*)malloc(EFS_GetFileSize(filePal));	//allocates memory for file
		EFS_fread(paletteBuffer, 1, EFS_GetFileSize(filePal), filePal);	//reads file to that memory
		EFS_fclose(filePal);	//closes file
		
		PA_LoadSpritePal(screen,number,paletteBuffer);
	}
		
		
	char filename[256];
	sprintf ( filename, "/%s_Sprite.bin", name);
 
	EFS_FILE* file; 
	file= EFS_fopen (filename);
	char* spriteBuffer;
	spriteBuffer = (char*)malloc(EFS_GetFileSize(file));
	EFS_fread(spriteBuffer, 1, EFS_GetFileSize(file), file);
	EFS_fclose(file);
 
	PA_CreateSprite(screen, // Screen
				number, // Sprite number
				spriteBuffer, // Sprite name
				obj_shape,// Sprite size
				obj_size, 
				color_mode, // 256 color mode
				number, // Sprite palette number
				x, y); // X and Y position on the screen
}

void EFS_LoadBG8(u8 screen, const char* name) {
 
	// Palette
	char filenamePal[256];
	sprintf ( filenamePal, "/%s_Pal.bin", name);
 
	EFS_FILE* filePal;
	filePal= EFS_fopen (filenamePal);
        char* paletteBuffer;
 
	paletteBuffer = (char*)malloc(EFS_GetFileSize(filePal));//allocates memory for file
	EFS_fread(paletteBuffer, 1, EFS_GetFileSize(filePal), filePal);//reads file to that memory
	EFS_fclose(filePal);//closes file
 
	PA_Load8bitBgPal(screen, // Screen
			   paletteBuffer);	// Palette name
	
	// Bitmap
	char filename[256];
	sprintf ( filename, "/%s_Bitmap.bin", name);
 
	EFS_FILE* file; 
	file= EFS_fopen (filename);
	char* spriteBuffer;
	spriteBuffer = (char*)malloc(EFS_GetFileSize(file));
	EFS_fread(spriteBuffer, 1, EFS_GetFileSize(file), file);
	EFS_fclose(file);
 
	PA_Load8bitBitmap(screen, // Screen
				spriteBuffer); // Sprite name
}
 
// La fonction EFS_CreateSprite

void EFS_LoadBG16(u8 screen, u8 sprite_number, const char* name, u8  obj_shape, u8 obj_size,  u8 color_mode, u8 palette, s16 x, s16 y) {	
 
	char filename[256];
	sprintf ( filename, "/%s_Sprite.bin", name);
 
	EFS_FILE* file; 
	file= EFS_fopen (filename);
	char* spriteBuffer;
	spriteBuffer = (char*)malloc(EFS_GetFileSize(file));
	EFS_fread(spriteBuffer, 1, EFS_GetFileSize(file), file);
	EFS_fclose(file);
 
	PA_CreateSprite(screen, // Screen
				sprite_number, // Sprite number
				spriteBuffer, // Sprite name
				obj_shape,// Sprite size
				obj_size, 
				color_mode, // 256 color mode
				palette, // Sprite palette number
				x, y); // X and Y position on the screen
}

void EFS_LoadCadre(int sprite,int numero,int x,int y) {
	char nom[2];
	sprintf(nom,"%02d",numero);
	EFS_LoadSprite(0,sprite,strcat("img/cadres/persoc",nom),OBJ_SIZE_64X64,1,x,y);
}
*/

void playMusic(const char* nom) {
	int essais=0;
	bool chargement;
	FILE* file;
	
	sprintf(id_music,"%s",nom);
	
	char filename[256];
	sprintf(filename,"/bgm/%s.mp3",nom);
	
	do {
		file= fopen (filename, "rb");
		essais++;
		if (essais == 10) {
			return;
		}
	}
	while (file == NULL);
	
	u32 fileSize = EFS_GetFileSize(file);
	
	essais=0;
	do {
		chargement = (musique_buffer = (u8*)malloc(fileSize)) ? true : false;
		essais++;
		if (essais == 10) {
			fclose(file);
			free(musique_buffer);
			return;
		}
	}
	while (!chargement);
	
	fread(musique_buffer, 1, fileSize, file);
	fclose(file);
	
	AS_MP3DirectPlay(musique_buffer,fileSize);
	
	free(musique_buffer);
	
	PA_WaitForVBL();
}

void loadBg(int ecran,const char* nom,bool langue) {
	free(bgBitmap[ecran]);
	
	char filenameTex[256];
	if (langue) {
		sprintf(filenameTex,"/bg/%s%01d_Bitmap.bin",nom,lang);
	}
	else {
		sprintf(filenameTex,"/bg/%s_Bitmap.bin",nom);
	}
	
	FILE* fileTex; 
	fileTex= fopen (filenameTex, "rb");
	bgBitmap[ecran] = (char*)malloc(EFS_GetFileSize(fileTex));
	fread(bgBitmap[ecran], 1, EFS_GetFileSize(fileTex), fileTex);
	fclose(fileTex);
	
	PA_WaitForVBL();
	
	PA_Load16bitBitmap(ecran,bgBitmap[ecran]);
}

void loadCarteMem(int sprite,int taille,int couleur,int numero) {
	int i;
	
	if (taille) {	// Dans ce cas, sprite défini la couleur
		free(carteG3D_tex);
		
		char filenameTex[256];
		sprintf ( filenameTex, "/texture/c%03d%01d1_Texture.bin",numero,couleur);
		FILE* fileTex; 
		fileTex= fopen (filenameTex, "rb");
		carteG3D_tex = (char*)malloc(EFS_GetFileSize(fileTex));
		fread(carteG3D_tex, 1, EFS_GetFileSize(fileTex), fileTex);
		fclose(fileTex);
			
		char filenamePal[256];
		char * palette;
		sprintf ( filenamePal, "/texture/c%03d%01d1_Pal.bin",numero,couleur);
		FILE* filePal; 
		filePal= fopen (filenamePal, "rb");
		palette = (char*)malloc(EFS_GetFileSize(filePal));
		fread(palette, 1, EFS_GetFileSize(filePal), filePal);
		fclose(filePal);
		
		PA_WaitForVBL();
		PA_3DProcess();
		
		PA_Load3DSpritePal(sprite,palette);
		
		PA_WaitForVBL();
		PA_3DProcess();
	}
	else {
		for (i=0;i<2;i++) {
			free(carte_gfx[i][sprite]);
			free(carte_pal[i][sprite]);
			
			char filenameTex[256];
			sprintf ( filenameTex, "/texture/c%03d%01d0_Texture.bin",numero,i);
		 
			FILE* fileTex; 
			fileTex= fopen (filenameTex, "rb");
			carte_gfx[i][sprite] = (char*)malloc(EFS_GetFileSize(fileTex));
			fread(carte_gfx[i][sprite], 1, EFS_GetFileSize(fileTex), fileTex);
			fclose(fileTex);
			
			char filenamePal[256];
			sprintf ( filenamePal, "/texture/c%03d%01d0_Pal.bin",numero,i);
		 
			FILE* filePal; 
			filePal= fopen (filenamePal, "rb");
			carte_pal[i][sprite] = (char*)malloc(EFS_GetFileSize(filePal));
			fread(carte_pal[i][sprite], 1, EFS_GetFileSize(filePal), filePal);
			fclose(filePal);
			
			PA_WaitForVBL();
			PA_3DProcess();
		}
	}
}

void loadCarte3D(bool create,int sprite,int taille,int couleur,int ref,int x,int y) {
	if (taille) {
		if (create) {
			carteG3D_gfx = PA_3DCreateTex(carteG3D_tex,64,64,TEX_256COL);
			PA_3DCreateSpriteFromTex(sprite,carteG3D_gfx,62,62,sprite,x,y);
		}
		else {
			PA_3DUpdateGfx(carteG3D_gfx,carteG3D_tex);
		}
	}
	else {
		PA_Load3DSpritePal(sprite,carte_pal[couleur][ref]);
		if (create) {
			carte3D_gfx[sprite] = PA_3DCreateTex(carte_gfx[couleur][ref],64,64,TEX_256COL);
			PA_3DCreateSpriteFromTex(sprite,carte3D_gfx[sprite],50,50,sprite,x,y);
		}
		else {
			PA_3DUpdateGfx(carte3D_gfx[sprite],carte_gfx[couleur][ref]);
		}
	}
}

/*void EFS_PlaySound(const char* name,int num) {
	char filename[256];
	sprintf ( filename, "/sound/%s.raw", name);
	EFS_FILE* rawFile = EFS_fopen (filename); 
 
	u32 rawSize;
	EFS_fseek (rawFile , 0 , SEEK_END);
	rawSize =  EFS_ftell (rawFile);
	rewind (rawFile);
 
	// allocate memory to store the raw file
	//char * rawBuffer;
	//rawBuffer = (char*) malloc (sizeof(char)*rawSize);
 
 
	//EFS_fread (rawBuffer,1,rawSize,rawFile);
	// close the file
	EFS_fclose (rawFile);
	//playing the sound	
	//PA_PlaySoundEx2(1, rawBuffer, rawSize, 127, 44100,1,false,0);
	
	switch (num) {
		case 0:
		AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
		break;
		
		case 1:
		AS_SoundDefaultPlay((void*)bruitCarte,8576,127,64,0,0);
		break;
		
		case 2:
		//AS_SoundDefaultPlay((void*)bruitMain,41988,127,64,0,0);
		break;
		
		case 3:
		AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
		break;
		
		case 4:
		AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
		break;
		
		case 5:
		AS_SoundDefaultPlay((void*)ok,240100,127,64,0,0);
		break;
		
		case 6:
		AS_SoundDefaultPlay((void*)ouvrir,171340,127,64,0,0);
		break;
		
		case 7:
		AS_SoundDefaultPlay((void*)valider,179792,127,64,0,0);
		break;
		
		default:
		break;
	}
	
	//AS_SoundDefaultPlay((void*)name,rawSize,127,64,0,0);
    //    free(rawBuffer);
}

void EFS_PlayBgm(int numero,int partieMusique) {
	PA_WaitFor(!IPC_Sound->chan[0].busy);
	numeroMusique = numero;
	char filename[256];
	sprintf(filename,"/bgm/%02d%01d.mp3",numeroMusique,partieMusique);
	AS_MP3StreamPlay(filename);
	if (partieMusique == 0) {
		musique = true;
	}
}*/

void afficherCarteAdv() {
	if (wifiOn && choixCarteWifi) {
		int i;
		
		for (i=0;i<5;i++) {
			if (enleverCarteWifi[i]) {
				ajouterCarteWifi[i] = false;
				vitesseWifi[i]++;
				yActuelWifi[i] -= vitesseWifi[i];
				if (yActuelWifi[i] <= yInitCarte) {
					yActuelWifi[i] = yInitCarte;
					vitesseWifi[i] = vitesseAfficherCarte;
					enleverCarteWifi[i] = false;
				}
				PA_3DSetSpriteY(i,yActuelWifi[i]);
			}
			else if (ajouterCarteWifi[i]) {
				if ((yActuelWifi[i]+distanceArretCarte > yFinalWifi[i]) && (vitesseWifi[i] > 0)) {
					vitesseWifi[i]--;
				}
				yActuelWifi[i] += vitesseWifi[i];
				if (yActuelWifi[i] >= yFinalWifi[i]) {
					yActuelWifi[i] = yFinalWifi[i];
					vitesseWifi[i] = 0;
					ajouterCarteWifi[i] = false;
					AS_SoundDefaultPlay((void*)bruitCarte,8576,127,64,0,0);
				}
				PA_3DSetSpriteY(i,yActuelWifi[i]);
			}
		}
	}
}

void afficherStatus(int couleur,char * texte) {
	PA_16cTextAlign(ALIGN_CENTER);
	PA_16cClearZone(0,0,174,256,192);
	PA_16cText(0,0,178,256,192,texte,couleur,5,strlen(texte));
}

void envoiWifi(bool attente,unsigned short canal,unsigned char *data,int length) {
	LOBBY_SendToRoom(LOBBY_GetRoomByID(ROOMID_MYROOM),canal,data,length);
	do {
		PA_3DProcess();
		PA_WaitForVBL();
		afficherCarteAdv();
	}
	while (attente && !LOBBY_UserIsAllSent(LOBBY_GetRoomUserBySlot(LOBBY_GetRoomByID(ROOMID_MYROOM),(wifiOn==1 ? 1 : 0))));
}

void attenteWifi() {

	int timerOut=0;
	etape++;
	envoiWifi(true,0x0005,"",etape);
	
	for (timerOut=0;timerOut<6;timerOut++) {
		PA_3DProcess();
		PA_WaitForVBL();
		afficherCarteAdv();
	}
	
	while (etapeWifi != etape) {
		timerOut++;
		if (timerOut == 60) {		// On attend une seconde et on demande l'étape de l'autre DS
			envoiWifi(true,0x0005,"",555);
			timerOut = 0;
		}
		
		PA_3DProcess();
		PA_WaitForVBL();
		afficherCarteAdv();
	}
	//etape = etapeWifi;
	
	for (timerOut=0;timerOut<12;timerOut++) {
		PA_3DProcess();
		PA_WaitForVBL();
		afficherCarteAdv();
	}
}

void fadeBlack(int speed,bool screen1,bool screen2,bool music,int io) {
	int i,j;
	int volume = 127*(1-io);
	int volumeStep = (128/(32*speed))*(2*io-1);
	
	for (i=-31*io;i!=-32+33*io;i-=1-2*io) {
		if (screen1) {
			PA_SetBrightness(0,i);
		}
		if (screen2) {
			PA_SetBrightness(1,i);
		}
		for (j=0;j<speed;j++) {
			if (music) {
				volume += volumeStep;
				AS_SetMP3Volume(volume);
			}
			PA_CheckLid();
			PA_WaitForVBL();
		}
	}
	
	if (music) {
		AS_SetMP3Volume(127*io);
	}
}


bool afficherFenetre3D(int mode,const char* texte) {

	PA_3DSetSpriteY(15,96);
	PA_3DSetSpriteY(16,67);
	PA_3DSetSpriteFrame(16,mode);

	PA_16cClearZone(0,64,63,192,126);
	
	PA_16cTextAlign(ALIGN_CENTER);
	PA_16cText(0,70,72,186,112,texte,1,5,strlen(texte));
	
	bool retour = false;
	
	// Remise à 0 de A et B et du stylet
	Pad.Newpress.A = false;
	Pad.Newpress.B = false;
	Stylus.Released = false;
	
	if (mode == 0) {
		PA_16cText(0,70,112,186,128,"Ok",1,5,2);
		PA_3DSetSpriteXY(10,110,120);
		
		PA_3DProcess();
		PA_WaitForVBL();
		
		while (!Pad.Newpress.A && !(Stylus.Released && PA_StylusInZone(119,110,137,124))) {
			if (wifiOn) {
				afficherCarteAdv();
			}
			
			PA_CheckLid();
			PA_3DProcess();
			PA_WaitForVBL();
		}
		
		AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
		
		retour = true;
	}
	else if (mode == 1) {
	
		PA_16cText(0,70,112,186,128,message[lang][0],1,5,22);
		PA_3DSetSpriteXY(10,88,120);
		int positionCurseur = 0;
		
		while (1) {
			if ((Pad.Newpress.Right && (positionCurseur == 0)) || (Pad.Newpress.Left && positionCurseur)) {
				positionCurseur = 1 - positionCurseur;
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
			}
			if (Pad.Newpress.A) {
				if (positionCurseur) {
					AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
					retour = false;
					break;
				}
				else {
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					retour = true;
					break;
				}
			}
			if (Pad.Newpress.B) {
				AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
				retour = false;
				break;
			}
			if (Stylus.Newpress || Stylus.Held) {
				if ((PA_StylusInZone(96,110,115,124) && positionCurseur) || (PA_StylusInZone(138,110,162,124) && (positionCurseur == 0))) {
					positionCurseur = 1 - positionCurseur;
				}
			}
			if (Stylus.Released) {
				if (PA_StylusInZone(96,110,115,124)) {
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					retour = true;
					break;
				}
				else if (PA_StylusInZone(138,110,162,124)) {
					AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
					retour = false;
					break;
				}
			}
			PA_3DSetSpriteX(10,88+39*positionCurseur);
			
			if (wifiOn) {
				afficherCarteAdv();
			}
			
			PA_CheckLid();
			PA_3DProcess();
			PA_WaitForVBL();
		}
	}
	
	PA_16cClearZone(0,64,64,192,126);
	
	PA_3DSetSpriteY(15,288);
	PA_3DSetSpriteY(16,259);
	
	PA_3DProcess();
	PA_WaitForVBL();
	
	return retour;
}

bool afficherFenetre(int mode,const char* texte) {
	//PA_LoadPal16(PAL_SPRITE0,1,(void*)hautFenetre_Pal);
	PA_LoadSpritePal(0,2,(void*)fenetre_Pal);
	PA_CreateSprite(0,1,(void*)hautFenetre_Sprite,OBJ_SIZE_32X8,0,0,67,64);
	PA_CreateSprite(0,2,(void*)fenetre0_Sprite,OBJ_SIZE_64X64,1,2,64,64);
	PA_CreateSprite(0,3,(void*)fenetre1_Sprite,OBJ_SIZE_64X64,1,2,128,64);
	PA_SetSpriteAnim(0,1,mode);
	PA_SetSpritePrio(0,1,2);
	PA_SetSpritePrio(0,2,2);
	PA_SetSpritePrio(0,3,2);
	
	PA_16cClearZone(0,64,64,192,128);
	
	int posInitX = PA_GetSpriteX(0,0);
	int posInitY = PA_GetSpriteY(0,0);
	
	PA_16cTextAlign(ALIGN_CENTER);
	PA_16cText(0,70,72,186,112,texte,1,5,strlen(texte));
	
	bool retour = false;
	
	// Remise à 0 de A et B
	Pad.Newpress.A = false;
	Pad.Newpress.B = false;
	Stylus.Released = false;
	
	if (mode == 0) {
		PA_16cText(0,70,112,186,128,"Ok",1,5,2);
		PA_SetSpriteXY(0,0,100,114);
		
		PA_WaitFor(Pad.Newpress.A || (Stylus.Released && PA_StylusInZone(119,110,137,124)));
		
		AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
		
		retour = true;
	}
	else if (mode == 1) {
		PA_16cText(0,70,112,186,128,message[lang][0],1,5,22);
		PA_SetSpriteXY(0,0,78,114);
		int positionCurseur = 0;
		
		while (1) {
			if ((Pad.Newpress.Right && (positionCurseur == 0)) || (Pad.Newpress.Left && positionCurseur)) {
				positionCurseur = 1 - positionCurseur;
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
			}
			if (Pad.Newpress.A) {
				if (positionCurseur) {
					AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
					retour = false;
					break;
				}
				else {
					AS_SoundDefaultPlay((void*)valider,179792,127,64,0,0);
					retour = true;
					break;
				}
			}
			if (Pad.Newpress.B) {
				AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
				retour = false;
				break;
			}
			if (Stylus.Newpress || Stylus.Held) {
				if ((PA_StylusInZone(96,110,115,124) && positionCurseur) || (PA_StylusInZone(138,110,162,124) && (positionCurseur == 0))) {
					positionCurseur = 1 - positionCurseur;
				}
			}
			if (Stylus.Released) {
				if (PA_StylusInZone(96,110,115,124)) {
					AS_SoundDefaultPlay((void*)valider,179792,127,64,0,0);
					retour = true;
					break;
				}
				else if (PA_StylusInZone(138,110,162,124)) {
					AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
					retour = false;
					break;
				}
			}
			PA_SetSpriteX(0,0,78+39*positionCurseur);
			PA_CheckLid();
			PA_WaitForVBL();
		}
	}
	
	PA_DeleteSprite(0,1);
	PA_DeleteSprite(0,2);
	PA_DeleteSprite(0,3);
	PA_16cClearZone(0,64,64,192,126);
	PA_SetSpriteXY(0,0,posInitX,posInitY);
	
	PA_WaitForVBL();
	
	return retour;
}

void progressionWifi(int pourcent) {
	PA_16cClearZone(0,162,42,210,58);
	if (pourcent != -1) {
		int i,j;
		char affiche[4];
		PA_16cTextAlign(ALIGN_CENTER);
		sprintf(affiche,"%d%c",pourcent*100/48,'%');
		PA_16cText(0,162,42,210,58,affiche,1,5,4);
		for (i=0;i<pourcent;i++) {
			for (j=0;j<3;j++) {
				PA_16cPutPixel(0,162+i,56+j,1);
			}
		}
	}
}

int initChoixFinWifi() {

	int positionCurseur=0;
	int timer=0;
	int i;
	
	PA_3DSetSpriteY(15,96);
	PA_3DSetSpriteY(16,67);
	
	/*
	// Affichage de la fenetre de confirmation
	u16 fenetre3D_gfx = PA_3DCreateTex((void*)fenetre3D_Texture,128,64,TEX_256COL);
	PA_Load3DSpritePal(15, (void*)fenetre3D_Pal);
	PA_3DCreateSpriteFromTex(15,fenetre3D_gfx,128,64,15,128,96);
	PA_3DSetSpritePrio(15,2046);
	
	// Affichage du haut de page
	u16 haut3D_gfx = PA_3DCreateTex((void*)hautFenetre3D_Texture,128,8,TEX_4COL);
	PA_3DCreateSpriteFromTex(16,haut3D_gfx,128,6,12,128,67);
	PA_3DSetSpritePrio(16,2047);
	PA_3DSetSpriteFrame(16,1);*/
	
	PA_16cTextAlign(ALIGN_LEFT);
	PA_16cText(0,70,72,184,128,message[lang][1],1,5,32);
	PA_16cText(0,70,84,184,128,message[lang][2],1,5,32);
	PA_16cText(0,70,96,184,128,message[lang][3],1,5,32);
	PA_16cText(0,70,108,184,128,message[lang][4],1,5,32);
	
	PA_3DSetSpriteXY(10,58,81);
	
	while (1) {
		if (Pad.Newpress.Up || Pad.Newpress.Down) {
			positionCurseur += Pad.Newpress.Down - Pad.Newpress.Up;
			positionCurseur &= 3;
			AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
			timer = 0;
		}
		else if (Pad.Held.Up || Pad.Held.Down) {
			if (timer == timerCurseur1) {
				positionCurseur += Pad.Held.Down - Pad.Held.Up;
				positionCurseur &= 3;
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				timer -= timerCurseur2;
			}
			else {
				timer++;
			}
		}
		else if (Pad.Newpress.A || (Stylus.Released && PA_StylusInZone(68,72,182,120))) {
			AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
			break;
		}
		else if (Pad.Newpress.B) {
			AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
			positionCurseur = 3;
		}
		if (Stylus.Newpress || Stylus.Held) {
			for (i=0;i<4;i++) {
				if (PA_StylusInZone(68,72+12*i,182,84+12*i)) {
					positionCurseur = i;
				}
			}
		}
		PA_3DSetSpriteY(10,81+12*positionCurseur);
		PA_3DProcess();
		PA_WaitForVBL();
	}
	
	PA_16cErase(0);
	PA_3DSetSpriteY(10,256);
	PA_3DSetSpriteY(15,288);
	PA_3DSetSpriteY(16,259);
	
	return positionCurseur;
}

void majInfoCollection() {

	char affichage[3];
	char victoireAffichage[16];
	
	PA_16cErase(1);
	
	PA_16cTextAlign(ALIGN_LEFT);
	PA_16cText(1,8,8,256,192,message[lang][5],1,2,18);
	PA_16cText(1,16,18,256,192,message[lang][6],1,2,7);
	PA_16cText(1,16,28,256,192,message[lang][7],1,2,4);
	PA_16cText(1,16,38,256,192,message[lang][8],1,2,8);
	PA_16cText(1,16,48,256,192,message[lang][9],1,2,10);
	PA_16cText(1,16,58,256,192,message[lang][10],1,2,5);
	
	PA_16cTextAlign(ALIGN_RIGHT);
	sprintf(affichage,"%d",getNombreCarte(1,1,5));
	PA_16cText(1,16,18,112,192,affichage,1,2,3);
	sprintf(affichage,"%d",getNombreCarte(1,6,7));
	PA_16cText(1,16,28,112,192,affichage,1,2,3);
	sprintf(affichage,"%d",getNombreCarte(1,8,9));
	PA_16cText(1,16,38,112,192,affichage,1,2,3);
	sprintf(affichage,"%d",getNombreCarte(1,10,10));
	PA_16cText(1,16,48,112,192,affichage,1,2,3);
	sprintf(affichage,"%d",getNombreCarte(1,1,10));
	PA_16cText(1,16,58,112,192,affichage,1,2,3);
	
	PA_16cTextAlign(ALIGN_LEFT);
	sprintf(victoireAffichage,"%s : %d",message[lang][11],getNombreVictoires(0));
	PA_16cText(1,19,78,256,192,victoireAffichage,1,2,16);
	sprintf(victoireAffichage,"%s : %d",message[lang][12],getNombreVictoires(1));
	PA_16cText(1,23,88,256,192,victoireAffichage,1,2,16);
	sprintf(victoireAffichage,"%s : %d",message[lang][13],getNombreVictoires(2));
	PA_16cText(1,25,98,256,192,victoireAffichage,1,2,16);
}

void majMiniature(int carte) {
	int i;
	
	for (i=0;i<persoDebloque;i++) {
		if (i < 12) {
			//PA_3DSetSpriteAlpha(i+20,7);
			PA_3DSetSpriteY(i+20,-12);
			if (historique[carte]) {			// Si on a déjà possédé la carte
				if (carte < 77) {		// Cartes normales
					if ((((11*(carteLvlMax[i][0]-1)) < carte) && ((11*carteLvlMax[i][1]) >= carte)) && ((carte != 48) || (i == 11))) {
						PA_3DSetSpriteY(i+20,12);
						//PA_3DSetSpriteAlpha(i+20,16);
					}
				}
				else {					// Cartes rares
					if (cartesRares[i][carte-78]) {
						PA_3DSetSpriteY(i+20,12);
						//PA_3DSetSpriteAlpha(i+20,16);
					}
				}
			}
		}
	}
}

void majListeCollection(int page) {

	int i;
	int couleur;
	char affichage[16];
	
	PA_16cClearZone(0,0,0,256,174);
	
	for (i=0;i<11;i++) {
		couleur = -1;
		if (collection[i+11*page+1] > 0) {
			couleur = 1;
		}
		else if (historique[i+11*page+1]) {
			couleur = 3;
		}
		if (couleur > 0) {
			PA_16cTextAlign(ALIGN_LEFT);
			sprintf(affichage,"%s",nomCarte[lang][i+11*page+1]);
			PA_16cText(0,38,31+12*i,152,174,affichage,couleur,5,16);
			
			PA_16cTextAlign(ALIGN_RIGHT);
			sprintf(affichage,"%d",collection[i+11*page+1]);
			PA_16cText(0,38,31+12*i,152,174,affichage,couleur,5,3);
		}
	}
}

void majNiveauCollection(int page) {
	int niveau;
	char affiche[32];
	if (page == 9) {
		niveau = 9;
	}
	else if (page > 6) {
		niveau = 8;
	}
	else if (page > 4) {
		niveau = 7;
	}
	else {
		niveau = 6;
	}
	sprintf(affiche,"%s %s %s %d",message[lang][14],message[lang][niveau],message[lang][15],page+1);
	afficherStatus(1,affiche);
}

void majListePersoWifi(int page,int adversaire) {
	int i;
	int couleur;
	char affichage[16];
	
	PA_16cClearZone(0,0,0,256,174);
	PA_16cTextAlign(ALIGN_LEFT);
	
	for (i=0;i<11;i++) {
		if (i+11*page <= persoDebloque) {
			couleur = (i == adversaire+11*page) ? 3 : 1;
			sprintf(affichage,"%s",nomAdv[lang][i+11*page]);
			PA_16cText(0,70,28+12*i,184,172,affichage,couleur,5,16);
		}
	}
}

void majListeReglesWifi() {
	int i;
	int couleur;
	char affichage[16];
	
	PA_16cClearZone(0,0,0,256,174);
	PA_16cTextAlign(ALIGN_LEFT);
	
	for (i=0;i<8;i++) {
		couleur = reglePerso[i] ? 1 : 3;
		sprintf(affichage,"%s",nomRegle[lang][i]);
		PA_16cText(0,70,28+12*i,184,172,affichage,couleur,5,16);
	}
	
	PA_16cTextAlign(ALIGN_CENTER);
	
	PA_16cText(0,70,136,184,172,message[lang][16],1,5,16);
}

int majRegles(int * regles) {
	// On affiche l'écran du haut...
	int i=0;
	int ligne = 1;
	int colonne = 0;
	bool aucune = true;
	
	PA_16cClearZone(1,0,12,256,60);
	PA_16cTextAlign(ALIGN_LEFT);
	
	for (i=0;i<8;i++) {
		if (regles[i]) {
			if (colonne == 2) {
				colonne = 0;
				ligne++;
			}
			PA_16cText(1,16+128*colonne,2+10*ligne,256,192,nomRegle[lang][i],1,2,strlen(nomRegle[lang][i]));
			colonne++;
			aucune = false;
		}
	}
	
	if (aucune) {
		PA_16cText(1,16+128*colonne,2+10*ligne,256,192,message[lang][17],1,2,6);
	}
	
	return ligne;
}

void majScoreWifi() {
	PA_16cClearZone(1,0,60,256,74);
	char affiche[6];
	
	PA_16cTextAlign(ALIGN_RIGHT);
	sprintf(affiche,"%d -",scoreWifi[0]);
	PA_16cText(1,0,62,128,72,affiche,1,3,6);
	
	PA_16cTextAlign(ALIGN_LEFT);
	sprintf(affiche,"- %d",scoreWifi[1]);
	PA_16cText(1,128,62,256,72,affiche,1,3,6);
}

void majScore() {
	int scoreTemp = 0;
	int i,j;
	for (i=1;i<4;i++) {
		for (j=1;j<4;j++) {
			if (plateauJoueur[i][j] == 1) {
				scoreTemp++;
			}
		}
	}
	for (i=0;i<5;i++) {
		if (!carteJouee[1][i]) {
			scoreTemp++;
		}
	}
	scoreJoueur = scoreTemp;
}

void majCarteG(int couleur,int carte) {
	if (couleur == -1) {
		couleur = 0;
	}
	PA_3DProcess();
	PA_WaitForVBL();
	PA_LoadSpritePal(1,3,(void*)carteG_Pal[couleur][carte]);
	PA_UpdateGfx(1,carteG_gfx,(void*)carteG_Sprite[couleur][carte]);
}

void afficherNomCarte(int carte,int couleur,int offset) {
	if (couleur == -1) {
		if (offset && (collection[carte] == offset)) {
			if (historique[carte]) {
				couleur = 5;
			}
			else {
				couleur = 4;
			}
		}
		else if (collection[carte] > 0) {
			couleur = 1;
		}
		else if (historique[carte]) {
			couleur = 5;
		}
		else {
			couleur = 4;
		}
	}
	
	afficherStatus(couleur,nomCarte[lang][carte]);
}

void retournerCartes(int sens[10],int couleur,bool identique,bool plus,bool combo,bool carteBrille[3][3]) {
	
	int i,j;
	int id=100;
	int frame=0;
	int frameRegle=0;
	int rot = 16;
	int caseX,caseY;
	float zoom = 1;
	bool ok = true;
	bool brille=false;
	
	if (combo) {
		frameRegle = 2;
	}
	else if (plus) {
		frameRegle = 1;
	}
	
	PA_3DSetSpriteFrame(31,frameRegle);
	
	// Si on a Identique ou Plus, on fait briller les cartes et on affiche la règle
	if (combo) {
		for (i=1;i<9;i++) {
			PA_3DSetSpriteX(31,384-32*i);
			PA_CheckLid();
			PA_3DProcess();
			PA_WaitForVBL();
		}
		for (i=0;i<24;i++) {
			PA_CheckLid();
			PA_3DProcess();
			PA_WaitForVBL();
		}
		for (i=1;i<9;i++) {
			PA_3DSetSpriteX(31,128-32*i);
			PA_CheckLid();
			PA_3DProcess();
			PA_WaitForVBL();
		}
		PA_3DSetSpriteX(31,384);
	}
	else if (identique || plus) {
		for (i=1;i<9;i++) {
			PA_3DSetSpriteX(31,384-32*i);
			PA_CheckLid();
			PA_3DProcess();
			PA_WaitForVBL();
		}
		AS_SoundDefaultPlay((void*)ouvrir,171340,127,64,0,0);
		for (i=0;i<3;i++) {
			for (j=0;j<3;j++) {
				if (carteBrille[j][i]) {
					brille = true;
					break;
				}
			}
			if (brille) {
				break;
			}
		}
		if (combo && !brille) {
			for (i=0;i<48;i++) {
				PA_CheckLid();
				PA_3DProcess();
				PA_WaitForVBL();
			}
		}
		else {
			for (i=0;i<3;i++) {
				for (j=0;j<3;j++) {
					if (carteBrille[j][i]) {
						if (id == 100) {
							id = 32+3*i+j;
						}
						PA_3DCreateSpriteFromTex(32+3*i+j,brille_gfx,64,64,11,78+50*j,39+50*i);
						PA_3DSetSpriteFrame(32+3*i+j,0);
						PA_3DSetSpritePrio(32+3*i+j,2009);
					}
				}
			}
			for (i=0;i<48;i++) {
				if (frame < i/8) {
					frame++;
					PA_3DSetSpriteFrame(id,frame);
				}
				PA_CheckLid();
				PA_3DProcess();
				PA_WaitForVBL();
			}
			for (i=0;i<4;i++) {
				for (j=0;j<4;j++) {
					if (carteBrille[j][i]) {
						PA_3DDeleteSprite(32+3*i+j);
					}
				}
			}
		}
		for (i=1;i<9;i++) {
			PA_3DSetSpriteX(31,128-32*i);
			PA_CheckLid();
			PA_3DProcess();
			PA_WaitForVBL();
		}
		PA_3DSetSpriteX(31,384);
	}
	
	for (i=0;i<10;i++) {
		if (sens[i] != -1) {
			ok = false;
			PA_3DSetSpritePrio(i,2001);
			caseX = getCaseX(i);
			caseY = getCaseY(i);
			if (bonusCase[caseX+1][caseY+1] != 0) {
				PA_3DSetSpriteY(22+3*caseY+caseX,256);
			}
		}
	}
	
	/*for (i=0;i<3;i++) {
		for (j=0;j<3;j++) {
			if (sens[idCarte[i+1][j+1]] != -1) {
				ok = false;
				PA_3DSetSpritePrio(idCarte[i+1][j+1],2001);
				if (bonusCase[i+1][j+1] != 0) {
					PA_3DSetSpriteY(22+3*j+i,256);
				}
			}
		}
	}*/
	
	while (!ok) {
		if (rot == 16) {
			AS_SoundDefaultPlay((void*)retournerCarte,40576,127,64,0,0);
		}
		if (rot < 128) {
			zoom += 0.03;
		}
		else if (rot == 128) {
			for (i=0;i<10;i++) {
				if (sens[i] != -1) {
					loadCarte3D(false,i,0,couleur,10,0,0);
				}
			}
		}
		else if (rot == 384) {
			for (i=0;i<10;i++) {
				if (sens[i] != -1) {
					loadCarte3D(false,i,0,couleur,idCarteInit[i],0,0);
				}
			}
		}
		else if ((rot > 384) && (rot < 512)) {
			zoom -= 0.03;
		}
		else if (rot == 512) {
			for (i=0;i<3;i++) {
				for (j=0;j<3;j++) {
					if (sens[idCarte[i+1][j+1]] != -1) {
						PA_3DSetSpritePrio(idCarte[i+1][j+1],1024);
						if (bonusCase[i+1][j+1] != 0) {
							PA_3DSetSpriteY(22+3*j+i,39+j*50);
						}
					}
				}
			}
			rot = 0;
			zoom = 1;
			//AS_SoundDefaultPlay((void*)bruitCarte,8576,127,64,0,0);
			ok = true;
		}
		for (i=0;i<10;i++) {
			if (sens[i] == 0) {
				PA_3DSetSpriteRotateY(i,rot);
				PA_3DSetSpriteZoomXY(i,zoom,zoom);
			}
			else if (sens[i] == 1) {
				PA_3DSetSpriteRotateX(i,rot);
				PA_3DSetSpriteZoomXY(i,zoom,zoom);
			}
		}
		rot += 16;
		PA_CheckLid();
		PA_3DProcess();
		PA_WaitForVBL();
	}
}

void deplacementCarte(int numero,int zoneX,int zoneY) {

	// Déplacement de la carte vers le haut
	int i;
	int carteJoueur = numero/5;
	int numeroCarte = numero%5;
	int carte = mainJoueur1[carteJoueur][numeroCarte];
	int vitesse = 0;
	int yActuel = 40+25*numeroCarte;
	int yFinal = 39+50*zoneY;
	int distanceArret = 0;
	
	for (i=1;i<=vitesseAfficherCarte;i++) {
		distanceArret += i;
	}
	
	AS_SoundDefaultPlay((void*)bruitCarte,8576,127,64,0,0);
	
	while (yActuel > -50) {
		if (vitesse < vitesseAfficherCarte) {
			vitesse++;
		}
		yActuel -= vitesse;
		PA_3DSetSpriteY(numero,yActuel);
		PA_CheckLid();
		PA_3DProcess();
		PA_WaitForVBL();
	}

	vitesse = vitesseAfficherCarte;
	PA_3DSetSpriteX(numero,78+50*zoneX);
	PA_3DSetSpritePrio(numero,1999);
	loadCarte3D(false,numero,0,carteJoueur,idCarteInit[numero],0,0);	// On recharge la carte au cas où la règle Open n'est pas valable
	
	while (yActuel < yFinal) {
		if (((yActuel+distanceArret) > yFinal) && (vitesse > 1)) {
			vitesse--;
		}
		yActuel += vitesse;
		if (yActuel > yFinal) {
			yActuel = yFinal;
		}
		PA_3DSetSpriteY(numero,yActuel);
		PA_CheckLid();
		PA_3DProcess();
		PA_WaitForVBL();
	}
	//AS_SoundDefaultPlay((void*)bruitCarte,8576,127,64,0,0);
	PA_3DSetSpritePrio(numero,1024);
	
	plateau[zoneX+1][zoneY+1] = carte;
	plateauJoueur[zoneX+1][zoneY+1] = carteJoueur;
	if (elementPlateau[zoneX+1][zoneY+1] > 0) {
		// Supression du sprite de l'élément
		PA_3DSpriteAnimPause(12+3*zoneY+zoneX,1);
		PA_3DDeleteSprite(12+3*zoneY+zoneX);
		
		// Affichage du bonus
		PA_3DCreateSpriteFromTex(22+3*zoneY+zoneX,bonus_gfx[3*zoneY+zoneX],32,32,11,78+50*zoneX,39+50*zoneY);
		PA_3DSetSpritePrio(22+3*zoneY+zoneX,1998);
		
		if (elementPlateau[zoneX+1][zoneY+1] == elementCarte[carte]) {	// Le bon élément !
			bonusCase[zoneX+1][zoneY+1] = 1;
			PA_3DSetSpriteFrame(22+3*zoneY+zoneX,1);
		}
		else {
			bonusCase[zoneX+1][zoneY+1] = -1;
			PA_3DSetSpriteFrame(22+3*zoneY+zoneX,0);
		}
	}
}

bool initEcrireNom() {
	int i,j;
	int positionCurseur1 = 0;
	int positionCurseur2 = 1;
	bool ok=false;
	bool retour=false;
	bool inZone=false;
	u16 couleur[3] = {PA_RGB(0,0,0),PA_RGB(31,31,31),PA_RGB(16,16,16)};
	
	PA_LoadPal16(PAL_BG0,0,(void*)text_Pal);
	
	loadBg(0,"backEcrireNom",true);
	
	PA_Draw16bitRect(0,32,32,128,80,couleur[1]);
	/*for (i=16;i<=144;i++) {
		for (j=16;j<=96;j++) {
			PA_16cPutPixel(0,i,j,6);
		}
	}
	
	PA_16cClearZone(0,32,32,128,79);*/
	
	if (chargerBitmap()) {
		for (i=0;i<48;i++) {
			for (j=0;j<96;j++) {
				if (bitmap[i][j] == '1') {
					PA_Put16bitPixel(0,32+j,32+i,couleur[2]);
				}
			}
		}
	}
	
	PA_SetDrawSize(0,positionCurseur2+1);
	
	PA_LoadSpritePal(0,4,(void*)crayonGomme_Pal);
	PA_CreateSprite(0,4,(void*)crayonGomme_Sprite,OBJ_SIZE_32X64,1,4,0,32);
	PA_SetSpriteAnim(0,4,0);
	
	PA_LoadPal16(PAL_SPRITE0,0,(void*)curseur_Pal);
	PA_CreateSprite(0,0,(void*)curseur_Sprite,OBJ_SIZE_32X16,0,0,256,256);

	fadeBlack(1,true,true,false,1);
	
	while (1) {
		if (((Pad.Newpress.Down || (Stylus.Released && PA_StylusInZone(5,57,27,79))) && (positionCurseur1 == 0)) || ((Pad.Newpress.Up || (Stylus.Released && PA_StylusInZone(5,33,27,55))) && (positionCurseur1 == 1))) {
			AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
			positionCurseur1 = 1-positionCurseur1;
			PA_SetSpriteAnim(0,4,positionCurseur1);
		}
		if ((Pad.Newpress.A) || (Stylus.Released && PA_StylusInZone(160,60,224,80))) {
			for (i=0;i<48;i++) {
				for (j=0;j<96;j++) {
					if (PA_Get16bitPixel(0,32+j,32+i) != couleur[1]) {
						ok = true;
						break;
					}
				}
				if (ok) {
					break;
				}
			}
			if (ok) {
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				retour = true;
				break;
			}
			else {
				AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
			}
		}
		else if ((Pad.Newpress.X) || (Stylus.Released && PA_StylusInZone(160,32,224,52))) {
			PA_Draw16bitRect(0,32,32,128,80,couleur[1]);
		}
		else if (Pad.Newpress.B) {
			AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
			if (afficherFenetre(1,message[lang][18])) {
				retour = false;
				break;
			}
		}
		if (!PA_StylusInZone(16,16,144,96)) {
			inZone = false;
		}
		if (PA_StylusInZone(32,32,128,80)) {
			inZone = true;
		}
		if (inZone) {
			PA_16bitDraw(0,couleur[positionCurseur1]);
		}
		
		PA_Draw16bitRect(0,16,16,128,32,couleur[0]);
		PA_Draw16bitRect(0,128,16,145,80,couleur[0]);
		PA_Draw16bitRect(0,16,32,32,97,couleur[0]);
		PA_Draw16bitRect(0,32,80,147,97,couleur[0]);
		
		PA_WaitForVBL();
	}
	
	for (i=0;i<48;i++) {
		for (j=0;j<96;j++) {
			bitmap[i][j] = (PA_Get16bitPixel(0,32+j,32+i) == couleur[1]) ? '0' : '1';
		}
	}
	
	fadeBlack(1,true,true,false,0);
	
	return retour;
}

void afficherNomWifi(int id) {
	int i,j;
	PA_16cClearZone(0,36,24,132,72);
	for (i=0;i<48;i++) {
		for (j=0;j<96;j++) {
			if (bitmapWifi[id][i][j] == '1') {
				PA_16cPutPixel(0,36+j,24+i,6);
			}
		}
	}
}

bool initAttenteChoixPersoWifi() {

	int i;
	int oldPersoAdvWifi=persoAdvWifi;
	int nbFrame=0;
	bool effacementPerso=false;
	bool affichagePerso=false;

	while (1) {
		// Affichage du perso de l'adversaire
		if ((persoAdvWifi == 15) && !effacementPerso && !affichagePerso) {
			persoAdvWifi = oldPersoAdvWifi;
			return true;
		}
		else {
			if ((persoAdvWifi != oldPersoAdvWifi) && (persoAdvWifi < 15)) {
				effacementPerso=true;
			}
			oldPersoAdvWifi = persoAdvWifi;
			
			if (effacementPerso) {
				if (nbFrame <= (128/vitessePerso)) {
					for (i=0;i<4;i++) {
						PA_SetSpriteX(1,i,PA_GetSpriteX(1,i)-vitessePerso);
					}
					nbFrame++;
				}
				else {
					if (persoAdvWifi != choixPersoWifi) {
						for (i=0;i<4;i++) {
							PA_DeleteSprite(1,i);
						}
						PA_LoadSpritePal(1,0,(void*)perso_Pal[persoAdvWifi]);
						PA_CreateSprite(1,0,(void*)perso_Sprite[persoAdvWifi][0],OBJ_SIZE_32X64,1,0,-32,64);
						PA_CreateSprite(1,1,(void*)perso_Sprite[persoAdvWifi][1],OBJ_SIZE_64X64,1,0,-96,64);
						PA_CreateSprite(1,2,(void*)perso_Sprite[persoAdvWifi][2],OBJ_SIZE_32X64,1,0,-32,128);
						PA_CreateSprite(1,3,(void*)perso_Sprite[persoAdvWifi][3],OBJ_SIZE_64X64,1,0,-96,128);
						PA_SetSpriteHflip(1,0,1);
						PA_SetSpriteHflip(1,1,1);
						PA_SetSpriteHflip(1,2,1);
						PA_SetSpriteHflip(1,3,1);
						affichagePerso = true;
						nbFrame=0;
					}
					effacementPerso = false;
				}
			}
			if (affichagePerso) {
				for (i=0;i<4;i++) {
					PA_SetSpriteX(1,i,PA_GetSpriteX(1,i)+vitessePerso);
				}
				if (PA_GetSpriteX(1,1) == 0) {
					affichagePerso = false;
				}
			}
			if (Pad.Newpress.B) {
				if (afficherFenetre3D(1,message[lang][19])) {
					return false;
				}
				PA_3DSetSpriteX(10,384);
				afficherNomWifi(0);
				effacementPerso=true;
			}
			
			PA_3DProcess();
			PA_WaitForVBL();
		}
	}
	return false;
}

bool initChoixPersoWifi(bool changerPerso,bool envoyerPerso,u16 fenetre_gfx) {

	int i=0;
	int x;
	int positionCurseur = (persoAdvWifi == choixPersoWifi) ? ((persoAdvWifi == 0) ? 1 : 0) : choixPersoWifi%11;
	int page = (persoAdvWifi == choixPersoWifi) ? 0 : choixPersoWifi/11;
	int timer=0;
	int afficherPageSuivante;
	int ajoutPage;
	int nbFrame=0;
	int choixAdversaire;
	int couleur;
	int cheat=0;
	char affichage[16];
	bool multipage=false;
	bool effacementPerso=false;
	bool affichagePerso=changerPerso;
	bool selection=false;
	bool retour = false;
	
	PA_3DSetSpriteXY(10,58,37+12*positionCurseur);
	
	PA_16cErase(0);
	afficherStatus(1,message[lang][20]);
	
	choixAdversaire = positionCurseur+11*page;
	if (changerPerso) {
		PA_LoadSpritePal(1,1,(void*)perso_Pal[choixAdversaire]);
		PA_CreateSprite(1,5,(void*)perso_Sprite[choixAdversaire][0],OBJ_SIZE_32X64,1,1,256,64);
		PA_CreateSprite(1,6,(void*)perso_Sprite[choixAdversaire][1],OBJ_SIZE_64X64,1,1,288,64);
		PA_CreateSprite(1,7,(void*)perso_Sprite[choixAdversaire][2],OBJ_SIZE_32X64,1,1,256,128);
		PA_CreateSprite(1,8,(void*)perso_Sprite[choixAdversaire][3],OBJ_SIZE_64X64,1,1,288,128);
	}
	
	if (persoDebloque > 10) {	// Affichage des flèches et utilisation du mode multipage
		PA_Load3DSpritePal(13, (void*)flecheMenu_Pal);
		PA_3DCreateSprite(13,(void*)flecheMenu_Texture,8,8,TEX_4COL,13,69,161);
		PA_3DCreateSprite(14,(void*)flecheMenu_Texture,8,8,TEX_4COL,13,186,161);
		PA_3DStartSpriteAnim(13,0,1,6);
		PA_3DStartSpriteAnim(14,2,3,6);
		PA_3DSetSpritePrio(13,2044);
		PA_3DSetSpritePrio(14,2045);
		multipage = true;
	}
	
	// Affichage de la première page
	majListePersoWifi(page,persoAdvWifi);
	
	if (envoyerPerso) {
		envoiWifi(false,0x0003,"",positionCurseur+11*page);
	}
	
	while (1) {
		
		// Cheat !
		if (Pad.Newpress.A || Pad.Newpress.B || Pad.Newpress.X || Pad.Newpress.L || Pad.Newpress.Up || Pad.Newpress.Down || Pad.Newpress.Start || Stylus.Newpress) {
			cheat = 0;
		}
		if (Pad.Newpress.Y) {
			if ((cheat == 0) || (cheat == 3)) {
				cheat++;
			}
			else {
				cheat = 0;
			}
		}
		if (Pad.Newpress.Left) {
			if (cheat == 1) {
				cheat++;
			}
			else {
				cheat = 0;
			}
		}
		if (Pad.Newpress.R) {
			if (cheat == 2) {
				cheat++;
			}
			else {
				cheat = 0;
			}
		}
		if (Pad.Newpress.Right) {
			if (cheat == 4) {
				cheat++;
			}
			else {
				cheat = 0;
			}
		}
		if (Pad.Newpress.Select) {
			if (cheat == 5) {
				if (persoAdvWifi == 14) {
					AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
				}
				else {
					AS_SoundDefaultPlay((void*)nouvelleCarte,60672,127,64,0,0);
					choixPersoWifi = 14;
					effacementPerso=false;
					affichagePerso=false;
					
					for (nbFrame=0;nbFrame<=(128/vitessePerso);nbFrame++) {
						for (i=1;i<5;i++) {
							PA_SetSpriteX(1,i+4,PA_GetSpriteX(1,i+4)+vitessePerso);
						}
						
						PA_3DProcess();
						PA_WaitForVBL();
					}
					for (i=1;i<5;i++) {
						PA_DeleteSprite(1,i+4);
					}
					PA_LoadSpritePal(1,1,(void*)perso_Pal[14]);
					PA_CreateSprite(1,5,(void*)perso_Sprite[14][0],OBJ_SIZE_32X64,1,1,256,64);
					PA_CreateSprite(1,6,(void*)perso_Sprite[14][1],OBJ_SIZE_64X64,1,1,288,64);
					PA_CreateSprite(1,7,(void*)perso_Sprite[14][2],OBJ_SIZE_32X64,1,1,256,128);
					PA_CreateSprite(1,8,(void*)perso_Sprite[14][3],OBJ_SIZE_64X64,1,1,288,128);
					
					while (PA_GetSpriteX(1,6) != 192) {
						for (i=1;i<5;i++) {
							PA_SetSpriteX(1,i+4,PA_GetSpriteX(1,i+4)-vitessePerso);
						}
						
						PA_3DProcess();
						PA_WaitForVBL();
					}
					
					retour = true;
					break;
				}
			}
			else {
				cheat = 0;
			}
		}
		if (effacementPerso) {
			if (nbFrame <= (128/vitessePerso)) {
				for (i=1;i<5;i++) {
					PA_SetSpriteX(1,i+4,PA_GetSpriteX(1,i+4)+vitessePerso);
				}
				nbFrame++;
			}
			else {
				choixAdversaire = positionCurseur+11*page;
				if (choixAdversaire != persoAdvWifi) {
					for (i=1;i<5;i++) {
						PA_DeleteSprite(1,i+4);
					}
					PA_LoadSpritePal(1,1,(void*)perso_Pal[choixAdversaire]);
					PA_CreateSprite(1,5,(void*)perso_Sprite[choixAdversaire][0],OBJ_SIZE_32X64,1,1,256,64);
					PA_CreateSprite(1,6,(void*)perso_Sprite[choixAdversaire][1],OBJ_SIZE_64X64,1,1,288,64);
					PA_CreateSprite(1,7,(void*)perso_Sprite[choixAdversaire][2],OBJ_SIZE_32X64,1,1,256,128);
					PA_CreateSprite(1,8,(void*)perso_Sprite[choixAdversaire][3],OBJ_SIZE_64X64,1,1,288,128);
					affichagePerso = true;
					nbFrame=0;
				}
				effacementPerso = false;
			}
		}
		if (affichagePerso) {
			for (i=1;i<5;i++) {
				PA_SetSpriteX(1,i+4,PA_GetSpriteX(1,i+4)-vitessePerso);
			}
			if (PA_GetSpriteX(1,6) == 192) {
				affichagePerso = false;
			}
		}
		if (Pad.Newpress.Down || Pad.Newpress.Up) {
			positionCurseur += Pad.Newpress.Down - Pad.Newpress.Up;
			if (positionCurseur == -1) {
				positionCurseur = (page == multipage) ? persoDebloque%11 : 10;
			}
			else if ((positionCurseur == 11) || ((page == multipage) && (positionCurseur == ((persoDebloque%11)+1)))) {
				positionCurseur = 0;
			}
			PA_3DSetSpriteY(10,37+12*positionCurseur);
			AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
			
			if (envoyerPerso) {
				envoiWifi(false,0x0003,"",positionCurseur+11*page);
			}
			
			timer = 0;
			effacementPerso = true;
		}
		if (Pad.Held.Down || Pad.Held.Up) {
			if (timer == timerCurseur1) {
				positionCurseur += Pad.Held.Down - Pad.Held.Up;
				if (positionCurseur == -1) {
					positionCurseur = (page == multipage) ? persoDebloque%11 : 10;
				}
				else if ((positionCurseur == 11) || ((page == multipage) && (positionCurseur == ((persoDebloque%11)+1)))) {
					positionCurseur = 0;
				}
				PA_3DSetSpriteY(10,37+12*positionCurseur);
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				
				timer -= timerCurseur2;
				effacementPerso = true;
				
				if (envoyerPerso) {
					envoiWifi(false,0x0003,"",positionCurseur+11*page);
				}
			}
			else {
				timer++;
			}
		}
		else if (multipage) {
			if ((Pad.Newpress.R || Pad.Held.Right) || (Pad.Newpress.L || Pad.Held.Left)) {
				ajoutPage = (Pad.Newpress.R || Pad.Held.Right) - (Pad.Newpress.L || Pad.Held.Left);
				page = !page;
				if (page == multipage) {
					if (positionCurseur > (persoDebloque%11)) {
						positionCurseur = persoDebloque%11;
						PA_3DSetSpriteY(10,37+12*positionCurseur);
					}
				}
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				
				if (envoyerPerso) {
					envoiWifi(false,0x0003,"",positionCurseur+11*page);
				}
					
				afficherPageSuivante = ajoutPage;
				effacementPerso = true;
			}
		}
		if (Pad.Newpress.A || selection) {
			if (effacementPerso || affichagePerso) {
				selection = true;
			}
			else {
				selection = false;
				choixAdversaire = positionCurseur+11*page;
				// Si le perso est débloquer...
				if (choixAdversaire != persoAdvWifi) {
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					sprintf(affichage,"%s\n%s ?",message[lang][21],nomAdv[lang][choixAdversaire]);
					if (afficherFenetre3D(1,affichage)) {
						choixPersoWifi = positionCurseur+11*page;
						retour = true;
						break;
					}
					majListePersoWifi(page,persoAdvWifi);
					PA_3DSetSpriteXY(10,58,37+12*positionCurseur);
				}
				else {
					AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
				}
			}
		}
		else if (Pad.Newpress.B && (wifiOn == 0)) {
			AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
			if (afficherFenetre3D(1,message[lang][22])) {
				retour = false;
				break;
			}
			majListePersoWifi(page,persoAdvWifi);
			PA_3DSetSpriteXY(10,58,37+12*positionCurseur);
		}
		if (Stylus.Newpress || Stylus.Held) {
			for (i=0;i<11;i++) {
				if (PA_StylusInZone(68,28+12*i,182,40+12*i) && ((page != multipage) || ((page == multipage) && (i <= persoDebloque%11))) && (positionCurseur != i)) {
					positionCurseur = i;
					PA_3DSetSpriteY(10,37+12*positionCurseur);
					
					if (envoyerPerso) {
						envoiWifi(false,0x0003,"",positionCurseur+11*page);
					}
					
					effacementPerso = true;
					break;
				}
			}
			if (multipage) {
				if (PA_StylusInZone(64,160,69,167)) {
					page = !page;
					if (positionCurseur > (persoDebloque%11)) {
						positionCurseur = persoDebloque%11;
						PA_3DSetSpriteY(10,37+12*positionCurseur);
					}
					
					if (envoyerPerso) {
						envoiWifi(false,0x0003,"",positionCurseur+11*page);
					}
					
					afficherPageSuivante = -1;
					effacementPerso = true;
				}
				else if (PA_StylusInZone(187,160,192,167)) {
					page = !page;
					if (positionCurseur > (persoDebloque%11)) {
						positionCurseur = persoDebloque%11;
						PA_3DSetSpriteY(10,37+12*positionCurseur);
					}
					
					if (envoyerPerso) {
						envoiWifi(false,0x0003,"",positionCurseur+11*page);
					}
					
					afficherPageSuivante = 1;
					effacementPerso = true;
				}
			}
		}
		if (Stylus.Released) {
			if ((PA_StylusInZone(68,28,182,160) && (page != multipage)) || (PA_StylusInZone(68,28,182,40+12*(persoDebloque%11)))) {
				if (effacementPerso || affichagePerso) {
					selection = true;
				}
				else {
					selection = false;
					choixAdversaire = positionCurseur+11*page;
					// Si le perso est débloquer...
					if (choixAdversaire != persoAdvWifi) {
						AS_SoundDefaultPlay((void*)choix_raw,15984,127,64,0,0);
						sprintf(affichage,"%s\n%s ?",message[lang][21],nomAdv[lang][choixAdversaire]);
						if (afficherFenetre3D(1,affichage)) {
							choixPersoWifi = positionCurseur+11*page;
							retour = true;
							break;
						}
						majListePersoWifi(page,persoAdvWifi);
						PA_3DSetSpriteXY(10,58,37+12*positionCurseur);
					}
					else {
						AS_SoundDefaultPlay((void*)erreur_raw,43404,127,64,0,0);
					}
				}
			}
		}
		if (afficherPageSuivante != 0) {
			x=0;
			PA_3DCreateSpriteFromTex(19,fenetre_gfx,128,156,17,128,100);
			PA_3DSetSpritePrio(19,2042);
			if (afficherPageSuivante == 1) {	// Page suivante
				PA_3DSetSpriteTopRight(19,-1,0);
				PA_3DSetSpriteBottomRight(19,-1,0);
				PA_3DSetSpriteTopLeft(19,128,0);
				PA_3DSetSpriteBottomLeft(19,128,0);
				while (x < 128) {
					x += ((128-x)/2)+1;
					if (x > 128) {
						x = 128;
					}
					PA_3DSetSpriteTopLeft(19,128-x,0);
					PA_3DSetSpriteBottomLeft(19,128-x,0);
					PA_16cClearZone(0,192-x,0,256,174);
					
					// On affiche la page suivante...
					for (i=0;i<11;i++) {
						if (i+11*page <= persoDebloque) {
							sprintf(affichage,"%s",nomAdv[lang][i+11*page]);
							couleur = (persoAdvWifi == i+11*page) ? 3 : 1;
							PA_16cText(0,198-x,28+12*i,312-x,172,affichage,couleur,5,16);
						}
					}
					// Qu'on coupe pour pas qu'elle dépasse :)
					PA_16cClearZone(0,191,0,256,174);
					
					PA_3DProcess();
					PA_WaitForVBL();
				}
			}
			else {		// Page précédente
				PA_3DSetSpriteTopRight(19,-127,0);
				PA_3DSetSpriteBottomRight(19,-127,0);
				while (x < 128) {
					x += ((128-x)/2)+1;
					if (x > 128) {
						x = 128;
					}
					PA_3DSetSpriteTopRight(19,x-129,0);
					PA_3DSetSpriteBottomRight(19,x-129,0);
					
					PA_16cClearZone(0,0,0,64+x,174);
					
					// On affiche la page suivante...
					for (i=0;i<11;i++) {
						if (i+11*page <= persoDebloque) {
							sprintf(affichage,"%s",nomAdv[lang][i+11*page]);
							couleur = (persoAdvWifi == i+11*page) ? 3 : 1;
							PA_16cText(0,x-58,28+12*i,56+x,172,affichage,couleur,5,16);
						}
					}
					// Qu'on coupe pour pas qu'elle dépasse :)
					PA_16cClearZone(0,0,0,65,174);
					
					PA_3DProcess();
					PA_WaitForVBL();
				}
			}
			
			PA_3DDeleteSprite(19);
			afficherPageSuivante = 0;
			PA_WaitForVBL();
		}
		
		PA_3DProcess();
		PA_WaitForVBL();
	}
	
	if (envoyerPerso && retour) {
		envoiWifi(true,0x0003,"",choixPersoWifi);
		PA_3DProcess();
		PA_WaitForVBL();PA_WaitForVBL();PA_WaitForVBL();PA_WaitForVBL();PA_WaitForVBL();PA_WaitForVBL();
		envoiWifi(true,0x0003,"",15);
	}
	
	if (choixPersoWifi == 14) {
		choixPersoWifi = 0;
		sauvegarder();
		choixPersoWifi = 14;
	}
	else {
		sauvegarder();
	}
	
	if (multipage) {
		PA_3DDeleteSprite(13);
		PA_3DDeleteSprite(14);
		PA_3DSpriteAnimPause(13,1);
		PA_3DSpriteAnimPause(14,1);
		PA_3DSetSpriteFrame(13,0);
		PA_3DSetSpriteFrame(14,0);
	}
	
	return retour;
}

bool initChoixReglesWifi(bool envoyerRegles) {

	int i=0;
	int timer=0;
	int ajoutPosition=0;
	int positionCurseur=0;
	bool retour=false;
	
	PA_3DSetSpriteXY(10,58,37+12*positionCurseur);
	
	PA_16cErase(0);
	afficherStatus(1,message[lang][23]);
	
	PA_16cTextAlign(ALIGN_LEFT);
	PA_16cText(1,8,2,256,192,message[lang][24],1,2,8);
	majRegles(reglePerso);
	majListeReglesWifi();
	
	while (1) {
		if (Pad.Newpress.Down || Pad.Newpress.Up) {
			ajoutPosition = Pad.Newpress.Down - Pad.Newpress.Up;
			do {
				positionCurseur += ajoutPosition;
			}
			while (positionCurseur == 8);
			if (positionCurseur == -1) {
				positionCurseur = 9;
			}
			else if (positionCurseur == 10) {
				positionCurseur = 0;
			}
			
			PA_3DSetSpriteXY(10,58+41*(positionCurseur/9),37+12*positionCurseur);
			AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
			
			timer = 0;
		}
		else if (Pad.Held.Down || Pad.Held.Up) {
			if (timer == timerCurseur1) {
				ajoutPosition = Pad.Held.Down - Pad.Held.Up;
				do {
					positionCurseur += ajoutPosition;
				}
				while (positionCurseur == 8);
				if (positionCurseur == -1) {
					positionCurseur = 9;
				}
				else if (positionCurseur == 10) {
					positionCurseur = 0;
				}
				
				PA_3DSetSpriteXY(10,58+41*(positionCurseur/9),37+12*positionCurseur);
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				
				timer -= timerCurseur2;
			}
			else {
				timer++;
			}
		}
		else if (Pad.Newpress.A) {
			if (((positionCurseur == 5) || (positionCurseur == 6)) && (!reglePerso[3] && !reglePerso[4])) {
				AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
			}
			else {
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				if (positionCurseur == 9) {		// Valider
					if (afficherFenetre3D(1,message[lang][25])) {
						if (envoyerRegles) {
							for (i=0;i<8;i++) {
								regleWifi[i] = reglePerso[i];
							}
						}
						retour = true;
						break;
					}
					PA_3DSetSpriteXY(10,58+41*(positionCurseur/9),37+12*positionCurseur);
				}
				else {
					reglePerso[positionCurseur] = !reglePerso[positionCurseur];
					if (!reglePerso[3] && !reglePerso[4]) {
						reglePerso[5] = false;
						reglePerso[6] = false;
					}
					majRegles(reglePerso);
					if (envoyerRegles) {
						char envoi[8];
						sprintf(envoi,"%01d%01d%01d%01d%01d%01d%01d%01d",reglePerso[0],reglePerso[1],reglePerso[2],reglePerso[3],reglePerso[4],reglePerso[5],reglePerso[6],reglePerso[7]);
						envoiWifi(false,0x0010,envoi,8);
					}
				}
				majListeReglesWifi();
			}
		}
		else if (Pad.Newpress.B) {
			AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
			if (afficherFenetre3D(1,message[lang][22])) {
				if (envoyerRegles) {
					for (i=0;i<8;i++) {
						reglePerso[i] = regleWifi[i];
					}
					majRegles(reglePerso);
					char envoi[8];
					sprintf(envoi,"%01d%01d%01d%01d%01d%01d%01d%01d",reglePerso[0],reglePerso[1],reglePerso[2],reglePerso[3],reglePerso[4],reglePerso[5],reglePerso[6],reglePerso[7]);
					envoiWifi(false,0x0010,envoi,8);
				}
				else {
					PA_16cErase(1);
					if (choixPersoWifi == 14) {
						choixPersoWifi = 0;
					}
				}
				retour = false;
				break;
			}
			PA_3DSetSpriteXY(10,58+41*(positionCurseur/9),37+12*positionCurseur);
			majListeReglesWifi();
		}
		else if (Pad.Newpress.Start) {
			AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
			if (afficherFenetre3D(1,message[lang][25])) {
				if (envoyerRegles) {
					for (i=0;i<8;i++) {
						regleWifi[i] = reglePerso[i];
					}
				}
				retour = true;
				break;
			}
			PA_3DSetSpriteXY(10,58+41*(positionCurseur/9),37+12*positionCurseur);
		}
		if (Stylus.Newpress || Stylus.Held) {
			for (i=0;i<10;i++) {
				if (PA_StylusInZone(68,28+12*i,182,40+12*i) && (i != 8)) {
					positionCurseur = i;
					PA_3DSetSpriteXY(10,58+41*(positionCurseur/9),37+12*positionCurseur);
					break;
				}
			}
		}
		else if (Stylus.Released && (PA_StylusInZone(68,28,182,124) || PA_StylusInZone(68,136,182,148))) {
			if (((positionCurseur == 5) || (positionCurseur == 6)) && (!reglePerso[3] && !reglePerso[4])) {
				AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
			}
			else {
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				if (positionCurseur == 9) {		// Valider
					if (afficherFenetre3D(1,message[lang][25])) {
						if (envoyerRegles) {
							for (i=0;i<8;i++) {
								regleWifi[i] = reglePerso[i];
							}
						}
						retour = true;
						break;
					}
					PA_3DSetSpriteXY(10,58+41*(positionCurseur/9),37+12*positionCurseur);
				}
				else {
					reglePerso[positionCurseur] = !reglePerso[positionCurseur];
					if (!reglePerso[3] && !reglePerso[4]) {
						reglePerso[5] = false;
						reglePerso[6] = false;
					}
					majRegles(reglePerso);
					if (envoyerRegles) {
						char envoi[8];
						sprintf(envoi,"%01d%01d%01d%01d%01d%01d%01d%01d",reglePerso[0],reglePerso[1],reglePerso[2],reglePerso[3],reglePerso[4],reglePerso[5],reglePerso[6],reglePerso[7]);
						envoiWifi(false,0x0010,envoi,8);
					}
				}
				majListeReglesWifi();
			}
		}
		
		PA_3DProcess();
		PA_WaitForVBL();
	}

	if (choixPersoWifi == 14) {
		choixPersoWifi = 0;
		sauvegarder();
		choixPersoWifi = 14;
	}
	else {
		sauvegarder();
	}
	
	return retour;
}

void initElements() {
	
	int i,j;
	// Pour chacune des cases, on choisi un élément
	for (i=0;i<3;i++) {
		for (j=0;j<3;j++) {
			// Une chance d'avoir un élement sur cette case
			if (PA_RandMinMax(1,chanceElementCase) == 1) {
				// Choix aléatoire de l'élément pour cette case...
				elementPlateau[j+1][i+1] = PA_RandMax(7)+1;
				//elementPlateau[i+1][j+1] = 3*i+j;
				element_gfx[3*i+j] = PA_3DCreateTex(element_Texture[elementPlateau[j+1][i+1]],16,16,TEX_256COL);
				bonus_gfx[3*i+j] = PA_3DCreateTex((void*)bonusCarte_Texture,32,32,TEX_4COL);
				PA_3DCreateSpriteFromTex(12+3*i+j,element_gfx[3*i+j],16,16,12,78+50*j,39+50*i);
				PA_3DSetSpritePrio(12+3*i+j,524+3*i+j);
				PA_3DStartSpriteAnim(12+3*i+j,0,3,16);
				PA_3DSetSpriteAlpha(12+3*i+j,7);
				PA_3DSetSpritePolyID(12+3*i+j,12+3*i+j);
			}
			else {
				elementPlateau[j+1][i+1] = 0;
			}
		}
	}
	
	if (wifiOn == 1) {
		char elementEnvoi[10];
		sprintf(elementEnvoi,"%01d%01d%01d%01d%01d%01d%01d%01d%01d",elementPlateau[1][1],elementPlateau[2][1],elementPlateau[3][1],elementPlateau[1][2],elementPlateau[2][2],elementPlateau[3][2],elementPlateau[1][3],elementPlateau[2][3],elementPlateau[3][3]);
		envoiWifi(true,0x0010,elementEnvoi,9);
	}
}

void majHistorique() {
	int i;
	for (i=1;i<=110;i++) {
		if (collection[i] > 0) {
			historique[i] = true;
		}
	}
}

void echangerCartes(int adversaire) {

	int i;
	for (i=0;i<5;i++) {
		if (cartePrise[0][i]) {		// On gagne...
			if (collection[mainJoueur2[0][i]] < 100) {
				collection[mainJoueur2[0][i]]++;
				if (mainJoueur2[0][i] > 77) {
					cartesRares[adversaire][mainJoueur2[0][i]-78] = 0;
				}
			}
		}
		if (cartePrise[1][i]) {		// On perd...
			collection[mainJoueur2[1][i]]--;
			if (mainJoueur2[1][i] > 77) {
				cartesRares[adversaire][mainJoueur2[1][i]-78] = 1;
			}
		}
	}
}

void initEchangeCarte(int adversaire) {

	int i,j,k;
	int joueur,carte;
	int nombre;
	int retourne[10];
	bool brille[3][3];
	char affichage[19];
	char affichageConfirm[24];
	
	for (i=0;i<3;i++) {
		for (j=0;j<3;j++) {
			brille[i][j] = false;
		}
	}
	
	/*// On supprime tout ce qu'il faut (et pas plus)
	PA_3DSpriteAnimPause(11,1);
	PA_3DSetSpriteFrame(11,0);
	PA_3DDeleteSprite(11);
	if (regleAdv[adversaire][7]) {	// Elementaire
		PA_3DDeleteSprite(21);
		for (i=0;i<3;i++) {
			for (j=0;j<3;j++) {
				if (elementPlateau[j+1][i+1] > 0) {
					//PA_3DDeleteSprite(22+3*i+j);
				}
			}
		}
	}
	PA_3DDeleteSprite(31);*/
	
	
	PA_Reset3DSprites();
	for (i=0;i<10;i++) {
		joueur = i/5;
		carte = i%5;
		//loadCarteMem(i,0,joueur,mainJoueur2[joueur][carte]);
		loadCarte3D(true,i,0,joueur,i,28+50*carte,63+68*joueur);
		PA_3DSetSpritePrio(i,1024);
		idCarteInit[i] = i;
	}
	
	u16 curseur_gfx = PA_3DCreateTex((void*)curseur3D_Texture, 32, 16, TEX_16COL);
	PA_Load3DSpritePal(10, (void*)curseur3D_Pal);
	PA_3DCreateSpriteFromTex(10,curseur_gfx,20,12,10,266,198);
	PA_3DSetSpritePrio(10,2048);
	

	// On affiche tout
	loadBg(0,"backFinPartie",false);
	
	/*for (i=0;i<5;i++) {
		for (j=0;j<2;j++) {
			loadCarte3D(false,5*j+i,0,j,5*j+i,0,0);
			PA_3DSetSpriteXY(5*j+i,28+50*i,63+68*j);
			//idCarteInit[5*j+i] = 5*j+i;
		}
	}*/
	
	PA_3DProcess();
	
	loadCarteMem(11,1,0,0);
	loadCarte3D(true,11,1,0,0,384,96);
	PA_3DSetSpritePrio(11,2002);
	
	fadeBlack(1,true,false,false,1);
	
	PA_16cTextAlign(ALIGN_CENTER);
	
	if ((scoreJoueur > 5) && ((regleAdv[adversaire][8] == 0) || ((regleAdv[adversaire][8] == 2) && (scoreJoueur < 8)))) {
		if (regleAdv[adversaire][8] == 0) {
			nombre = 1;
			sprintf(affichage,"%s 1 %s",message[lang][26],message[lang][29]);
			sprintf(affichageConfirm,"%s",message[lang][27]);
		}
		else {
			nombre = 2*scoreJoueur-10;		// On ne peut pas dépasser 5 (déjà vu ce cas avant d'arriver là)
			sprintf(affichage,"%s %d %s",message[lang][26],nombre,message[lang][30]);
			sprintf(affichageConfirm,"%s",message[lang][28]);
		}
		PA_16cTextAlign(ALIGN_CENTER);
		PA_16cText(0,0,14,256,32,affichage,1,5,64);
		PA_3DSetSpriteXY(10,19,64);
		
		majCarteG(0,mainJoueur2[0][0]);
		afficherNomCarte(mainJoueur2[0][0],-1,0);
		
		int positionCurseur=0;
		int timer=0;
		int id=0;
		int historiqueSelection[5];
		
		// Affichage de la fenetre de confirmation
		u16 fenetre3D_gfx = PA_3DCreateTex((void*)fenetre3D_Texture,128,64,TEX_256COL);
		PA_Load3DSpritePal(15, (void*)fenetre3D_Pal);
		PA_3DCreateSpriteFromTex(15,fenetre3D_gfx,128,64,15,128,288);
		PA_3DSetSpritePrio(15,2046);
		
		// Affichage du haut de page
		u16 haut3D_gfx = PA_3DCreateTex((void*)hautFenetre3D_Texture,128,8,TEX_4COL);
		PA_Load3DSpritePal(12, (void*)hautListeCarte_Pal);
		PA_3DCreateSpriteFromTex(16,haut3D_gfx,128,6,12,128,259);
		PA_3DSetSpritePrio(16,2047);
		PA_3DSetSpriteFrame(16,0);
		
		while (1) {
			if (Pad.Newpress.Right || Pad.Newpress.Left) {
				positionCurseur += Pad.Newpress.Right - Pad.Newpress.Left;
				if (positionCurseur == 5) {
					positionCurseur = 0;
				}
				else if (positionCurseur == -1) {
					positionCurseur = 4;
				}
				PA_3DSetSpriteX(10,19+50*positionCurseur);
				majCarteG(0,mainJoueur2[0][positionCurseur]);
				afficherNomCarte(mainJoueur2[0][positionCurseur],-1,0);
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				
				timer = 0;
			}
			else if (Pad.Held.Right || Pad.Held.Left) {
				if (timer == timerCurseur1) {
					positionCurseur += Pad.Held.Right - Pad.Held.Left;
					if (positionCurseur == 5) {
						positionCurseur = 0;
					}
					else if (positionCurseur == -1) {
						positionCurseur = 4;
					}
					PA_3DSetSpriteX(10,19+50*positionCurseur);
					majCarteG(0,mainJoueur2[0][positionCurseur]);
					afficherNomCarte(mainJoueur2[0][positionCurseur],-1,0);
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					timer -= timerCurseur2;
				}
				else {
					timer++;
				}
			}
			if (Pad.Newpress.A) {
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				if ((id < nombre) || cartePrise[0][positionCurseur]) {
					cartePrise[0][positionCurseur] = !cartePrise[0][positionCurseur];
					if (cartePrise[0][positionCurseur]) {
						historiqueSelection[id] = positionCurseur;
						id++;
					}
					else {
						id--;
					}
					for (i=0;i<10;i++) {
						retourne[i] = -1;
					}
					retourne[positionCurseur] = 0;
					PA_3DSetSpriteY(10,256);
					retournerCartes(retourne,cartePrise[0][positionCurseur],false,false,false,brille);
					majCarteG(cartePrise[0][positionCurseur],mainJoueur2[0][positionCurseur]);
				}
				if (id == nombre) {
					if (afficherFenetre3D(1,affichageConfirm)) {
						break;
					}
				}
				PA_3DSetSpriteXY(10,19+50*positionCurseur,64);
			}
			else if ((Pad.Newpress.B) && (id > 0)) {
				AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
				id--;
				cartePrise[0][historiqueSelection[id]] = false;
				for (i=0;i<10;i++) {
					retourne[i] = -1;
				}
				retourne[historiqueSelection[id]] = 0;
				PA_3DSetSpriteY(10,256);
				retournerCartes(retourne,0,false,false,false,brille);
				majCarteG(cartePrise[0][positionCurseur],mainJoueur2[0][positionCurseur]);
				PA_3DSetSpriteY(10,64);
			}
			if (Stylus.Newpress || Stylus.Held) {
				for (i=0;i<5;i++) {
					if (PA_StylusInZone(3+50*i,38,53+50*i,88)) {
						positionCurseur = i;
						PA_3DSetSpriteX(10,19+50*positionCurseur);
						majCarteG(0,mainJoueur2[0][positionCurseur]);
						afficherNomCarte(mainJoueur2[0][positionCurseur],-1,0);
					}
				}
			}
			if (Stylus.Released) {
				if (PA_StylusInZone(3,38,253,88)) {
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					if ((id < nombre) || cartePrise[0][positionCurseur]) {
						cartePrise[0][positionCurseur] = !cartePrise[0][positionCurseur];
						if (cartePrise[0][positionCurseur]) {
							historiqueSelection[id] = positionCurseur;
							id++;
						}
						else {
							id--;
						}
						for (i=0;i<10;i++) {
							retourne[i] = -1;
						}
						retourne[positionCurseur] = 0;
						PA_3DSetSpriteY(10,256);
						retournerCartes(retourne,cartePrise[0][positionCurseur],false,false,false,brille);
						majCarteG(cartePrise[0][positionCurseur],mainJoueur2[0][positionCurseur]);
					}
					if (id == nombre) {
						if (afficherFenetre3D(1,affichageConfirm)) {
							break;
						}
					}
					PA_3DSetSpriteXY(10,19+50*positionCurseur,64);
				}
			}
			
			PA_CheckLid();
			PA_3DProcess();
			PA_WaitForVBL();
		}
		echangerCartes(adversaire);
		sauvegarder();
		
		PA_3DDeleteSprite(10);
		PA_3DDeleteSprite(15);
		PA_3DDeleteSprite(16);
		
		majCarteG(0,0);
		PA_16cErase(0);
	}
	
	else {
		for (i=0;i<2;i++) {
			for (j=0;j<5;j++) {
				if (cartePrise[i][j]) {
					for (k=0;k<10;k++) {
						retourne[k] = -1;
					}
					retourne[5*i+j] = 0;
					retournerCartes(retourne,!i,false,false,false,brille);
				}
			}
		}
	}
	
	// On déplace les cartes et on affiche les pertes et les gains
	int vitesse;
	int xActuel;
	int sens;
	int distanceArret;
	char affichageCarteGagnee[64];
	bool skip = false;
	
	for (i=0;i<2;i++) {
		sens = -1+2*i;
		for (j=i*4;j!=5-6*i;j+=1-2*i) {
			if (cartePrise[i][j]) {
				PA_3DSetSpritePrio(5*i+j,1998);
				
				vitesse = 0;
				xActuel = 28+50*j;
				while ((xActuel > -50) && (xActuel < 306)) {		// Déplacement de la petite carte sur le côté
					if (vitesse < vitesseAfficherCarte) {
						vitesse++;
					}
					xActuel += vitesse*sens;
					PA_3DSetSpriteX(5*i+j,xActuel);
					PA_CheckLid();
					PA_3DProcess();
					PA_WaitForVBL();
				}
				
				// Chargement de la grande carte
				loadCarteMem(11,1,!i,mainJoueur2[i][j]);
				loadCarte3D(false,11,1,0,0,0,0);
				PA_3DSetSpriteX(11,-50);
				
				xActuel = 356*i-50;
				vitesse = vitesseAfficherCarte;
				distanceArret = 0;
				for (k=1;k<=vitesseAfficherCarte;k++) {
					distanceArret += k;
				}
				while (xActuel != 128) {	// Déplacement de la grande carte au milieu
					if (i) {
						if (((xActuel+distanceArret) < 128) && (vitesse > 1)) {
							vitesse--;
						}
						xActuel -= vitesse;
						if (xActuel < 128) {
							xActuel = 128;
						}
					}
					else {
						if (((xActuel-distanceArret) > 128) && (vitesse > 1)) {
							vitesse--;
						}
						xActuel += vitesse;
						if (xActuel > 128) {
							xActuel = 128;
						}
					}
					PA_3DSetSpriteX(11,xActuel);
					PA_CheckLid();
					PA_3DProcess();
					PA_WaitForVBL();
				}
				
				if (i) {
					sprintf(affichageCarteGagnee,"%s%s %s !",message[lang][68],nomCarte[lang][mainJoueur2[i][j]],message[lang][31]);
				}
				else {
					sprintf(affichageCarteGagnee,"%s%s %s !",message[lang][68],nomCarte[lang][mainJoueur2[i][j]],message[lang][32]);
				}
				
				PA_16cText(0,0,14,256,32,affichageCarteGagnee,1,5,64);
				afficherNomCarte(mainJoueur2[i][j],-1+2*i,1);
				PA_WaitFor(Pad.Held.A || Stylus.Held || skip || ((skip = Pad.Newpress.Start) && Pad.Newpress.Start));
				PA_16cErase(0);
				
				if ((i == 0) && !historique[mainJoueur2[i][j]]) {
					AS_SoundDefaultPlay((void*)nouvelleCarte,60672,127,64,0,0);
				}
				
				vitesse = 0;
				
				while ((xActuel > -50) && (xActuel < 306)) {	// Déplacement de la grande carte sur le côté
					if (vitesse < vitesseAfficherCarte) {
						vitesse++;
					}
					xActuel += vitesse*(-sens);
					PA_3DSetSpriteX(11,xActuel);
					PA_CheckLid();
					PA_3DProcess();
					PA_WaitForVBL();
				}
			}
		}
	}
	
	majHistorique();
	sauvegarder();
}

void initFinPartie(int adversaire) {

	int i,j;
	int id=0;
	int joueur,carte;
	int nbCartesGagnees;
	
	PA_WaitForVBL();
	
	if (scoreJoueur == 5) {		// Egalité.
		
		if ((regleAdv[adversaire][8] == 1) && !regleAdv[adversaire][1]) {
			
			// Pour chaque cartes...
			for (i=0;i<5;i++) {
				for (j=0;j<2;j++) {
					if (!carteJouee[j][i]) {
						if ((idCarteInit[5*j+i]/5) != j) {		// Si c'est pas notre carte, on la garde !
							cartePrise[idCarteInit[5*j+i]/5][idCarteInit[5*j+i]%5] = true;
						}
					}
				}
			}
			for (i=0;i<3;i++) {
				for (j=0;j<3;j++) {
					joueur = idCarteInit[idCarte[j+1][i+1]]/5;
					carte = idCarteInit[idCarte[j+1][i+1]]%5;
					if (joueur != plateauJoueur[j+1][i+1]) {
						cartePrise[joueur][carte] = true;
					}
				}
			}
			echangerCartes(adversaire);
		}
		
		victoires[adversaire][2]++;
		sauvegarder();
		
		// On affiche l'égalité...
		PA_3DSetSpriteFrame(31,4);
		PA_3DSetSpriteAlpha(31,0);
		PA_WaitForVBL();
		PA_3DSetSpriteX(31,128);
		PA_WaitForVBL();
		
		for (i=1;i<32;i++) {
			PA_3DSetSpriteAlpha(31,i);
			PA_CheckLid();
			PA_3DProcess();
			PA_WaitForVBL();
		}
		while (!Pad.Newpress.A && !Stylus.Newpress) {
			PA_CheckLid();
			PA_3DProcess();
			PA_WaitForVBL();
		}
		
		if (regleAdv[adversaire][1]) {		// Mort subite : on garde les cartes qu'on possède actuellement
			
			int nouvelleIdCarteInit[10];
			int mainJ[2] = {0,0};
			int joueur;
			int carte;
			
			//fadeBlack(1,true,true,0);
			
			PA_3DSetSpriteX(31,384);
			
			for (i=0;i<5;i++) {
				for (j=0;j<2;j++) {
					if (!carteJouee[j][i]) {
						mainJoueur1[j][0] = mainJoueur1[j][i];
						nouvelleIdCarteInit[5*j] = idCarteInit[5*j+i];
						mainJ[j]++;
					}
				}
			}
			for (i=0;i<3;i++) {
				for (j=0;j<3;j++) {
					joueur = plateauJoueur[j+1][i+1];
					mainJoueur1[joueur][mainJ[joueur]] = plateau[j+1][i+1];
					nouvelleIdCarteInit[5*joueur+mainJ[joueur]] = idCarteInit[idCarte[j+1][i+1]];
					mainJ[joueur]++;
				}
			}
			
			PA_Reset3DSprites();
			
			u16 curseur_gfx = PA_3DCreateTex((void*)curseur3D_Texture, 32, 16, TEX_16COL);
			PA_Load3DSpritePal(10, (void*)curseur3D_Pal);
			PA_3DCreateSpriteFromTex(10,curseur_gfx,20,12,10,266,198);
			PA_3DSetSpritePrio(10,2048);
			
			for (i=0;i<10;i++) {
				joueur = i/5;
				carte = i%5;
				
				idCarteInit[i] = nouvelleIdCarteInit[i];
				
				if (regleAdv[adversaire][0] || (joueur == 1)) {
					id = idCarteInit[i];
				}
				else {
					id = 10;
				}
				//loadCarteMem(i,0,mainJoueur1[joueur][carte]);
				//loadCarte3D(false,i,0,joueur,id,0,0);
				loadCarte3D(true,i,0,joueur,id,25+206*joueur,40+25*carte);
				PA_3DSetSpritePrio(i, 1024+100*carte);
				//PA_3DSetSpriteXY(i,25+joueur*206,40+25*carte);
			}
			
			if (regleAdv[adversaire][7]) {
			
				// On affiche le background pour les elements
				PA_Load3DSpritePal(13,(void*)elementBg_Pal);
				u16 elementBg_gfx = PA_3DCreateTex((void*)elementBg_Texture,128,128,TEX_256COL);
				PA_3DCreateSpriteFromTex(21,elementBg_gfx,128,128,13,128,89);
				PA_3DSetSpritePrio(21,512);
				PA_3DSetSpriteAlpha(21,16);
				PA_3DSetSpritePolyID(21,11);
				
				initElements();
			}
			
			PA_CheckLid();
			PA_3DProcess();
			PA_WaitForVBL();
			
			// Charger la fleche
			u16 fleche_gfx = PA_3DCreateTex((void*)fleche_Texture,16,16,TEX_4COL);
			PA_3DCreateSpriteFromTex(11,fleche_gfx,16,16,11,348,7);
			PA_3DSetSpritePrio(11,2000);
			
			//fadeBlack(1,true,true,1);
			
		}
		
		else if ((regleAdv[adversaire][8] == 1) && cartePriseExiste()) {
			fadeBlack(1,true,false,false,0);
			initEchangeCarte(adversaire);
		}
	}
	
	// Sinon on échange des cartes
	else {
		
		// Déjà, on regarde si la règle Directe est là
		if (regleAdv[adversaire][8] == 1) {
			
			// Pour chaque cartes...
			for (i=0;i<5;i++) {
				for (j=0;j<2;j++) {
					if (!carteJouee[j][i]) {
						if ((idCarteInit[5*j+i]/5) != j) {		// Si c'est pas notre carte, on la garde !
							cartePrise[idCarteInit[5*j+i]/5][idCarteInit[5*j+i]%5] = true;
						}
					}
				}
			}
			for (i=0;i<3;i++) {
				for (j=0;j<3;j++) {
					joueur = idCarteInit[idCarte[j+1][i+1]]/5;
					carte = idCarteInit[idCarte[j+1][i+1]]%5;
					if (joueur != plateauJoueur[j+1][i+1]) {
						cartePrise[joueur][carte] = true;
					}
				}
			}
			echangerCartes(adversaire);
		}
		
		// Puis Totale, ou Change avec un score de 5 points d'écart
		else if ((regleAdv[adversaire][8] == 3) || ((regleAdv[adversaire][8] == 2) && ((scoreJoueur < 3) || (scoreJoueur > 7)))) {
			joueur = (scoreJoueur > 5) ? 0 : 1;
			for (i=0;i<5;i++) {
				cartePrise[joueur][i] = true;
			}
			echangerCartes(adversaire);
		}
		
		if (scoreJoueur < 5) {	// Perdu...
			
			int numeroMax=0;
			
			victoires[adversaire][1]++;
			
			/*  On perd les cartes... */
			
			// D'abord, avec One
			if (regleAdv[adversaire][8] == 0) {
				for (i=0;i<5;i++) {
					if (mainJoueur2[1][i] > numeroMax) {
						numeroMax = mainJoueur2[1][i];
						id = i;
					}
				}
				cartePrise[1][id] = true;
				echangerCartes(adversaire);
			}
			
			// Puis Change...
			
			else if ((regleAdv[adversaire][8] == 2) && (scoreJoueur > 2) && (scoreJoueur < 8)) {		// Si c'est pas comme total...
				nbCartesGagnees = 10-2*scoreJoueur;		// On ne peut pas dépasser 5 (déjà vu ce cas en haut)
				for (i=0;i<nbCartesGagnees;i++) {
					id = 0;
					numeroMax = 0;
					for (j=0;j<5;j++) {
						if (!cartePrise[1][j] && (mainJoueur2[1][j] > numeroMax)) {
							numeroMax = mainJoueur2[1][j];
							id = j;
						}
					}
					cartePrise[1][id] = true;
				}
				echangerCartes(adversaire);
			}
			
			// Et on sauvegarde !
			sauvegarder();
			
			// On affiche...
			PA_3DSetSpriteFrame(31,3);
			PA_3DSetSpriteAlpha(31,0);
			PA_WaitForVBL();
			PA_3DSetSpriteX(31,128);
			
			PA_WaitForVBL();
			
			for (i=1;i<32;i++) {
				PA_3DSetSpriteAlpha(31,i);
				PA_CheckLid();
				PA_3DProcess();
				PA_WaitForVBL();
			}
			
			while (!Pad.Newpress.A && !Stylus.Newpress) {
				PA_CheckLid();
				PA_3DProcess();
				PA_WaitForVBL();
			}
			fadeBlack(1,true,false,false,0);
			initEchangeCarte(adversaire);
		}
		else {	// Gagné !
			victoires[adversaire][0]++;
			sauvegarder();
			
			for (i=1;i<=16;i++) {
				AS_SetMP3Volume(128-8*i);
				PA_3DProcess();
				PA_WaitForVBL();
			}
			
			AS_MP3Stop();
			PA_WaitForVBL();
			AS_SetMP3Volume(127);
			playMusic("fanfare");
			
			// On affiche l'égalité...
			PA_3DSetSpriteFrame(31,5);
			PA_3DSetSpriteAlpha(31,0);
			PA_WaitForVBL();
			PA_3DSetSpriteX(31,128);
			
			PA_WaitForVBL();
			
			for (i=0;i<32;i++) {
				PA_3DSetSpriteAlpha(31,i);
				PA_CheckLid();
				PA_3DProcess();
				PA_WaitForVBL();
			}
			while (!Pad.Newpress.A && !Stylus.Newpress) {
				PA_CheckLid();
				PA_3DProcess();
				PA_WaitForVBL();
			}
			fadeBlack(1,true,false,false,0);
			initEchangeCarte(adversaire);
		}
	}
}

void initFinPartieWifi(bool leader) {
	int i,j;
	int id=0;
	
	PA_WaitForVBL();
	
	if (scoreJoueur == 5) {		// Egalité.
		
		// On affiche l'égalité...
		PA_3DSetSpriteFrame(31,4);
		PA_3DSetSpriteAlpha(31,0);
		PA_WaitForVBL();
		PA_3DSetSpriteX(31,128);
		PA_WaitForVBL();
		
		for (i=1;i<32;i++) {
			PA_3DSetSpriteAlpha(31,i);
			PA_3DProcess();
			PA_WaitForVBL();
		}
		while (!Pad.Newpress.A && !Stylus.Newpress) {
			PA_3DProcess();
			PA_WaitForVBL();
		}
		
		PA_3DSetSpriteX(31,384);
		PA_3DProcess();
		PA_WaitForVBL();
		
		attenteWifi();
		
		if (regleWifi[1]) {		// Mort subite : on garde les cartes qu'on possède actuellement
			
			int joueur;
			int carte;
			mainJWifi[0] = 0;
			mainJWifi[1] = 0;
			
			//fadeBlack(1,true,true,0);
			
			PA_3DSetSpriteX(31,384);
			
			for (i=0;i<5;i++) {
				for (j=0;j<2;j++) {
					if (!carteJouee[j][i]) {
						mainJoueur1[j][mainJWifi[j]] = mainJoueur1[j][i];
						nouvelleIdCarteInitWifi[5*j+mainJWifi[j]] = idCarteInit[5*j+i];
						mainJWifi[j]++;
					}
				}
			}
			for (i=0;i<3;i++) {
				for (j=0;j<3;j++) {
					joueur = plateauJoueur[j+1][i+1];
					carte = plateau[j+1][i+1];
					
					mainJoueur1[joueur][mainJWifi[joueur]] = carte;
					nouvelleIdCarteInitWifi[5*joueur+mainJWifi[joueur]] = idCarteInit[idCarte[j+1][i+1]];
					mainJWifi[joueur]++;
				}
			}
			
			PA_Reset3DSprites();
			
			u16 curseur_gfx = PA_3DCreateTex((void*)curseur3D_Texture, 32, 16, TEX_16COL);
			PA_Load3DSpritePal(10, (void*)curseur3D_Pal);
			PA_3DCreateSpriteFromTex(10,curseur_gfx,20,12,10,266,198);
			PA_3DSetSpritePrio(10,2048);
			
			for (i=0;i<10;i++) {
				joueur = i/5;
				carte = i%5;
				
				idCarteInit[i] = nouvelleIdCarteInitWifi[i];
				
				if (regleWifi[0] || (joueur == 1)) {
					id = idCarteInit[i];
				}
				else {
					id = 10;
				}
				//loadCarteMem(i,0,mainJoueur1[joueur][carte]);
				//loadCarte3D(false,i,0,joueur,id,0,0);
				loadCarte3D(true,i,0,joueur,id,25+206*joueur,40+25*carte);
				PA_3DSetSpritePrio(i, 1024+100*carte);
				//PA_3DSetSpriteXY(i,25+joueur*206,40+25*carte);
			}
			
			attenteWifi();
			
			if (regleWifi[7]) {
				
				// On affiche le background pour les elements
				PA_Load3DSpritePal(13,(void*)elementBg_Pal);
				u16 elementBg_gfx = PA_3DCreateTex((void*)elementBg_Texture,128,128,TEX_256COL);
				PA_3DCreateSpriteFromTex(21,elementBg_gfx,128,128,13,128,89);
				PA_3DSetSpritePrio(21,512);
				PA_3DSetSpriteAlpha(21,16);
				PA_3DSetSpritePolyID(21,11);
				
				attenteWifi();
				
				if (leader) {
					initElements();
				}
				
				attenteWifi();
			}
			
			PA_3DProcess();
			PA_WaitForVBL();
			
			// Charger la fleche
			u16 fleche_gfx = PA_3DCreateTex((void*)fleche_Texture,16,16,TEX_4COL);
			PA_3DCreateSpriteFromTex(11,fleche_gfx,16,16,11,348,7);
			PA_3DSetSpritePrio(11,2000);
			
			//fadeBlack(1,true,true,1);
			
		}
	}
	
	else {
		if (scoreJoueur < 5) {	// Perdu...
			
			scoreWifi[0]++;
			
			// On affiche...
			PA_3DSetSpriteFrame(31,3);
			PA_3DSetSpriteAlpha(31,0);
			PA_WaitForVBL();
			PA_3DSetSpriteX(31,128);
			PA_WaitForVBL();
			
			for (i=1;i<32;i++) {
				PA_3DSetSpriteAlpha(31,i);
				PA_3DProcess();
				PA_WaitForVBL();
			}
			
			while (!Pad.Newpress.A && !Stylus.Newpress) {
				PA_3DProcess();
				PA_WaitForVBL();
			}
			
			PA_3DSetSpriteX(31,384);
			PA_3DProcess();
			PA_WaitForVBL();
			
			attenteWifi();
		}
		else {	// Gagné !
			
			scoreWifi[1]++;
			
			for (i=1;i<=16;i++) {
				AS_SetMP3Volume(128-8*i);
				PA_3DProcess();
				PA_WaitForVBL();
			}
			
			AS_MP3Stop();
			PA_WaitForVBL();
			AS_SetMP3Volume(127);
			playMusic("fanfare");
			
			// On affiche l'égalité...
			PA_3DSetSpriteFrame(31,5);
			PA_3DSetSpriteAlpha(31,0);
			PA_WaitForVBL();
			PA_3DSetSpriteX(31,128);
			PA_WaitForVBL();
			
			for (i=0;i<32;i++) {
				PA_3DSetSpriteAlpha(31,i);
				PA_3DProcess();
				PA_WaitForVBL();
			}
			while (!Pad.Newpress.A && !Stylus.Newpress) {
				PA_3DProcess();
				PA_WaitForVBL();
			}
			
			PA_3DSetSpriteX(31,384);
			PA_3DProcess();
			PA_WaitForVBL();
			
			attenteWifi();
		}
	}
}

int initTest(int zoneXCarte,int zoneYCarte,int adversaire,int plateauTemp[5][5],int plateauJoueurTemp[5][5],int bonusCaseTemp[5][5]) {
	
	int point=0;
	int i,j;
	int nbIdentique1;
	int nbIdentique2;
	int nbPlus1;
	int nbPlus2;
	int plateauActu;
	int bonusActu;
	int joueur = plateauJoueurTemp[zoneXCarte+1][zoneYCarte+1];
	int zone;
	int zoneX;
	int zoneY;
	int zoneAdj[4];
	int zoneXAdj[4];
	int zoneYAdj[4];
	int zoneXAdj2[4];
	int zoneYAdj2[4];
	int plateauAdj[4];
	int valeurAdj[4];
	int valeurActu[4];
	int bonusAdj[4];
	int joueurAdj[4];
	int nouveauJoueur[5][5];
	int nouveauJoueurTemp[5][5];
	bool bordAdj[4];
	bool identique[4];
	bool plus[4];
	bool combo;
	bool premiereCarte=true;
	bool regleIdentique = regleAdv[adversaire][3];
	bool reglePlus = regleAdv[adversaire][4];
	bool regleCombo = regleAdv[adversaire][5];
	bool regleMemeMur = regleAdv[adversaire][6];
	bool nouvelleZonePlateau[9];
	bool zonePlateau[9];
	
	for (i=0;i<9;i++) {
		zonePlateau[i] = false;
	}
	zonePlateau[3*zoneYCarte+zoneXCarte] = true;
	for (i=0;i<5;i++) {
		for (j=0;j<5;j++) {
			nouveauJoueurTemp[i][j] = plateauJoueurTemp[i][j];
		}
	}

	do {
		combo = false;
		for (i=0;i<5;i++) {
			for (j=0;j<5;j++) {
				nouveauJoueur[i][j] = nouveauJoueurTemp[i][j];
			}
		}
		for (i=0;i<9;i++) {
			nouvelleZonePlateau[i] = false;
		}
		
		for (zone=0;zone<9;zone++) {
			if (zonePlateau[zone]) {
				zoneX = zone%3+1;
				zoneY = zone/3+1;
				zoneXAdj[0] = zoneX;
				zoneXAdj[1] = zoneX-1;
				zoneXAdj[2] = zoneX+1;
				zoneXAdj[3] = zoneX;
				zoneYAdj[0] = zoneY-1;
				zoneYAdj[1] = zoneY;
				zoneYAdj[2] = zoneY;
				zoneYAdj[3] = zoneY+1;
				nbIdentique1 = 0;
				nbIdentique2 = 0;
				nbPlus1 = 0;
				nbPlus2 = 0;
				
				plateauActu = plateauTemp[zoneX][zoneY];
				// Ajout du bonus
				if (elementPlateau[zoneX][zoneY] > 0) {
					bonusActu = (elementPlateau[zoneX][zoneY] == elementCarte[plateauActu]) ? 1 : -1;
				}
				else {
					bonusActu = 0;
				}
				
				for (i=0;i<4;i++) {
					zoneAdj[i] = 3*(zoneYAdj[i]-1)+(zoneXAdj[i]-1);
					plateauAdj[i] = plateauTemp[zoneXAdj[i]][zoneYAdj[i]];
					valeurAdj[i] = valeurCarte[plateauAdj[i]][3-i];
					valeurActu[i] = valeurCarte[plateauActu][i];
					bonusAdj[i] = bonusCaseTemp[zoneXAdj[i]][zoneYAdj[i]];
					joueurAdj[i] = nouveauJoueur[zoneXAdj[i]][zoneYAdj[i]];
					bordAdj[i] = ((zoneXAdj[i] == 0) || (zoneXAdj[i] == 4) || (zoneYAdj[i] == 0) || (zoneYAdj[i] == 4));
					identique[i] = false;
					plus[i] = false;
				}
				
				if (premiereCarte) {				// Si c'est la première carte
					for (i=0;i<4;i++) {
						if (bordAdj[i] || (plateauAdj[i] > 0)) {
							point += styleJeu[adversaire][2];
							point += (11-valeurAdj[i])*styleJeu[adversaire][6];
						}
						else if (plateauAdj[i] == 0) {
							point += styleJeu[adversaire][1]*(valeurActu[i]+bonusActu);
						}
						if (regleIdentique || reglePlus) {
							for (j=i+1;j<4;j++) {
								if ((joueurAdj[i] == joueur) && (joueurAdj[j] == joueur)) {
									point += styleJeu[adversaire][3];
								}
							}
						}
						if (joueurAdj[i] == joueur) {
							point += (11-valeurAdj[i])*styleJeu[adversaire][4];
						}
						
					}
				}
				premiereCarte = false;
				
				if (!regleAdv[adversaire][0] && joueur) {
					return point;
				}
				
				/* On commence par Identique */
				
				if (regleIdentique) {
					for (i=0;i<4;i++) {
						if ((valeurActu[i] == valeurAdj[i]) && ((plateauAdj[i] > 0) || (bordAdj[i] && regleMemeMur))) {
							nbIdentique1++;
							identique[i] = true;
							if (!bordAdj[i] && (joueurAdj[i] != joueur)) {
								nbIdentique2++;
							}
						}
					}
					if ((nbIdentique1 > 1) && (nbIdentique2 > 0)) {	// Si on a au moins deux identiques !
						for (i=0;i<4;i++) {
							if (identique[i] && !bordAdj[i] && (joueurAdj[i] != joueur)) {
								point += styleJeu[adversaire][0];
								nouveauJoueur[zoneXAdj[i]][zoneYAdj[i]] = joueur;
								if (regleCombo) {	// Combo
									nouvelleZonePlateau[zoneAdj[i]] = true;
									combo = true;
								}
								// Calcul des valeurs libre de la carte retournée
								zoneXAdj2[0] = zoneXAdj[i];
								zoneXAdj2[1] = zoneXAdj[i]-1;
								zoneXAdj2[2] = zoneXAdj[i]+1;
								zoneXAdj2[3] = zoneXAdj[i];
								zoneYAdj2[0] = zoneYAdj[i]-1;
								zoneYAdj2[1] = zoneYAdj[i];
								zoneYAdj2[2] = zoneYAdj[i];
								zoneYAdj2[3] = zoneYAdj[i]+1;
								for (j=0;j<4;j++) {
									if ((zoneXAdj2[j] != 0) && (zoneXAdj2[j] != 4) && (zoneYAdj2[j] != 0) && (zoneYAdj2[j] != 4) && (plateauTemp[zoneXAdj2[j]][zoneYAdj2[j]] == 0)) {
										point += styleJeu[adversaire][1]*(valeurCarte[plateauAdj[i]][j]+bonusCaseTemp[zoneXAdj2[i]][zoneYAdj2[i]]);
									}
								}
								// Si Directe, calcule des points de la carte
								if (regleAdv[adversaire][8] == 1) {
									point += styleJeu[adversaire][5]*plateauAdj[i];
								}
							}
						}
					}
				}
				
				
				/* Ensuite, Plus */
				
				if (reglePlus) {
					for (i=0;i<4;i++) {
						for (j=i+1;j<4;j++) {
							if (((valeurActu[i]+valeurAdj[i]) == (valeurActu[j]+valeurAdj[j])) && ((plateauAdj[i] > 0) || (bordAdj[i] && regleMemeMur)) && ((plateauAdj[j] > 0) || (bordAdj[j] && regleMemeMur))) {
								plus[i] = true;
								plus[j] = true;
								nbPlus1 += 2;
								if (!bordAdj[i] && (joueurAdj[i] != joueur)) {
									nbPlus2++;
								}
								if (!bordAdj[j] && (joueurAdj[j] != joueur)) {
									nbPlus2++;
								}
							}
						}
					}
					if ((nbPlus1 > 1) && (nbPlus2 > 0)) {	// Si on a au moins deux plus !
						for (i=0;i<4;i++) {
							if (plus[i] && !bordAdj[i] && (joueurAdj[i] != joueur)) {
								point += styleJeu[adversaire][0];
								nouveauJoueur[zoneXAdj[i]][zoneYAdj[i]] = joueur;
								if (regleCombo) {	// Combo
									nouvelleZonePlateau[zoneAdj[i]] = true;
									combo = true;
								}
								// Calcul des valeurs libre de la carte retournée
								zoneXAdj2[0] = zoneXAdj[i];
								zoneXAdj2[1] = zoneXAdj[i]-1;
								zoneXAdj2[2] = zoneXAdj[i]+1;
								zoneXAdj2[3] = zoneXAdj[i];
								zoneYAdj2[0] = zoneYAdj[i]-1;
								zoneYAdj2[1] = zoneYAdj[i];
								zoneYAdj2[2] = zoneYAdj[i];
								zoneYAdj2[3] = zoneYAdj[i]+1;
								for (j=0;j<4;j++) {
									if ((zoneXAdj2[j] != 0) && (zoneXAdj2[j] != 4) && (zoneYAdj2[j] != 0) && (zoneYAdj2[j] != 4) && (plateauTemp[zoneXAdj2[j]][zoneYAdj2[j]] == 0)) {
										point += styleJeu[adversaire][1]*(valeurCarte[plateauAdj[i]][j]+bonusCaseTemp[zoneXAdj2[i]][zoneYAdj2[i]]);
									}
								}
								// Si Directe, calcule des points de la carte
								if (regleAdv[adversaire][8] == 1) {
									point += styleJeu[adversaire][5]*plateauAdj[i];
								}
							}
						}
					}
				}
				
				
				/* Puis on retourne les cartes adjacentes dont la valeur est inférieure */
				
				for (i=0;i<4;i++) {
					if ((plateauAdj[i] > 0) && !bordAdj[i] && (joueurAdj[i] != joueur) && (valeurActu[i]+bonusActu > valeurAdj[i]+bonusAdj[i]) && (nouveauJoueur[zoneXAdj[i]][zoneYAdj[i]] == joueurAdj[i])) {
						point += styleJeu[adversaire][0];
						nouveauJoueur[zoneXAdj[i]][zoneYAdj[i]] = joueur;
						// Calcul des valeurs libre de la carte retournée
						zoneXAdj2[0] = zoneXAdj[i];
						zoneXAdj2[1] = zoneXAdj[i]-1;
						zoneXAdj2[2] = zoneXAdj[i]+1;
						zoneXAdj2[3] = zoneXAdj[i];
						zoneYAdj2[0] = zoneYAdj[i]-1;
						zoneYAdj2[1] = zoneYAdj[i];
						zoneYAdj2[2] = zoneYAdj[i];
						zoneYAdj2[3] = zoneYAdj[i]+1;
						for (j=0;j<4;j++) {
							if ((zoneXAdj2[j] != 0) && (zoneXAdj2[j] != 4) && (zoneYAdj2[j] != 0) && (zoneYAdj2[j] != 4) && (plateauTemp[zoneXAdj2[j]][zoneYAdj2[j]] == 0)) {
								point += styleJeu[adversaire][1]*(valeurCarte[plateauAdj[i]][j]+bonusCaseTemp[zoneXAdj2[i]][zoneYAdj2[i]]);
							}
						}
						// Si Directe, calcule des points de la carte
						if (regleAdv[adversaire][8] == 1) {
							point += styleJeu[adversaire][5]*plateauAdj[i];
						}
					}
				}
			}
		}
		
		if (combo) {
			for (i=0;i<9;i++) {
				zonePlateau[i] = nouvelleZonePlateau[i];
			}
		}
		for (i=0;i<5;i++) {
			for (j=0;j<5;j++) {
				nouveauJoueurTemp[i][j] = nouveauJoueur[i][j];
			}
		}
	}
	while (combo);
	
	return point;
}

/*int initTestAdversaire(int resultat,int alpha,int beta,int adversaire,int joueur,int plateauTemp[5][5],int plateauJoueurTemp[5][5],int bonusCaseTemp[5][5],bool carteJoueeTemp[2][5],int rang,int tour) {
	
	// Si on arrive au bout, on renvoi les points...
	if ((rang < 0) || (tour == 9)) {
		return -resultat;
	}
	
	bool premier = (rang == styleJeu[adversaire][7]);
	int i,j,k,l,m;
	int meilleur=-10000;
	int carte=0;
	int zone=0;
	int carteTemp;
	
	for (i=0;i<5;i++) {												// Pour chaque carte
		if (!carteJoueeTemp[joueur][i]) {								// Si elle n'est pas jouée
			for (j=0;j<3;j++) {										// Pour chaque ligne...
				for (k=0;k<3;k++) {									// ... et colonne du plateau
					if (plateauTemp[k+1][j+1] == 0) {					// Si la case est libre...
						
						// Si c'est le dernier tour... Pas le choix !
						if (premier && (tour == 8)) {
							return 10*i+3*j+k;
						}
						
						// Redéclaration des variables...
						int plateauTemp2[5][5];
						int plateauJoueurTemp2[5][5];
						int bonusCaseTemp2[5][5];
						bool carteJoueeTemp2[2][5];
						
						for (l=0;l<5;l++) {
							for (m=0;m<5;m++) {
								plateauTemp2[l][m] = plateauTemp[l][m];
								plateauJoueurTemp2[l][m] = plateauJoueurTemp[l][m];
								bonusCaseTemp2[l][m] = bonusCaseTemp[l][m];
							}
							for (m=0;m<2;m++) {
								carteJoueeTemp2[m][l] = carteJoueeTemp[m][l];
							}
						}
						
						// On joue virtuellement la carte...
						carteTemp = mainJoueur1[joueur][i];
						plateauTemp2[k+1][j+1] = carteTemp;
						plateauJoueurTemp2[k+1][j+1] = joueur;
						if (elementPlateau[k+1][j+1] > 0) {
							bonusCaseTemp2[k+1][j+1] = (elementPlateau[k+1][j+1] == elementCarte[carteTemp]) ? 1 : -1;
						}
						carteJoueeTemp2[joueur][i] = true;
						
						int test = initTest(k,j,adversaire,plateauTemp2,plateauJoueurTemp2,bonusCaseTemp2);
						
						//alpha = test;
						
						// Et on test !
						alpha = max(alpha,-initTestAdversaire(test,-beta,-alpha,adversaire,1-joueur,plateauTemp2,plateauJoueurTemp2,bonusCaseTemp2,carteJoueeTemp2,rang-1,tour+1));
						
						// Si c'est le premier appel, on devra renvoyer la carte et la zone !
						if (premier) {
							if (alpha > meilleur) {
								meilleur = alpha;
								carte = i;
								zone = 3*j+k;
							}
							char arf[55];
							sprintf(arf,"%d",test);
							PA_16cText(0,26*(3*j+k),10*i,256,192,arf,1,5,55);
							sprintf(arf,"%d",alpha);
							PA_16cText(0,26*(3*j+k),50+10*i,256,192,arf,1,5,55);
						}
						
						// Sinon, on revoi tout simplement les points gagnés
						else {
							if (alpha >= beta) {	// Coupure alphabeta
								return alpha;
							}
						}
						
						/*maxTemp = initTest(k,j,adversaire,plateauTemp2,plateauJoueurTemp2,bonusCaseTemp2)-initTestAdversaire(false,adversaire,1-joueur,plateauTemp2,plateauJoueurTemp2,bonusCaseTemp2,carteJoueeTemp2,rang-1,tour+1);	// On teste cette carte sur cette case !
						if (maxTemp > max) {							// Si on a les meilleurs résultats
							max = maxTemp;								// On le stock
							carte = i;									// On définie la carte...
							zone = 3*j+k;								// ... et la zone !
						}
						if (first) {
							char arf[55];
							sprintf(arf,"%d:%d",max,i);
							PA_16cText(0,0,10*i,256,192,arf,1,5,55);
						}*//*
					}
				}
			}
		}
	}
	if (premier) {
		return carte*10+zone;
	}
	return alpha;
}*/

int initTestAdversaire(int resultat,int adversaire,int joueur,int plateauTemp[5][5],int plateauJoueurTemp[5][5],int bonusCaseTemp[5][5],bool carteJoueeTemp[2][5],int rang,int tour) {
	
	// Si on arrive au bout, on renvoi les points...
	if ((rang < 0) || (tour == 9)) {
		return resultat;
	}
	
	bool premier = (rang == styleJeu[adversaire][7]);
	int i,j,k,l,m;
	int meilleur=-10000;
	int test;
	int carte=0;
	int zone=0;
	int carteTemp;
	
	for (i=0;i<5;i++) {												// Pour chaque carte
		if (!carteJoueeTemp[joueur][i]) {								// Si elle n'est pas jouée
			if (premier) {
				for (j=0;j<5;j++) {
					if (!carteJouee[0][j]) {
						PA_3DSetSpriteX(j,25);
					}
				}
				PA_3DSetSpriteX(i,27);
				PA_3DProcess();
				PA_WaitForVBL();
			}
			for (j=0;j<3;j++) {										// Pour chaque ligne...
				for (k=0;k<3;k++) {									// ... et colonne du plateau
					if (plateauTemp[k+1][j+1] == 0) {					// Si la case est libre...
						
						// Si c'est le dernier tour... Pas le choix !
						if (premier && (tour == 8)) {
							return 10*i+3*j+k;
						}
						
						// Redéclaration des variables...
						int plateauTemp2[5][5];
						int plateauJoueurTemp2[5][5];
						int bonusCaseTemp2[5][5];
						bool carteJoueeTemp2[2][5];
						
						for (l=0;l<5;l++) {
							for (m=0;m<5;m++) {
								plateauTemp2[l][m] = plateauTemp[l][m];
								plateauJoueurTemp2[l][m] = plateauJoueurTemp[l][m];
								bonusCaseTemp2[l][m] = bonusCaseTemp[l][m];
							}
							for (m=0;m<2;m++) {
								carteJoueeTemp2[m][l] = carteJoueeTemp[m][l];
							}
						}
						
						// On joue virtuellement la carte...
						carteTemp = mainJoueur1[joueur][i];
						plateauTemp2[k+1][j+1] = carteTemp;
						plateauJoueurTemp2[k+1][j+1] = joueur;
						if (elementPlateau[k+1][j+1] > 0) {
							bonusCaseTemp2[k+1][j+1] = (elementPlateau[k+1][j+1] == elementCarte[carteTemp]) ? 1 : -1;
						}
						carteJoueeTemp2[joueur][i] = true;
						
						// Et on test !
						test = initTestAdversaire(initTest(k,j,adversaire,plateauTemp2,plateauJoueurTemp2,bonusCaseTemp2),adversaire,1-joueur,plateauTemp2,plateauJoueurTemp2,bonusCaseTemp2,carteJoueeTemp2,rang-1,tour+1);
						
						// Si c'est le premier appel, on devra renvoyer la carte et la zone !
						if (test > meilleur) {
							meilleur = test;
							if (premier) {
								carte = i;
								zone = 3*j+k;
							}
						}
					}
				}
			}
		}
	}
	if (premier) {
		return carte*10+zone;
	}
	return resultat+meilleur*(1-2*joueur);
}


int initTourJoueur() {

	int i,j;
	int positionCurseurX=1;
	int positionCurseurY=1;
	int positionCurseurY2=0;
	int timer=0;
	int carteSelection=0;
	bool selection = false;
	
	for (i=0;i<5;i++) {
		if (!carteJouee[1][i]) {
			PA_3DSetSpriteXY(10,200,40+25*i);
			PA_3DSetSpriteX(i+5,229);
			positionCurseurY2 = i;
				
			if (wifiOn) {
				envoiWifi(false,0x0006,"",positionCurseurY2+10);
			}
			
			break;
		}
	}
	
	majCarteG(1,mainJoueur1[1][positionCurseurY2]);
	afficherNomCarte(mainJoueur1[1][positionCurseurY2],-1,0);
	
	while (1) {
		if (selection) {
			if (Pad.Newpress.Down || Pad.Newpress.Up) {
				positionCurseurY += Pad.Newpress.Down - Pad.Newpress.Up;
				if (positionCurseurY == 3) {
					positionCurseurY = 0;
				}
				else if (positionCurseurY == -1) {
					positionCurseurY = 2;
				}
				PA_3DSetSpriteY(10,41+50*positionCurseurY);
				majCarteG(plateauJoueur[positionCurseurX+1][positionCurseurY+1],plateau[positionCurseurX+1][positionCurseurY+1]);
				afficherNomCarte(plateau[positionCurseurX+1][positionCurseurY+1],-1,0);
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				
				timer = 0;
			}
			else if (Pad.Held.Down || Pad.Held.Up) {
				if (timer == timerCurseur1) {
					positionCurseurY += Pad.Held.Down - Pad.Held.Up;
					if (positionCurseurY == 3) {
						positionCurseurY = 0;
					}
					else if (positionCurseurY == -1) {
						positionCurseurY = 2;
					}
					PA_3DSetSpriteY(10,41+50*positionCurseurY);
					majCarteG(plateauJoueur[positionCurseurX+1][positionCurseurY+1],plateau[positionCurseurX+1][positionCurseurY+1]);
					afficherNomCarte(plateau[positionCurseurX+1][positionCurseurY+1],-1,0);
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					timer -= timerCurseur2;
				}
				else {
					timer++;
				}
			}
			else if (Pad.Newpress.Right || Pad.Newpress.Left) {
				positionCurseurX += Pad.Newpress.Right - Pad.Newpress.Left;
				if (positionCurseurX == 3) {
					positionCurseurX = 0;
				}
				else if (positionCurseurX == -1) {
					positionCurseurX = 2;
				}
				PA_3DSetSpriteX(10,68+50*positionCurseurX);
				majCarteG(plateauJoueur[positionCurseurX+1][positionCurseurY+1],plateau[positionCurseurX+1][positionCurseurY+1]);
				afficherNomCarte(plateau[positionCurseurX+1][positionCurseurY+1],-1,0);
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				
				timer = 0;
			}
			else if (Pad.Held.Right || Pad.Held.Left) {
				if (timer == timerCurseur1) {
					positionCurseurX += Pad.Held.Right - Pad.Held.Left;
					if (positionCurseurX == 3) {
						positionCurseurX = 0;
					}
					else if (positionCurseurX == -1) {
						positionCurseurX = 2;
					}
					PA_3DSetSpriteX(10,68+50*positionCurseurX);
					majCarteG(plateauJoueur[positionCurseurX+1][positionCurseurY+1],plateau[positionCurseurX+1][positionCurseurY+1]);
					afficherNomCarte(plateau[positionCurseurX+1][positionCurseurY+1],-1,0);
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					timer -= timerCurseur2;
				}
				else {
					timer++;
				}
			}
			if (Pad.Newpress.A) {
				if (plateau[positionCurseurX+1][positionCurseurY+1] == 0) {
					carteJouee[1][carteSelection] = true;
					idCarte[positionCurseurX+1][positionCurseurY+1] = carteSelection+5;
					PA_3DSetSpriteY(10,256);
					if (wifiOn) {
						envoiWifi(false,0x0004,"",carteSelection*10+(3*positionCurseurY+positionCurseurX));
					}
					deplacementCarte(carteSelection+5,positionCurseurX,positionCurseurY);
					return 3*positionCurseurY+positionCurseurX;
				}
				else {
					AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
				}
			}
			else if (Pad.Newpress.B) {
				selection = false;
				PA_3DSetSpriteXY(10,200,40+25*positionCurseurY2);
				AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
				majCarteG(1,mainJoueur1[1][positionCurseurY2]);
				afficherNomCarte(mainJoueur1[1][positionCurseurY2],-1,0);
			}
			if (Stylus.Newpress || Stylus.Held) {
				for (i=0;i<3;i++) {
					for (j=0;j<3;j++) {
						if (PA_StylusInZone(53+50*j,14+50*i,103+50*j,64+50*i) && ((positionCurseurX != j) || (positionCurseurY != i))) {
							positionCurseurX = j;
							positionCurseurY = i;
							PA_3DSetSpriteXY(10,68+50*positionCurseurX,41+50*positionCurseurY);
							majCarteG(plateauJoueur[positionCurseurX+1][positionCurseurY+1],plateau[positionCurseurX+1][positionCurseurY+1]);
							afficherNomCarte(plateau[positionCurseurX+1][positionCurseurY+1],-1,0);
						}
					}
				}
			}
			if (Stylus.Released) {
				if (PA_StylusInZone(53,14,203,164)) {
					if (plateau[positionCurseurX+1][positionCurseurY+1] == 0) {
						carteJouee[1][carteSelection] = true;
						idCarte[positionCurseurX+1][positionCurseurY+1] = carteSelection+5;
						PA_3DSetSpriteY(10,256);
						if (wifiOn) {
							envoiWifi(false,0x0004,"",carteSelection*10+(3*positionCurseurY+positionCurseurX));
						}
						deplacementCarte(carteSelection+5,positionCurseurX,positionCurseurY);
						return 3*positionCurseurY+positionCurseurX;
					}
					else {
						AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
					}
				}
				else if (PA_StylusInZone(206,14,256,164)) {
					selection = false;
					PA_3DSetSpriteXY(10,200,40+25*positionCurseurY2);
					AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
					majCarteG(1,mainJoueur1[1][positionCurseurY2]);
					afficherNomCarte(mainJoueur1[1][positionCurseurY2],-1,0);
				}
			}
		}
		else {
			if (Pad.Newpress.Down || Pad.Newpress.Up) {
				int deplacementCurseur = Pad.Newpress.Down - Pad.Newpress.Up;
				do {
					positionCurseurY2 += deplacementCurseur;
					if (positionCurseurY2 == 5) {
						positionCurseurY2 = 0;
					}
					else if (positionCurseurY2 == -1) {
						positionCurseurY2 = 4;
					}
				}
				while (carteJouee[1][positionCurseurY2]);
				
				if (wifiOn) {
					envoiWifi(false,0x0006,"",positionCurseurY2+10);
				}
				
				PA_3DSetSpriteY(10,40+25*positionCurseurY2);
				majCarteG(1,mainJoueur1[1][positionCurseurY2]);
				afficherNomCarte(mainJoueur1[1][positionCurseurY2],-1,0);
				for (i=0;i<5;i++) {
					if (i == positionCurseurY2) {
						PA_3DSetSpriteX(i+5,229);
					}
					else if (!carteJouee[1][i]) {
						PA_3DSetSpriteX(i+5,231);
					}
				}
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				
				timer = 0;
			}
			else if (Pad.Held.Down || Pad.Held.Up) {
				if (timer == timerCurseur1) {
					int deplacementCurseur = Pad.Held.Down - Pad.Held.Up;
					do {
						positionCurseurY2 += deplacementCurseur;
						if (positionCurseurY2 == 5) {
							positionCurseurY2 = 0;
						}
						else if (positionCurseurY2 == -1) {
							positionCurseurY2 = 4;
						}
					}
					while (carteJouee[1][positionCurseurY2]);
					
					if (wifiOn) {
						envoiWifi(false,0x0006,"",positionCurseurY2+10);
					}
					
					PA_3DSetSpriteY(10,40+25*positionCurseurY2);
					majCarteG(1,mainJoueur1[1][positionCurseurY2]);
					afficherNomCarte(mainJoueur1[1][positionCurseurY2],-1,0);
					for (i=0;i<5;i++) {
						if (i == positionCurseurY2) {
							PA_3DSetSpriteX(i+5,229);
						}
						else if (!carteJouee[1][i]) {
							PA_3DSetSpriteX(i+5,231);
						}
					}
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					timer -= timerCurseur2;
				}
				else {
					timer++;
				}
			}
			if (Pad.Newpress.A) {
				carteSelection = positionCurseurY2;
				selection = true;
				PA_3DSetSpriteXY(10,68+50*positionCurseurX,41+50*positionCurseurY);
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				majCarteG(plateauJoueur[positionCurseurX+1][positionCurseurY+1],plateau[positionCurseurX+1][positionCurseurY+1]);
				afficherNomCarte(plateau[positionCurseurX+1][positionCurseurY+1],-1,0);
			}
			if (Stylus.Newpress || Stylus.Held) {
				for (i=0;i<6;i++) {
					if (PA_StylusInZone(206,14+25*i,256,39+25*i) && (i != positionCurseurY2)) {
						if (i == 0) {
							if (!carteJouee[1][i]) {
								positionCurseurY2 = i;
								
								if (wifiOn) {
									envoiWifi(false,0x0006,"",positionCurseurY2+10);
								}
								
								PA_3DSetSpriteY(10,40+25*positionCurseurY2);
								majCarteG(1,mainJoueur1[1][positionCurseurY2]);
								afficherNomCarte(mainJoueur1[1][positionCurseurY2],-1,0);
								for (j=0;j<5;j++) {
									if (j == positionCurseurY2) {
										PA_3DSetSpriteX(j+5,229);
									}
									else if (!carteJouee[1][j]) {
										PA_3DSetSpriteX(j+5,231);
									}
								}
							}
						}
						else if (i == 5) {
							if (!carteJouee[1][i-1]) {
								positionCurseurY2 = i-1;
								
								if (wifiOn) {
									envoiWifi(false,0x0006,"",positionCurseurY2+10);
								}
								
								PA_3DSetSpriteY(10,40+25*positionCurseurY2);
								majCarteG(1,mainJoueur1[1][positionCurseurY2]);
								afficherNomCarte(mainJoueur1[1][positionCurseurY2],-1,0);
								for (j=0;j<5;j++) {
									if (j == positionCurseurY2) {
										PA_3DSetSpriteX(j+5,229);
									}
									else if (!carteJouee[1][j]) {
										PA_3DSetSpriteX(j+5,231);
									}
								}
							}
						}
						else {
							if (!carteJouee[1][i] || !carteJouee[1][i-1]) {
								positionCurseurY2 = !carteJouee[1][i] ? i : i-1;
								
								if (wifiOn) {
									envoiWifi(false,0x0006,"",positionCurseurY2+10);
								}
								
								PA_3DSetSpriteY(10,40+25*positionCurseurY2);
								majCarteG(1,mainJoueur1[1][positionCurseurY2]);
								afficherNomCarte(mainJoueur1[1][positionCurseurY2],-1,0);
								for (j=0;j<5;j++) {
									if (j == positionCurseurY2) {
										PA_3DSetSpriteX(j+5,229);
									}
									else if (!carteJouee[1][j]) {
										PA_3DSetSpriteX(j+5,231);
									}
								}
							}
						}
					}
				}
			}
			if (Stylus.Released) {
				for (i=0;i<6;i++) {
					if (PA_StylusInZone(206,14+25*i,256,39+25*i)) {
						if (((i == 0) && !carteJouee[1][0]) || ((i == 5) && !carteJouee[1][4]) || (((i > 0) && (i < 5)) && (!carteJouee[1][i] || !carteJouee[1][i-1]))) {
							carteSelection = positionCurseurY2;
							selection = true;
							PA_3DSetSpriteXY(10,68+50*positionCurseurX,41+50*positionCurseurY);
							AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
							majCarteG(plateauJoueur[positionCurseurX+1][positionCurseurY+1],plateau[positionCurseurX+1][positionCurseurY+1]);
							afficherNomCarte(plateau[positionCurseurX+1][positionCurseurY+1],-1,0);
						}
					}
				}
			}
		}
		
		PA_CheckLid();
		PA_3DProcess();
		PA_WaitForVBL();
	}
	
	return 0;
}

int initTourAdversaire(int adversaire,int tour) {

	int i,j;
	int carte;
	int zone;
	int valeurJeu;
	//	PA_16cErase(0);
	//	PA_16cTextAlign(ALIGN_LEFT);
	
	int plateauTemp[5][5];
	int plateauJoueurTemp[5][5];
	int bonusCaseTemp[5][5];
	bool carteJoueeTemp[2][5];
	
	for (i=0;i<5;i++) {
		for (j=0;j<5;j++) {
			plateauTemp[i][j] = plateau[i][j];
			plateauJoueurTemp[i][j] = plateauJoueur[i][j];
			bonusCaseTemp[i][j] = bonusCase[i][j];
		}
		for (j=0;j<2;j++) {
			carteJoueeTemp[j][i] = carteJouee[j][i];
		}
	}
	
	valeurJeu = initTestAdversaire(0,adversaire,0,plateauTemp,plateauJoueurTemp,bonusCaseTemp,carteJoueeTemp,styleJeu[adversaire][7],tour);
	
	carte = valeurJeu/10;
	zone = valeurJeu%10;
	
	for (i=0;i<5;i++) {
		if (!carteJouee[0][i]) {
			PA_3DSetSpriteX(i,25);
		}
	}
	PA_3DSetSpriteX(carte,27);
	
	PA_3DProcess();
	PA_WaitForVBL();
	
	idCarte[zone%3+1][zone/3+1] = carte;
	carteJouee[0][carte] = true;
	deplacementCarte(carte,zone%3,zone/3);

	/*char truc[32];
	sprintf(truc,"%d",max);
	PA_16cText(0,0,164,256,192,truc,1,5,32);*/
	
	return zone;
}

int initTourAdversaireWifi() {
	idCarte[zoneWifi%3+1][zoneWifi/3+1] = carteWifi;
	carteJouee[0][carteWifi] = true;
	deplacementCarte(carteWifi,zoneWifi%3,zoneWifi/3);
	
	return zoneWifi;
}

void initAppliquerRegles(int * reglesActuelles,bool zonePlateau[9]) {

	bool regleIdentique = reglesActuelles[3];
	bool reglePlus = reglesActuelles[4];
	bool regleCombo = reglesActuelles[5];
	bool regleMemeMur = reglesActuelles[6];
	bool combo;
	bool identiqueAffichage;
	bool plusAffichage;
	bool comboAffichage = false;
	bool afficherRetournement;
	bool identique[4];
	bool plus[4];
	bool nouvelleZonePlateau[9];
	bool bordAdj[4];
	bool carteBrille[3][3];
	int retournementAdj[4];
	int valeurAdj[4];
	int valeurActu[4];
	int bonusAdj[4];
	int idAdj[4];
	int joueurAdj[4];
	int plateauAdj[4];
	int zoneAdj[4];
	int zoneXAdj[4];
	int zoneYAdj[4];
	int zone;
	int zoneX;
	int zoneY;
	int plateauActu;
	int joueurActu=0;
	int bonusActu;
	int nbIdentique1;
	int nbIdentique2;
	int nbPlus1;
	int nbPlus2;
	int cartesARetourner[10];
	int nouveauPlateauJoueur[5][5];
	int i,j;

	do {
		identiqueAffichage = false;
		plusAffichage = false;
		afficherRetournement = false;
		combo = false;
		for (i=0;i<3;i++) {
			for (j=0;j<3;j++) {
				carteBrille[i][j] = false;
			}
		}
		for (i=0;i<5;i++) {
			for (j=0;j<5;j++) {
				nouveauPlateauJoueur[i][j] = plateauJoueur[i][j];
			}
		}
		for (i=0;i<9;i++) {
			nouvelleZonePlateau[i] = false;
			cartesARetourner[i] = -1;
		}
		cartesARetourner[9] = -1;
		
		for (zone=0;zone<9;zone++) {
			if (zonePlateau[zone]) {
				zoneX = zone%3+1;
				zoneY = zone/3+1;
				zoneXAdj[0] = zoneX;
				zoneXAdj[1] = zoneX-1;
				zoneXAdj[2] = zoneX+1;
				zoneXAdj[3] = zoneX;
				zoneYAdj[0] = zoneY-1;
				zoneYAdj[1] = zoneY;
				zoneYAdj[2] = zoneY;
				zoneYAdj[3] = zoneY+1;
				retournementAdj[0] = 1;
				retournementAdj[1] = 0;
				retournementAdj[2] = 0;
				retournementAdj[3] = 1;
				nbIdentique1 = 0;
				nbIdentique2 = 0;
				nbPlus1 = 0;
				nbPlus2 = 0;
				
				plateauActu = plateau[zoneX][zoneY];
				joueurActu = plateauJoueur[zoneX][zoneY];
				bonusActu = bonusCase[zoneX][zoneY];
				
				for (i=0;i<4;i++) {
					zoneAdj[i] = 3*(zoneYAdj[i]-1)+(zoneXAdj[i]-1);
					plateauAdj[i] = plateau[zoneXAdj[i]][zoneYAdj[i]];
					valeurAdj[i] = valeurCarte[plateauAdj[i]][3-i];
					valeurActu[i] = valeurCarte[plateauActu][i];
					bonusAdj[i] = bonusCase[zoneXAdj[i]][zoneYAdj[i]];
					idAdj[i] = idCarte[zoneXAdj[i]][zoneYAdj[i]];
					joueurAdj[i] = plateauJoueur[zoneXAdj[i]][zoneYAdj[i]];
					bordAdj[i] = ((zoneXAdj[i] == 0) || (zoneXAdj[i] == 4) || (zoneYAdj[i] == 0) || (zoneYAdj[i] == 4));
					identique[i] = false;
					plus[i] = false;
				}
				
				/* On commence par Identique */
				
				if (regleIdentique) {
					for (i=0;i<4;i++) {
						if ((valeurActu[i] == valeurAdj[i]) && ((plateauAdj[i] > 0) || (bordAdj[i] && regleMemeMur))) {
							nbIdentique1++;
							identique[i] = true;
							if (!bordAdj[i] && (joueurAdj[i] != joueurActu)) {
								nbIdentique2++;
							}
						}
					}
					if ((nbIdentique1 > 1) && (nbIdentique2 > 0)) {	// Si on a au moins deux identiques !
						afficherRetournement = true;
						if (!comboAffichage) {
							identiqueAffichage = true;
						}
						carteBrille[zoneX-1][zoneY-1] = true;
						for (i=0;i<4;i++) {
							if (identique[i] && !bordAdj[i]) {
								carteBrille[zoneXAdj[i]-1][zoneYAdj[i]-1] = true;
								if (joueurAdj[i] != joueurActu) {
									cartesARetourner[idAdj[i]] = retournementAdj[i];
									nouveauPlateauJoueur[zoneXAdj[i]][zoneYAdj[i]] = joueurActu;
									if (regleCombo) {	// Combo
										nouvelleZonePlateau[zoneAdj[i]] = true;
										combo = true;
									}
								}
							}
						}
					}
				}
				
				
				/* Ensuite, Plus */
				
				if (reglePlus) {
					for (i=0;i<4;i++) {
						for (j=i+1;j<4;j++) {
							if (((valeurActu[i]+valeurAdj[i]) == (valeurActu[j]+valeurAdj[j])) && ((plateauAdj[i] > 0) || (bordAdj[i] && regleMemeMur)) && ((plateauAdj[j] > 0) || (bordAdj[j] && regleMemeMur))) {
								plus[i] = true;
								plus[j] = true;
								nbPlus1 += 2;
								if (!bordAdj[i] && (joueurAdj[i] != joueurActu)) {
									nbPlus2++;
								}
								if (!bordAdj[j] && (joueurAdj[j] != joueurActu)) {
									nbPlus2++;
								}
							}
						}
					}
					if ((nbPlus1 > 1) && (nbPlus2 > 0)) {	// Si on a au moins deux plus !
						afficherRetournement = true;
						if (!comboAffichage) {
							plusAffichage = true;
						}
						for (i=0;i<4;i++) {
							if (plus[i] && !bordAdj[i]) {
								carteBrille[zoneXAdj[i]-1][zoneYAdj[i]-1] = true;
								if (joueurAdj[i] != joueurActu) {
									cartesARetourner[idAdj[i]] = retournementAdj[i];
									nouveauPlateauJoueur[zoneXAdj[i]][zoneYAdj[i]] = joueurActu;
									if (regleCombo) {	// Combo
										nouvelleZonePlateau[zoneAdj[i]] = true;
										combo = true;
									}
								}
							}
						}
						carteBrille[zoneX-1][zoneY-1] = true;
					}
				}
				
				
				/* Puis on retourne les cartes adjacentes dont la valeur est inférieure */
				
				for (i=0;i<4;i++) {
					if ((plateauAdj[i] > 0) && !bordAdj[i] && (joueurAdj[i] != joueurActu) && (valeurActu[i]+bonusActu > valeurAdj[i]+bonusAdj[i])) {
						afficherRetournement = true;
						cartesARetourner[idAdj[i]] = retournementAdj[i];
						nouveauPlateauJoueur[zoneXAdj[i]][zoneYAdj[i]] = joueurActu;
					}
				}
			}
		}
		if (afficherRetournement) {
			retournerCartes(cartesARetourner,joueurActu,identiqueAffichage,plusAffichage,comboAffichage,carteBrille);
		}
		if (combo) {
			comboAffichage = true;
			for (i=0;i<9;i++) {
				zonePlateau[i] = nouvelleZonePlateau[i];
			}
		}
		for (i=0;i<5;i++) {
			for (j=0;j<5;j++) {
				plateauJoueur[i][j] = nouveauPlateauJoueur[i][j];
			}
		}
		majScore();
		PA_SetSpriteAnim(1,4,10-scoreJoueur);
		PA_SetSpriteAnim(1,9,scoreJoueur);
	}
	while (combo);
}

void initDeplacerFleche(int tourJoueur) {
	int joueurActu = !tourJoueur;
	int xActu = 25+206*joueurActu;
	int xFinal = 25+206*tourJoueur;
	int deplacementX = (206/frameDeplacementFleche)*(-2*joueurActu+1);
	
	PA_3DSpriteAnimPause(11,1);
	PA_3DSetSpriteFrame(11,0);
	
	while (xActu != xFinal) {
		xActu += deplacementX;
		if ((tourJoueur && (xActu > xFinal)) || (joueurActu && (xActu < xFinal))) {
			xActu = xFinal;
		}
		PA_3DSetSpriteX(11,xActu);
		PA_CheckLid();
		PA_3DProcess();
		PA_WaitForVBL();
	}
	
	PA_3DSpriteAnimPause(11,0);
}

void afficherCartes(int type) {

	int debut=0;
	int fin=1;
	
	if (type == 0) {
		fin = 0;
	}
	else if (type == 1) {
		debut = 1;
	}

	int i,j;
	int numero;
	int yInit[5],yActuel[5],yFinal[5];
	int vitesse[5];
	bool cartePlacee[5];
	int frame = 4*framesEntreDeuxCartes;
	int distanceArret=0;
	
	for (i=1;i<vitesseAfficherCarte;i++) {
		distanceArret += i;
	}
	
	for (i=0;i<5;i++) {
		for (j=debut;j<=fin;j++) {
			numero = (j == 1) ? i+5 : 10;
			loadCarteMem(i+5*j,0,0,mainJoueur1[j][i]);
			loadCarte3D(false,i+5*j,0,j,numero,0,0);
			PA_3DSetSpritePrio(i+5*j, 1024+100*i);
		}
		yInit[i] = -152+25*i;
		yActuel[i] = -152+25*i;
		yFinal[i] = 40+25*i;
		vitesse[i] = vitesseAfficherCarte;
		cartePlacee[i] = false;
	}
	
	// On fait maintenant glisser les cartes sur le plateau depuis le haut de l'écran
	//EFS_PlaySound("bruitMain",2);
	while (!cartePlacee[0]) {	// Temps que toutes les cartes ne sont pas placer, on les déplace (normal)
		for (i=4;i>=0;i--) {	// On commence par la dernière carte
			if ((frame <= i*framesEntreDeuxCartes) && !cartePlacee[i]) {	// On ne les déplace pas toutes en même temps
				if ((yActuel[i]+distanceArret > yFinal[i]) && (vitesse[i] > 1)) {	// Si on a atteind la limite, il faut ralentir
					vitesse[i]--;
				}
				yActuel[i] += vitesse[i];
				if (yActuel[i] >= yFinal[i]) {	// Si la carte est placée...
					yActuel[i] = yFinal[i];
					cartePlacee[i] = true;
					AS_SoundDefaultPlay((void*)bruitCarte,8576,127,64,0,0);
				}
				for (j=debut;j<=fin;j++) {
					PA_3DSetSpriteY(i+5*j,yActuel[i]);	// On affiche...
				}
			}
			frame--;
		}
		PA_CheckLid();
		PA_3DProcess();
		PA_WaitForVBL();
	}
}

void initRetournerCartes() {
	
	int i;
	int rot[5];
	float zoom[5];
	int frame = 4*framesEntreDeuxCartes;
	bool cartePlacee[5];
	
	for (i=0;i<5;i++) {	// On initialise tout
		rot[i] = 16;
		zoom[i] = 1;
		cartePlacee[i] = false;
	}

	// Puis on tourne les cartes :)

	while (!cartePlacee[0]) {
		for (i=4;i>=0;i--) {
			if ((frame <= i*framesEntreDeuxCartes) && !cartePlacee[i]) {	// On ne les déplace pas toutes en même temps
				if (rot[i] < 128) {
					zoom[i] += 0.03;
				}
				else if (rot[i] == 128) {
					loadCarte3D(false,i,0,0,i,0,0);
					rot[i] = 384;
				}
				else if (rot[i] < 512) {
					zoom[i] -= 0.03;
				}
				else {
					rot[i] = 0;
					zoom[i] = 1;
					//AS_SoundDefaultPlay((void*)bruitCarte,8576,127,64,0,0);
					cartePlacee[i] = true;
				}
				PA_3DSetSpriteRotateY(i,rot[i]);
				PA_3DSetSpriteZoomXY(i,zoom[i],zoom[i]);
				rot[i] += 16;
			}
			frame--;
		}
		PA_CheckLid();
		PA_3DProcess();
		PA_WaitForVBL();
	}
}

void initMainAleatoire(int joueur) {

	int i,j;
	int numero;
	int carte=0;
	bool doublon;
	
	if (joueur == 12) {		// Si c'est le joueur
		int nombreCarte=0;
		int carteDispo[getNombreCarte(1,1,10)];
		for (i=1;i<111;i++) {
			for (j=0;j<collection[i];j++) {
				carteDispo[nombreCarte++] = i;
			}
		}
		
		// On a mit dans un tableau toutes les cartes à disposition, plus qu'à les prendre sans doublon :)
		int nouvelleMain[5];	// On met les correspondances dans un nouveau tableau...
		for (i=0;i<5;i++) {
			do {
				doublon = false;
				numero = PA_RandMax(nombreCarte-1);
				for (j=0;j<i;j++) {
					if (nouvelleMain[j] == numero) {
						doublon = true;
					}
				}
			}
			while (doublon);	// Pas de doublon !
			nouvelleMain[i] = numero;
		}
		
		// Et on recopie tout ça dans la main !
		for (i=0;i<5;i++) {
			mainJoueur1[1][i] = carteDispo[nouvelleMain[i]];
		}
		
		if (wifiOn) {
			char envoi[24];
			sprintf(envoi,"%d %d %d %d %d ",mainJoueur1[1][0],mainJoueur1[1][1],mainJoueur1[1][2],mainJoueur1[1][3],mainJoueur1[1][4]);
			envoiWifi(true,0x0007,envoi,24);
		}
	}
	else {	// Sinon, c'est un adversaire
		// Déjà, on regarde si on a besoin de gagner une carte pour débloquer la suite...
		if ((conditionDebloquer[joueur][1] > 0) && (cartesRares[joueur][conditionDebloquer[joueur][1]-78])) {
			if (PA_RandMinMax(1,chanceCarteRare[joueur]) == 1) {	// Une chance sur n d'avoir cette carte
				mainJoueur1[0][carte++] = conditionDebloquer[joueur][1];
			}
		}
		// Ensuite, on regarde si on doit prendre des cartes rares...
		for (i=2;i>=0;i--) {	// Les cartes des plus fortes en premier
			if (carteDebloque[joueur][i] <= persoDebloque) {	// Si on peut prendre ce niveau de carte...
				for (j=10;j>=0;j--) {
					if ((78+11*i+j) != conditionDebloquer[joueur][1]) {	// Elle a déjà eut sa chance, celle-là
						if (cartesRares[joueur][11*i+j]) {		// Si l'adversaire possède cette carte
							if (PA_RandMinMax(1,chanceCarteRare[joueur]) == 1) {	// Une chance sur n d'avoir cette carte
								mainJoueur1[0][carte++] = 78+11*i+j;
								if (carte == 5) {	// Si on a déjà atteint 5 cartes (petit chanceux !)
									break;
								}
							}
						}
					}
				}
				if (carte == 5) {	// Si on a déjà atteint 5 cartes (petit chanceux !)
					break;
				}
			}
		}
		
		// On a fini avec les cartes rares, fiou !
		for (i=carte;i<5;i++) {	// Si on doit en rajouter...
			do {
				doublon = false;
				numero = PA_RandMinMax(11*(carteLvlMax[joueur][0]-1)+1,11*(carteLvlMax[joueur][1]));
				for (j=0;j<i;j++) {
					if (mainJoueur1[0][j] == numero) {
						doublon = true;
					}
				}
			}
			while (doublon || ((numero == 48) && (joueur != 11)));	// Pas de doublon ! Seul Boko peut avoir Koyo K !
			mainJoueur1[0][i] = numero;
		}
	}
	// Et voilà ! ;)
}

void initChoixCarte() {
	// Affichage de la fenetre
	u16 fenetre_gfx = PA_3DCreateTex((void*)fenetreListeCarte_Texture,128,256,TEX_256COL);
	PA_Load3DSpritePal(11, (void*)fenetreListeCarte_Pal);
	PA_3DCreateSpriteFromTex(11,fenetre_gfx,128,156,11,128,100);
	PA_3DSetSpritePrio(11,2041);
	
	// Affichage du numero de page
	u16 haut_gfx = PA_3DCreateTex((void*)hautListeCarte_Texture,128,8,TEX_4COL);
	PA_Load3DSpritePal(12, (void*)hautListeCarte_Pal);
	PA_3DCreateSpriteFromTex(12,haut_gfx,128,6,12,128,25);
	PA_3DSetSpritePrio(12,2043);
	PA_3DSetSpriteFrame(12,0);
	
	// Affichage de la fenetre de confirmation
	u16 fenetre3D_gfx = PA_3DCreateTex((void*)fenetre3D_Texture,128,64,TEX_256COL);
	PA_Load3DSpritePal(15, (void*)fenetre3D_Pal);
	PA_3DCreateSpriteFromTex(15,fenetre3D_gfx,128,64,15,128,288);
	PA_3DSetSpritePrio(15,2046);
	
	// Affichage du haut de page
	u16 haut3D_gfx = PA_3DCreateTex((void*)hautFenetre3D_Texture,128,8,TEX_4COL);
	PA_3DCreateSpriteFromTex(16,haut3D_gfx,128,6,12,128,259);
	PA_3DSetSpritePrio(16,2047);
	PA_3DSetSpriteFrame(16,0);
	
	// Liste des cartes : 70,28,190,172
	
	bool cinqCartes = false;
	bool fini = false;
	bool multipage = false;
	bool majListe = true;
	bool ajouterCarte[5] = {false,false,false,false,false};
	bool enleverCarte[5] = {false,false,false,false,false};
	int cartesChoisies[5];
	int afficherPageSuivante = 0;
	int page=0;
	int positionCurseur = 0;
	int carte=0;
	int vitesse[5];
	int yActuel[5],yFinal[5];
	
	int i,indice=0;
	int x;
	int timer=0;
	
	distanceArretCarte = 0;
	for (i=1;i<vitesseAfficherCarte;i++) {
		distanceArretCarte += i;
	}
	
	yInitCarte = 40-distanceArretCarte;
	if (yInitCarte > -25) {
		yInitCarte = -25;
	}
	
	
	char affichage[16];
	int couleur;
	
	int nombreCartes = getNombreCarte(0,1,10);
	int carteDispoInit[111][2];
	int carteDispo[111][2];
	int nombrePage = (nombreCartes-1)/11;
	
	for (i=1;i<=110;i++) {
		if (collection[i] > 0) {
			carteDispoInit[indice][0] = i;
			carteDispoInit[indice][1] = collection[i];
			carteDispo[indice][0] = i;
			carteDispo[indice][1] = collection[i];
			indice++;
		}
	}

	if (nombreCartes > 11) {	// Affichage des flèches et utilisation du mode multi-page
		PA_Load3DSpritePal(13, (void*)flecheMenu_Pal);
		PA_3DCreateSprite(13,(void*)flecheMenu_Texture,8,8,TEX_4COL,13,69,161);
		PA_3DCreateSprite(14,(void*)flecheMenu_Texture,8,8,TEX_4COL,13,186,161);
		PA_3DStartSpriteAnim(13,0,1,6);
		PA_3DStartSpriteAnim(14,2,3,6);
		PA_3DSetSpritePrio(13,2044);
		PA_3DSetSpritePrio(14,2045);
		multipage = true;
	}
	
	// Chargement des 5 cartes...
	for (i=0;i<5;i++) {
		yFinal[i] = 40+25*i;
		yActuel[i] = yInitCarte;
		vitesse[i] = vitesseAfficherCarte;
		PA_3DSetSpriteY(i+5,yInitCarte);
		PA_3DSetSpritePrio(i+5, 1024+100*i);
		if (wifiOn) {		// Si on est en mode Wifi
			enleverCarteWifi[i] = false;
			ajouterCarteWifi[i] = false;
			yActuelWifi[i] = yInitCarte;
			yFinalWifi[i] = 40+25*i;
			vitesseWifi[i] = vitesseAfficherCarte;
			PA_3DSetSpritePrio(i, 1024+100*i);
		}
	}
	
	PA_3DSetSpriteXY(10,58,37);
	
	majCarteG(1,carteDispo[positionCurseur+11*page][0]);
	
	while (1) {
		if (Pad.Newpress.Down || Pad.Newpress.Up) {
			positionCurseur += Pad.Newpress.Down - Pad.Newpress.Up;
			if (positionCurseur == -1) {
				positionCurseur = (page == nombrePage) ? (nombreCartes-1)%11 : 10;
			}
			else if ((positionCurseur == 11) || ((page == nombrePage) && (positionCurseur == (nombreCartes%11)))) {
				positionCurseur = 0;
			}
			PA_3DSetSpriteY(10,37+12*positionCurseur);
			AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
			
			timer = 0;
			majCarteG(1,carteDispo[positionCurseur+11*page][0]);
		}
		if (Pad.Held.Down || Pad.Held.Up) {
			if (timer == timerCurseur1) {
				positionCurseur += Pad.Held.Down - Pad.Held.Up;
				if (positionCurseur == -1) {
					positionCurseur = (page == nombrePage) ? (nombreCartes-1)%11 : 10;
				}
				else if ((positionCurseur == 11) || ((page == nombrePage) && (positionCurseur == (nombreCartes%11)))) {
					positionCurseur = 0;
				}
				PA_3DSetSpriteY(10,37+12*positionCurseur);
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				timer -= timerCurseur2;
				majCarteG(1,carteDispo[positionCurseur+11*page][0]);
			}
			else {
				timer++;
			}
		}
		
		else if (multipage) {
			if (Pad.Newpress.R || Pad.Held.Right) {
				page++;
				if (page > nombrePage) {
					page = 0;
				}
				else if (page == nombrePage) {
					if (positionCurseur > ((nombreCartes-1)%11)) {
						positionCurseur = (nombreCartes-1)%11;
						PA_3DSetSpriteY(10,37+12*positionCurseur);
					}
				}
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				afficherPageSuivante = 1;
				majCarteG(1,carteDispo[positionCurseur+11*page][0]);
			}
			
			else if (Pad.Newpress.L || Pad.Held.Left) {
				page--;
				if (page == -1) {
					page = nombrePage;
					if (positionCurseur > ((nombreCartes-1)%11)) {
						positionCurseur = (nombreCartes-1)%11;
						PA_3DSetSpriteY(10,37+12*positionCurseur);
					}
				}
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				afficherPageSuivante = -1;
				majCarteG(1,carteDispo[positionCurseur+11*page][0]);
			}
		}
		
		if ((Pad.Newpress.A) && (!enleverCarte[carte] || (carte == 5))) {
			if (cinqCartes) {
				fini = true;
			}
			else if ((carteDispo[positionCurseur+11*page][1] > 0) && (carte < 5))  {				
				cartesChoisies[carte] = positionCurseur+11*page;
				loadCarteMem(carte+5,0,0,carteDispo[positionCurseur+11*page][0]);
				loadCarte3D(false,carte+5,0,1,carte+5,0,0);
				//loadCarte3D(false,carte+5,0,1,carteDispo[positionCurseur+11*page][0]+1,0,0);
				carteDispo[positionCurseur+11*page][1]--;
				ajouterCarte[carte] = true;
				majListe = true;
				AS_SoundDefaultPlay((void*)bruitCarte,8576,127,64,0,0);
				if (wifiOn) {		// Si on est en multijoueur
					char envoi[6];
					sprintf(envoi,"%d ",carteDispo[positionCurseur+11*page][0]);
					envoiWifi(false,0x0007,envoi,3);
					IPC_WaitForAllSent();
				}
				carte++;
			}
			else {
				AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
			}
		}
		else if (Pad.Newpress.B && (carte > 0)) {
			if (cinqCartes) {
				cinqCartes = false;
			}
			carte--;
			carteDispo[cartesChoisies[carte]][1]++;
			enleverCarte[carte] = true;
			majListe = true;
			AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
			if (wifiOn) {		// Si on est en multijoueur
				envoiWifi(false,0x0007,"",1);
				IPC_WaitForAllSent();
			}
		}
		if (Stylus.Newpress || Stylus.Held) {
			for (i=0;i<11;i++) {
				if (PA_StylusInZone(68,28+12*i,182,40+12*i) && ((((nombreCartes-1)%11) > i-1) || (page < nombrePage))) {
					positionCurseur = i;
					PA_3DSetSpriteY(10,37+12*positionCurseur);
					majCarteG(1,carteDispo[positionCurseur+11*page][0]);
					break;
				}
			}
			if (multipage) {
				if (PA_StylusInZone(64,160,69,167)) {
					page--;
					if (page == -1) {
						page = nombrePage;
						if (positionCurseur > ((nombreCartes-1)%11)) {
							positionCurseur = (nombreCartes-1)%11;
							PA_3DSetSpriteY(10,37+12*positionCurseur);
						}
					}
					afficherPageSuivante = -1;
					majCarteG(1,carteDispo[positionCurseur+11*page][0]);
				}
				else if (PA_StylusInZone(187,160,192,167)) {
					page++;
					if (page > nombrePage) {
						page = 0;
					}
					else if (page == nombrePage) {
						if (positionCurseur > ((nombreCartes-1)%11)) {
							positionCurseur = (nombreCartes-1)%11;
							PA_3DSetSpriteY(10,37+12*positionCurseur);
						}
					}
					afficherPageSuivante = 1;
					majCarteG(1,carteDispo[positionCurseur+11*page][0]);
				}
			}
		}
		if (Stylus.Released) {
			if (PA_StylusInZone(206,14,256,164) && (carte > 0)) {
				if (cinqCartes) {
					cinqCartes = false;
				}
				carte--;
				carteDispo[cartesChoisies[carte]][1]++;
				enleverCarte[carte] = true;
				majListe = true;
				AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
				if (wifiOn) {		// Si on est en multijoueur
					envoiWifi(false,0x0007,"",1);
					IPC_WaitForAllSent();
				}
			}
			else if (((PA_StylusInZone(68,28,182,160) && (page < nombrePage)) || (PA_StylusInZone(68,28,182,40+12*((nombreCartes-1)%11)))) && (!enleverCarte[carte] || (carte == 5))) { // && ((((nombreCartes-1)%11) > i-1) || (page < nombrePage)) && (!enleverCarte[carte] || (carte == 5))) {
				if (cinqCartes) {
					fini = true;
				}
				else if ((carteDispo[positionCurseur+11*page][1] > 0) && (carte < 5))  {
					cartesChoisies[carte] = positionCurseur+11*page;
					loadCarteMem(carte+5,0,0,carteDispo[positionCurseur+11*page][0]);
					loadCarte3D(false,carte+5,0,1,carte+5,0,0);
					carteDispo[positionCurseur+11*page][1]--;
					ajouterCarte[carte] = true;
					majListe = true;
					AS_SoundDefaultPlay((void*)bruitCarte,8576,127,64,0,0);
					if (wifiOn) {		// Si on est en multijoueur
						char envoi[6];
						sprintf(envoi,"%d ",carteDispo[positionCurseur+11*page][0]);
						envoiWifi(false,0x0007,envoi,3);
						//IPC_WaitForAllSent();
					}
					carte++;
				}
				else {
					AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
				}
			}
		}
		for (i=0;i<5;i++) {
			if (enleverCarte[i]) {
				ajouterCarte[i] = false;
				vitesse[i]++;
				yActuel[i] -= vitesse[i];
				if (yActuel[i] <= yInitCarte) {
					yActuel[i] = yInitCarte;
					vitesse[i] = vitesseAfficherCarte;
					enleverCarte[i] = false;
				}
				PA_3DSetSpriteY(i+5,yActuel[i]);
			}
			else if (ajouterCarte[i]) {
				if ((yActuel[i]+distanceArretCarte > yFinal[i]) && (vitesse[i] > 0)) {
					vitesse[i]--;
				}
				yActuel[i] += vitesse[i];
				if (yActuel[i] >= yFinal[i]) {
					yActuel[i] = yFinal[i];
					vitesse[i] = 0;
					ajouterCarte[i] = false;
					//AS_SoundDefaultPlay((void*)bruitCarte,8576,127,64,0,0);
					if (i == 4) {
						cinqCartes = true;
						fini = true;
					}
				}
				PA_3DSetSpriteY(i+5,yActuel[i]);
			}
		}
		
		if (fini) {
			if (afficherFenetre3D(1,message[lang][25])) {
				break;
			}
			else {
				majListe = true;
				fini = false;
				PA_3DSetSpriteXY(10,58,37+12*positionCurseur);
			}
		}
		if (majListe) {
			PA_16cClearZone(0,70,28,185,172);
			for (i=0;i<11;i++) {
				if (i+11*page < nombreCartes) {
					PA_16cTextAlign(ALIGN_LEFT);
					sprintf(affichage,"%s",nomCarte[lang][carteDispo[i+11*page][0]]);
					couleur = (carteDispo[i+11*page][1] == 0) ? 3 : 1;
					PA_16cText(0,70,28+12*i,184,172,affichage,couleur,5,16);
					
					PA_16cTextAlign(ALIGN_RIGHT);
					sprintf(affichage,"%d",carteDispo[i+11*page][1]);
					couleur = (carteDispo[i+11*page][1] == 0) ? 3 : 1;
					PA_16cText(0,70,28+12*i,184,172,affichage,couleur,5,3);
				}
			}
			majListe = false;
		}
		if (afficherPageSuivante != 0) {
			x=0;
			PA_3DSetSpriteFrame(12,page);
			PA_3DCreateSpriteFromTex(17,fenetre_gfx,128,156,11,128,100);
			PA_3DSetSpritePrio(17,2042);
			if (afficherPageSuivante == 1) {	// Page suivante
				PA_3DSetSpriteTopRight(17,-1,0);
				PA_3DSetSpriteBottomRight(17,-1,0);
				PA_3DSetSpriteTopLeft(17,128,0);
				PA_3DSetSpriteBottomLeft(17,128,0);
				while (x < 128) {
					x += ((128-x)/2)+1;
					if (x > 128) {
						x = 128;
					}
					PA_3DSetSpriteTopLeft(17,128-x,0);
					PA_3DSetSpriteBottomLeft(17,128-x,0);
					PA_16cClearZone(0,192-x,0,256,192);
					
					// On affiche la page suivante...
					for (i=0;i<11;i++) {
						if (i+11*page < nombreCartes) {
							PA_16cTextAlign(ALIGN_LEFT);
							sprintf(affichage,"%s",nomCarte[lang][carteDispo[i+11*page][0]]);
							couleur = (carteDispo[i+11*page][1] == 0) ? 3 : 1;
							PA_16cText(0,198-x,28+12*i,312-x,172,affichage,couleur,5,16);
							
							PA_16cTextAlign(ALIGN_RIGHT);
							sprintf(affichage,"%d",carteDispo[i+11*page][1]);
							couleur = (carteDispo[i+11*page][1] == 0) ? 3 : 1;
							PA_16cText(0,198-x,28+12*i,312-x,172,affichage,couleur,5,3);
						}
					}
					// Qu'on coupe pour pas qu'elle dépasse :)
					PA_16cClearZone(0,191,0,256,192);
					
					PA_CheckLid();
					PA_3DProcess();
					PA_WaitForVBL();
				}
			}
			else {		// Page précédente
				PA_3DSetSpriteTopRight(17,-127,0);
				PA_3DSetSpriteBottomRight(17,-127,0);
				while (x < 128) {
					x += ((128-x)/2)+1;
					if (x > 128) {
						x = 128;
					}
					PA_3DSetSpriteTopRight(17,x-129,0);
					PA_3DSetSpriteBottomRight(17,x-129,0);
					
					PA_16cClearZone(0,0,0,64+x,192);
					
					// On affiche la page suivante...
					for (i=0;i<11;i++) {
						if (i+11*page < nombreCartes) {
							PA_16cTextAlign(ALIGN_LEFT);
							sprintf(affichage,"%s",nomCarte[lang][carteDispo[i+11*page][0]]);
							couleur = (carteDispo[i+11*page][1] == 0) ? 3 : 1;
							PA_16cText(0,x-58,28+12*i,56+x,172,affichage,couleur,5,16);
							
							PA_16cTextAlign(ALIGN_RIGHT);
							sprintf(affichage,"%d",carteDispo[i+11*page][1]);
							couleur = (carteDispo[i+11*page][1] == 0) ? 3 : 1;
							PA_16cText(0,x-58,28+12*i,56+x,172,affichage,couleur,5,3);
						}
					}
					// Qu'on coupe pour pas qu'elle dépasse :)
					PA_16cClearZone(0,0,0,65,192);
					
					PA_CheckLid();
					PA_3DProcess();
					PA_WaitForVBL();
				}
			}
			PA_3DDeleteSprite(17);
			afficherPageSuivante = 0;
			PA_WaitForVBL();
		}
		
		if (wifiOn) {
			afficherCarteAdv();
		}
		
		PA_CheckLid();
		PA_3DProcess();
		PA_WaitForVBL();
	}
	
	for (i=0;i<5;i++) {
		mainJoueur1[1][i] = carteDispo[cartesChoisies[i]][0];
	}
	
	if (multipage) {
		PA_3DDeleteSprite(13);
		PA_3DDeleteSprite(14);
		PA_3DSpriteAnimPause(13,1);
		PA_3DSpriteAnimPause(14,1);
		PA_3DSetSpriteFrame(13,0);
		PA_3DSetSpriteFrame(14,0);
	}
	
	PA_3DDeleteSprite(11);
	PA_3DDeleteSprite(12);
	PA_3DDeleteSprite(15);
	PA_3DDeleteSprite(16);
	PA_16cErase(0);
	PA_3DSetSpriteY(10,256);
}

void initPartie() {

	int i,j;
	
	u16 curseur_gfx = PA_3DCreateTex((void*)curseur3D_Texture, 32, 16, TEX_16COL);
	PA_Load3DSpritePal(10, (void*)curseur3D_Pal);
	PA_3DCreateSpriteFromTex(10,curseur_gfx,20,12,10,266,198);
	PA_3DSetSpritePrio(10,2048);
	
	// On initialise les mains
	for (i=0;i<5;i++) {
		for (j=0;j<2;j++) {
			mainJoueur1[j][i] = 0;
			cartePrise[j][i] = false;
			idCarteInit[5*j+i] = 5*j+i;
		}
	}
	
	// Et les éléments
	for (i=0;i<5;i++) {
		for (j=0;j<5;j++) {
			elementPlateau[i][j] = 0;
		}
	}
	
	// Chargement des cartes
	for (i=0;i<10;i++) {
		loadCarteMem(i,0,0,0);
		loadCarte3D(true,i,0,0,0,25+(i/5)*206,-152+25*(i%5));
		PA_3DSetSpritePolyID(i,i);
	}
	loadCarteMem(10,0,0,0);
	
	playMusic("boogie");
}

void initPartieSolo(int adversaire) {
	
	// On joue la musique
	// QUAND ELLE SERA PRETE... T_T

	int i,j;
	int tour;
	int zonePlateau = 0;
	scoreJoueur = 5;
	
	PA_Init3D();
	PA_Reset3DSprites();
	PA_SetBgPrio(0,0,2);
	PA_Init16bitBg(0,3);
	PA_Init16cBg(0,1);
	PA_LoadPal16(PAL_BG0,0,(void*)text_Pal);

	// Reglage de la luminosité
	loadBg(0,"plateau",false);
	loadBg(1,"backVS",false);
	
	initPartie();
	
	fadeBlack(1,true,true,false,1);
	
	// On affiche l'écran du haut...
	
	PA_16cTextAlign(ALIGN_LEFT);
	PA_16cText(1,8,2,256,192,message[lang][24],1,2,8);
	
	int ligne = majRegles(regleAdv[adversaire]);

	ligne += 2;
	char regleAffiche[32];
	sprintf(regleAffiche,"%s %s",message[lang][33],nomRegleVainqueur[lang][regleAdv[adversaire][8]]);
	PA_16cText(1,8,10*ligne,256,192,regleAffiche,1,2,strlen(regleAffiche));
	
	PA_LoadSpritePal(1,2,(void*)chiffre_Pal);
	
	PA_LoadSpritePal(1,0,(void*)perso_Pal[adversaire+1]);
	PA_CreateSprite(1,0,(void*)perso_Sprite[adversaire+1][0],OBJ_SIZE_32X64,1,0,-32,64);
	PA_CreateSprite(1,1,(void*)perso_Sprite[adversaire+1][1],OBJ_SIZE_64X64,1,0,-96,64);
	PA_CreateSprite(1,2,(void*)perso_Sprite[adversaire+1][2],OBJ_SIZE_32X64,1,0,-32,128);
	PA_CreateSprite(1,3,(void*)perso_Sprite[adversaire+1][3],OBJ_SIZE_64X64,1,0,-96,128);
	PA_SetSpriteHflip(1,0,1);
	PA_SetSpriteHflip(1,1,1);
	PA_SetSpriteHflip(1,2,1);
	PA_SetSpriteHflip(1,3,1);
	PA_CreateSprite(1,4,(void*)chiffre_Sprite,OBJ_SIZE_32X32,1,2,1,159);
	PA_SetSpriteAnim(1,4,5);

	
	PA_LoadSpritePal(1,1,(void*)perso_Pal[0]);
	PA_CreateSprite(1,5,(void*)perso_Sprite[0][0],OBJ_SIZE_32X64,1,1,256,64);
	PA_CreateSprite(1,6,(void*)perso_Sprite[0][1],OBJ_SIZE_64X64,1,1,288,64);
	PA_CreateSprite(1,7,(void*)perso_Sprite[0][2],OBJ_SIZE_32X64,1,1,256,128);
	PA_CreateSprite(1,8,(void*)perso_Sprite[0][3],OBJ_SIZE_64X64,1,1,288,128);
	PA_CreateSprite(1,9,(void*)chiffre_Sprite,OBJ_SIZE_32X32,1,2,233,159);
	PA_SetSpriteAnim(1,9,5);
	
	PA_LoadSpritePal(1,3,(void*)carteG_Pal[0][0]);
	carteG_gfx = PA_CreateGfx(1,(void*)carteG_Sprite[0][0],OBJ_SIZE_64X64,1);
	PA_CreateSpriteFromGfx(1,10,carteG_gfx,OBJ_SIZE_64X64,1,3,97,192);
	//PA_CreateSprite(1,10,(void*)carteG_Sprite[0][0],OBJ_SIZE_64X64,1,3,97,192);
	PA_CreateSprite(1,11,(void*)chiffre_Sprite,OBJ_SIZE_32X32,1,2,117,253);
	PA_SetSpriteAnim(1,11,11);
	
	PA_WaitForVBL();
	
	while (PA_GetSpriteX(1,1) != 0) {
		for (i=0;i<5;i++) {
			PA_SetSpriteX(1,i,PA_GetSpriteX(1,i)+vitessePerso);
			PA_SetSpriteX(1,i+5,PA_GetSpriteX(1,i+5)-vitessePerso);
		}
		for (i=10;i<12;i++) {
			PA_SetSpriteY(1,i,PA_GetSpriteY(1,i)-vitessePerso);
		}
		PA_CheckLid();
		PA_WaitForVBL();
	}
	
	initMainAleatoire(adversaire);

	afficherCartes(0);
	
	if (regleAdv[adversaire][2]) {	// Aléatoire
		initMainAleatoire(12);
		afficherCartes(1);
	}
	else {
		initChoixCarte();
	}
	
	// On copie les cartes dans la 2eme main
	for (i=0;i<5;i++) {
		mainJoueur2[0][i] = mainJoueur1[0][i];
		mainJoueur2[1][i] = mainJoueur1[1][i];
	}
	
	if (regleAdv[adversaire][7]) {	// Elémentaire
		
		// On affiche le background pour les elements
		PA_Load3DSpritePal(13,(void*)elementBg_Pal);
		u16 elementBg_gfx = PA_3DCreateTex((void*)elementBg_Texture,128,128,TEX_256COL);
		PA_3DCreateSpriteFromTex(21,elementBg_gfx,128,128,13,128,89);
		PA_3DSetSpritePrio(21,512);
		PA_3DSetSpriteAlpha(21,16);
		PA_3DSetSpritePolyID(21,11);
		
		// On charge la palette... numero 12
		PA_Load3DSpritePal(12,(void*)element_Pal);
		initElements();
	}
	
	if (regleAdv[adversaire][0]) {	// Open
		initRetournerCartes();
	}

	int tourJoueur = PA_RandMax(1);
	
	PA_Load3DSpritePal(11,(void*)fleche_Pal);
	
	// Charger la fleche
	u16 fleche_gfx = PA_3DCreateTex((void*)fleche_Texture,16,16,TEX_4COL);
	PA_3DCreateSpriteFromTex(11,fleche_gfx,16,16,11,128,89);
	PA_3DSetSpritePrio(11,2000);
	
	int rot=0;
	int rotTotal=0;
	int rotationFleche=0;
	int rotMax = tourFleche*512+(384-256*tourJoueur);
	int vitesseRotation = vitesseRotationFleche;
	int distanceArret = 0;
	
	for (i=1;i<=vitesseRotation;i++) {
		distanceArret += i;
	}
	
	PA_3DProcess();
	PA_WaitForVBL();
	
	// On fait tourner la fleche !
	
	AS_SoundDefaultPlay((void*)flecheRot,86656,127,64,0,0);
	
	while ((rotationFleche < tourFleche) || (rot >= 384-256*tourJoueur)) {
		if ((rotTotal+distanceArret > rotMax) && (vitesseRotation > 1)) {
			vitesseRotation--;
		}
		rot -= vitesseRotation;
		rotTotal += vitesseRotation;
		if (rot < 0) {
			rot += 512;
			rotationFleche++;
		}
		PA_3DSetSpriteRotate(11,rot);
		
		PA_CheckLid();
		PA_3DProcess();
		PA_WaitForVBL();
	}
	PA_3DSetSpriteRotate(11,384-256*tourJoueur);
	
	// On attend une demie seconde...
	for (i=0;i<30;i++) {
		PA_CheckLid();
		PA_3DProcess();
		PA_WaitForVBL();
	}
	
	// Et on affiche la flèche où il faut
	PA_3DSetSpriteRotate(11,0);
	
	int xFlecheInit = 128;
	int yFlecheInit = 89;
	int xFlecheFinal = 25+206*tourJoueur;
	int yFlecheFinal = 7;
	int xFlecheFrame = xFlecheFinal-xFlecheInit;
	int yFlecheFrame = yFlecheFinal-yFlecheInit;
	
	AS_SoundDefaultPlay((void*)fleche,31616,127,64,0,0);
	
	for (i=3;i>0;i--) {
		PA_3DSetSpriteXY(11,xFlecheInit+xFlecheFrame/i,yFlecheInit+yFlecheFrame/i);
		PA_CheckLid();
		PA_3DProcess();
		PA_WaitForVBL();
	}
	PA_3DStartSpriteAnimEx(11,0,6,10,ANIM_UPDOWN,-1);
	
	bool zonePlateauBool[9];
	
	do {
		PA_Load3DSpritePal(14,(void*)regleAffiche_Pal);
		u16 regleAffiche_gfx;
		if (lang == 1) {
			regleAffiche_gfx = PA_3DCreateTex((void*)regleAffiche1_Texture,256,64,TEX_256COL);
		}
		else {
			regleAffiche_gfx = PA_3DCreateTex((void*)regleAffiche0_Texture,256,64,TEX_256COL);
		}
		PA_3DCreateSpriteFromTex(31,regleAffiche_gfx,256,42,14,384,96);
		PA_3DSetSpriteFrame(31,0);
		PA_3DSetSpritePrio(31,2010);
		PA_3DSetSpritePolyID(31,10);
		
		brille_gfx = PA_3DCreateTex((void*)carteBrille_Texture,64,64,TEX_4COL);
		
		tour = 0;
		for (i=0;i<5;i++) {
			for (j=0;j<5;j++) {
				plateau[i][j] = 0;
				idCarte[i][j] = -1;
				plateauJoueur[i][j] = -1;
				bonusCase[i][j] = 0;
			}
			for (j=0;j<2;j++) {
				carteJouee[j][i] = false;
			}
		}
		
		PA_3DSetSpriteX(11,25+206*tourJoueur);
		PA_3DSpriteAnimPause(11,0);
		
		while (tour < 9) {
			
			if (tourJoueur) {
				zonePlateau = initTourJoueur();
			}
			else {
				zonePlateau = initTourAdversaire(adversaire,tour);
			}
			for (i=0;i<9;i++) {
				zonePlateauBool[i] = false;
			}
			zonePlateauBool[zonePlateau] = true;
			
			initAppliquerRegles(regleAdv[adversaire],zonePlateauBool);
			tourJoueur = !tourJoueur;
			tour++;
			
			if (tour < 9) {
				initDeplacerFleche(tourJoueur);
			}
		}
		
		initFinPartie(adversaire);
	}
	while ((scoreJoueur == 5) && regleAdv[adversaire][1]);
	
	fadeBlack(1,true,true,true,0);
	AS_MP3Stop();
	PA_WaitForVBL();
	AS_SetMP3Volume(127);
	
	retour2D();
}

void initPartieWifi(bool leader) {
	int i,j;

	initPartie();
	
	scoreJoueur = 5;
	PA_SetSpriteAnim(1,4,5);
	PA_SetSpriteAnim(1,9,5);
	
	attenteWifi();
		
	if (leader) {
		tourWifi = PA_RandMax(1);
		envoiWifi(true,0x0004,"",101-tourWifi);
	}
	
	attenteWifi();
	
	if (regleWifi[2]) {		// Aléatoire
		initMainAleatoire(12);
		attenteWifi();
		afficherCartes(2);
	}
	else {
		choixCarteWifi = true;
		nombreCarteAfficheWifi = 0;
		initChoixCarte();
		PA_3DProcess();
		
		attenteWifi();
		
		for (i=0;i<5;i++) {
			loadCarteMem(i,0,0,mainJoueur1[0][i]);
		}
	}
	
	attenteWifi();
	
	choixCarteWifi = false;
	
	if (regleWifi[7]) {	// Elémentaire
		// On affiche le background pour les elements
		PA_Load3DSpritePal(13,(void*)elementBg_Pal);
		u16 elementBg_gfx = PA_3DCreateTex((void*)elementBg_Texture,128,128,TEX_256COL);
		PA_3DCreateSpriteFromTex(21,elementBg_gfx,128,128,13,128,89);
		PA_3DSetSpritePrio(21,512);
		PA_3DSetSpriteAlpha(21,16);
		PA_3DSetSpritePolyID(21,11);
		
		// On charge la palette... numero 12
		PA_Load3DSpritePal(12,(void*)element_Pal);
		
		attenteWifi();
		
		if (leader) {
			initElements();
		}
		
		attenteWifi();
	}
	
	if (regleWifi[0]) {	// Open
		initRetournerCartes();
	}
	
	attenteWifi();
	
	PA_Load3DSpritePal(11,(void*)fleche_Pal);
	
	// Charger la fleche
	u16 fleche_gfx = PA_3DCreateTex((void*)fleche_Texture,16,16,TEX_4COL);
	PA_3DCreateSpriteFromTex(11,fleche_gfx,16,16,11,128,89);
	PA_3DSetSpritePrio(11,2000);
	
	int rot=0;
	int rotTotal=0;
	int rotationFleche=0;
	int rotMax = tourFleche*512+(384-256*tourWifi);
	int vitesseRotation = vitesseRotationFleche;
	int distanceArret = 0;
	
	for (i=1;i<=vitesseRotation;i++) {
		distanceArret += i;
	}
	
	PA_3DProcess();
	PA_WaitForVBL();
	
	// On fait tourner la fleche !
	
	AS_SoundDefaultPlay((void*)flecheRot,86656,127,64,0,0);
	
	while ((rotationFleche < tourFleche) || (rot >= 384-256*tourWifi)) {
		if ((rotTotal+distanceArret > rotMax) && (vitesseRotation > 1)) {
			vitesseRotation--;
		}
		rot -= vitesseRotation;
		rotTotal += vitesseRotation;
		if (rot < 0) {
			rot += 512;
			rotationFleche++;
		}
		PA_3DSetSpriteRotate(11,rot);
		
		PA_3DProcess();
		PA_WaitForVBL();
	}
	PA_3DSetSpriteRotate(11,384-256*tourWifi);
	
	// On attend une demie seconde...
	for (i=0;i<30;i++) {
		PA_3DProcess();
		PA_WaitForVBL();
	}
	
	// Et on affiche la flèche où il faut
	PA_3DSetSpriteRotate(11,0);
	
	int xFlecheInit = 128;
	int yFlecheInit = 89;
	int xFlecheFinal = 25+206*tourWifi;
	int yFlecheFinal = 7;
	int xFlecheFrame = xFlecheFinal-xFlecheInit;
	int yFlecheFrame = yFlecheFinal-yFlecheInit;
	
	AS_SoundDefaultPlay((void*)fleche,31616,127,64,0,0);
	
	for (i=3;i>0;i--) {
		PA_3DSetSpriteXY(11,xFlecheInit+xFlecheFrame/i,yFlecheInit+yFlecheFrame/i);
		PA_3DProcess();
		PA_WaitForVBL();
	}
	PA_3DStartSpriteAnimEx(11,0,6,10,ANIM_UPDOWN,-1);
	
	attenteWifi();
	
	bool zonePlateauBool[9];
	int tour;
	int etapeActuelle=etape;
	int zonePlateau;
	
	do {
		PA_Load3DSpritePal(14,(void*)regleAffiche_Pal);
		u16 regleAffiche_gfx;
		if (lang == 1) {
			regleAffiche_gfx = PA_3DCreateTex((void*)regleAffiche1_Texture,256,64,TEX_256COL);
		}
		else {
			regleAffiche_gfx = PA_3DCreateTex((void*)regleAffiche0_Texture,256,64,TEX_256COL);
		}
		PA_3DCreateSpriteFromTex(31,regleAffiche_gfx,256,42,14,384,96);
		PA_3DSetSpriteFrame(31,0);
		PA_3DSetSpritePrio(31,2010);
		PA_3DSetSpritePolyID(31,10);
		
		brille_gfx = PA_3DCreateTex((void*)carteBrille_Texture,64,64,TEX_4COL);
		
		carteJoueeWifi = false;
		etape = etapeActuelle;
		tour = 0;
		for (i=0;i<5;i++) {
			for (j=0;j<5;j++) {
				plateau[i][j] = 0;
				idCarte[i][j] = -1;
				plateauJoueur[i][j] = -1;
				bonusCase[i][j] = 0;
			}
			for (j=0;j<2;j++) {
				carteJouee[j][i] = false;
			}
		}
		
		PA_3DSetSpriteX(11,25+206*tourWifi);
		PA_3DSpriteAnimPause(11,0);
		
		attenteWifi();
		
		while (tour < 9) {
			
			if (tourWifi) {
				zonePlateau = initTourJoueur();
			}
			else {
				while (!carteJoueeWifi) {
					PA_3DProcess();
					PA_WaitForVBL();
				}
				zonePlateau = initTourAdversaireWifi();
				carteJoueeWifi = false;
			}
			for (i=0;i<9;i++) {
				zonePlateauBool[i] = false;
			}
			zonePlateauBool[zonePlateau] = true;
			
			initAppliquerRegles(regleWifi,zonePlateauBool);
			tourWifi = !tourWifi;
			tour++;
			
			if (tour < 9) {
				initDeplacerFleche(tourWifi);
			}
			
			attenteWifi();
		}
		
		initFinPartieWifi(leader);
		
		attenteWifi();
	}
	while ((scoreJoueur == 5) && regleWifi[1]);
}

void initJeuWifi(bool leader,int * reglePartieWifi) {

	int i,j;
	
	PA_16cErase(0);
	
	fadeBlack(1,true,false,true,0);
	
	AS_MP3Stop();
	PA_WaitForVBL();
	AS_SetMP3Volume(127);
	
	PA_Reset3DSprites();
	loadBg(0,"plateau",false);
	
	scoreWifi[0] = 0;
	scoreWifi[1] = 0;
	
	for (i=0;i<8;i++) {
		regleWifi[i] = reglePartieWifi[i];
	}
	
	majScoreWifi();
	
	fadeBlack(1,true,false,false,1);
	
	PA_LoadSpritePal(1,2,(void*)chiffre_Pal);
	
	PA_CreateSprite(1,4,(void*)chiffre_Sprite,OBJ_SIZE_32X32,1,2,1,159);
	PA_SetSpriteAnim(1,4,5);
	
	PA_CreateSprite(1,9,(void*)chiffre_Sprite,OBJ_SIZE_32X32,1,2,233,159);
	PA_SetSpriteAnim(1,9,5);
	
	PA_LoadSpritePal(1,3,(void*)carteG_Pal[0][0]);
	carteG_gfx = PA_CreateGfx(1,(void*)carteG_Sprite[0][0],OBJ_SIZE_64X64,1);
	PA_CreateSpriteFromGfx(1,10,carteG_gfx,OBJ_SIZE_64X64,1,3,97,192);
	//PA_CreateSprite(1,10,(void*)carteG_Sprite[0][0],OBJ_SIZE_64X64,1,3,97,192);
	PA_CreateSprite(1,11,(void*)chiffre_Sprite,OBJ_SIZE_32X32,1,2,117,253);
	PA_SetSpriteAnim(1,11,11);

	while (PA_GetSpriteY(1,10) != 96) {
		PA_SetSpriteX(1,4,PA_GetSpriteX(1,4)+vitessePerso);
		PA_SetSpriteX(1,9,PA_GetSpriteX(1,9)-vitessePerso);
		for (i=10;i<12;i++) {
			PA_SetSpriteY(1,i,PA_GetSpriteY(1,i)-vitessePerso);
		}
		PA_WaitForVBL();
	}
	
	PA_WaitForVBL();
	
	while (1) {
		etapeWifi = 0;
		etape = 0;
		initPartieWifi(leader);
		majScoreWifi();
		choixFinWifi = 4;
		
		u16 curseur_gfx = PA_3DCreateTex((void*)curseur3D_Texture, 32, 16, TEX_16COL);
		PA_Load3DSpritePal(10, (void*)curseur3D_Pal);
		PA_3DCreateSpriteFromTex(10,curseur_gfx,20,12,10,266,198);
		PA_3DSetSpritePrio(10,2048);
		
		// Affichage de la fenetre
		u16 fenetre_gfx = PA_3DCreateTex((void*)fenetreListeCarte_Texture,128,256,TEX_256COL);
		PA_Load3DSpritePal(17, (void*)fenetreListeCarte_Pal);
		PA_3DCreateSpriteFromTex(17,fenetre_gfx,128,156,17,128,292);
		PA_3DSetSpritePrio(17,2041);
		
		// Affichage du haut de page
		u16 haut_gfx = PA_3DCreateTex((void*)hautFenetre3D_Texture,128,8,TEX_4COL);
		PA_Load3DSpritePal(12, (void*)hautListeCarte_Pal);
		PA_3DCreateSpriteFromTex(18,haut_gfx,128,6,12,128,259);
		PA_3DSetSpritePrio(18,2047);
		PA_3DSetSpriteFrame(18,1);
		
		// Affichage de la fenetre de confirmation
		u16 fenetre3D_gfx = PA_3DCreateTex((void*)fenetre3D_Texture,128,64,TEX_256COL);
		PA_Load3DSpritePal(15, (void*)fenetre3D_Pal);
		PA_3DCreateSpriteFromTex(15,fenetre3D_gfx,128,64,15,128,288);
		PA_3DSetSpritePrio(15,2046);
		
		// Affichage du haut de page
		u16 haut3D_gfx = PA_3DCreateTex((void*)hautFenetre3D_Texture,128,8,TEX_4COL);
		PA_3DCreateSpriteFromTex(16,haut3D_gfx,128,6,12,128,259);
		PA_3DSetSpritePrio(16,2047);
		PA_3DSetSpriteFrame(16,1);
		
		if (leader) {
			while (choixFinWifi > 0) {
				choixFinWifi = initChoixFinWifi();
				PA_16cErase(0);
				envoiWifi(true,0x0006,"",choixFinWifi);
				
				if (choixFinWifi == 1) {
					// On efface le perso adverse...
					for (j=0;j<=(128/vitessePerso);j++) {
						for (i=0;i<4;i++) {
							PA_SetSpriteX(1,i,PA_GetSpriteX(1,i)-vitessePerso);
						}
						
						PA_3DProcess();
						PA_WaitForVBL();
					}
					
					persoAdvWifi = -1;
					
					attenteWifi();
					
					PA_3DSetSpriteY(17,100);
					PA_3DSetSpriteY(18,25);
					
					initChoixPersoWifi(false,true,fenetre_gfx);
					
					PA_3DSetSpriteY(17,292);
					PA_3DSetSpriteY(18,217);
					PA_3DSetSpriteY(10,256);
					PA_16cErase(0);
					
					afficherStatus(1,message[lang][34]);
					
					attenteWifi();
					
					if (!initAttenteChoixPersoWifi()) {
						envoiWifi(true,0x0003,"",555);
						fadeBlack(1,true,true,false,0);
						return;
					}
				}
				else if (choixFinWifi == 2) {
					PA_3DSetSpriteY(17,100);
					PA_3DSetSpriteY(18,25);
					
					initChoixReglesWifi(true);
					
					PA_3DSetSpriteY(17,292);
					PA_3DSetSpriteY(18,217);
					PA_3DSetSpriteY(10,256);
					PA_16cErase(0);
				}
				else if (choixFinWifi == 3) {
					fadeBlack(1,true,true,true,0);
					AS_MP3Stop();
					PA_WaitForVBL();
					AS_SetMP3Volume(127);
					return;
				}
				
				attenteWifi();
			}
		}
		else {
			while (choixFinWifi > 0) {
				afficherStatus(1,message[lang][36]);
				choixFinWifi = 4;
				while (choixFinWifi == 4) {
					PA_3DProcess();
					PA_WaitForVBL();
				}
				if (choixFinWifi == 1) {		// Changer de perso
					// On efface le perso du joueur...
					for (j=0;j<=(128/vitessePerso);j++) {
						for (i=0;i<4;i++) {
							PA_SetSpriteX(1,i+5,PA_GetSpriteX(1,i+5)+vitessePerso);
						}
						
						PA_3DProcess();
						PA_WaitForVBL();
					}
					
					int oldPersoWifi = choixPersoWifi;
					choixPersoWifi = -1;
					
					attenteWifi();
					
					afficherStatus(1,message[lang][34]);
					
					if (!initAttenteChoixPersoWifi()) {
						envoiWifi(true,0x0003,"",555);
						fadeBlack(1,true,true,false,0);
						return;
					}
					
					PA_3DSetSpriteY(17,100);
					PA_3DSetSpriteY(18,25);
					
					choixPersoWifi = oldPersoWifi;
					
					attenteWifi();
					
					PA_WaitForVBL();PA_WaitForVBL();PA_WaitForVBL();PA_WaitForVBL();
					
					initChoixPersoWifi(true,true,fenetre_gfx);
					
					PA_3DSetSpriteY(17,292);
					PA_3DSetSpriteY(18,217);
					PA_3DSetSpriteY(10,256);
					PA_16cErase(0);
				}
				else if (choixFinWifi == 2) {
					afficherStatus(1,message[lang][35]);
				}
				else if (choixFinWifi == 3) {
					afficherFenetre3D(0,message[lang][37]);
					fadeBlack(1,true,true,true,0);
					AS_MP3Stop();
					PA_WaitForVBL();
					AS_SetMP3Volume(127);
					return;
				}
				attenteWifi();
			}
		}
		fadeBlack(1,true,false,true,0);
		
		AS_MP3Stop();
		PA_WaitForVBL();
		AS_SetMP3Volume(127);
		
		PA_16cErase(0);
		PA_Reset3DSprites();
		PA_3DProcess();
		PA_WaitForVBL();
		fadeBlack(1,true,false,false,1);
	}
}

bool initWifiCreer(u16 fenetre_gfx) {
	int i,j;
	int retour=0;
	bool returnVal=true;
	bool changerPerso = true;
	char roomName[20];
	
	persoAdvWifi=-1;
	
	// Affichage de la fenetre
	PA_3DSetSpriteY(1,100);
	PA_3DSetSpriteY(2,25);
	
	do {
		// Selection du personnage
		if (!initChoixPersoWifi(changerPerso,false,fenetre_gfx)) {
			retour = 1;
			break;
		}
		changerPerso = (choixPersoWifi == 14);
		PA_3DProcess();
		PA_WaitForVBL();
	}
	while (!initChoixReglesWifi(false));		// Choix des règles
	
	PA_3DSetSpriteY(1,292);
	PA_3DSetSpriteY(2,217);
	PA_3DSetSpriteY(10,256);
	PA_16cErase(0);
	
	if (retour == 0) {
		// On dit par wifi qu'on est prêt
		sprintf(roomName,"%02d %01d %01d %01d %01d %01d %01d %01d %01d",choixPersoWifi,reglePerso[0],reglePerso[1],reglePerso[2],reglePerso[3],reglePerso[4],reglePerso[5],reglePerso[6],reglePerso[7]);
		LOBBY_CreateRoom(roomName,2,52863,1);
		LOBBY_SetRoomVisibility(1);
		
		// Affichage du texte dans la barre de status
		afficherStatus(1,message[lang][38]);
		
		afficherNomWifi(0);
		
		while (1) {
			if (LOBBY_GetUsercountInRoom(LOBBY_GetRoomByID(ROOMID_MYROOM)) == 2) {		// Si quelqu'un est entré dans la room
				afficherStatus(1,message[lang][39]);
				int nomWifiActuel=0;
				afficherNomWifiId=0;
				for (i=0;i<48;i++) {
					progressionWifi(nomWifiActuel);
					nomWifiActuel = afficherNomWifiId;
					LOBBY_SendToUser(LOBBY_GetRoomUserBySlot(LOBBY_GetRoomByID(ROOMID_MYROOM),1),0x0008,"",i);
					PA_WaitFor(nomWifiActuel != afficherNomWifiId);
				}
				progressionWifi(-1);
				afficherNomWifi(0);
				AS_SoundDefaultPlay((void*)nouvelleCarte,60672,127,64,0,0);
				
				PA_3DSetSpriteXY(10,24,52);
				
				afficherStatus(1,message[lang][40]);
				while (1) {
					if (LOBBY_GetUsercountInRoom(LOBBY_GetRoomByID(ROOMID_MYROOM)) == 1) {		// Si l'autre s'est barré...
						afficherFenetre3D(0,message[lang][42]);
						PA_16cErase(0);
						break;
					}
					if (Pad.Newpress.A || (Stylus.Released && PA_StylusInZone(36,24,132,72))) {
						AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
						if (afficherFenetre3D(1,message[lang][43])) {
							PA_3DSetSpriteY(10,256);
							
							envoiWifi(true,0x0003,"",21);
							PA_WaitForVBL();PA_WaitForVBL();PA_WaitForVBL();
							wifiOn = 1;
							persoAdvWifi=-1;
							
							// On pré-charge l'image du perso
							PA_CreateSprite(1,0,(void*)perso_Sprite[0][0],OBJ_SIZE_32X64,1,0,-32,64);
							PA_CreateSprite(1,1,(void*)perso_Sprite[0][1],OBJ_SIZE_64X64,1,0,-96,64);
							PA_CreateSprite(1,2,(void*)perso_Sprite[0][2],OBJ_SIZE_32X64,1,0,-32,128);
							PA_CreateSprite(1,3,(void*)perso_Sprite[0][3],OBJ_SIZE_64X64,1,0,-96,128);
							
							// Affichage du texte dans la barre de status
							afficherStatus(1,message[lang][44]);
							afficherNomWifi(0);
							
							attenteWifi();
							
							if (initAttenteChoixPersoWifi()) {
								PA_16cErase(0);
								initJeuWifi(true,reglePerso);
								returnVal = false;
								break;
							}
							else {
								envoiWifi(true,0x0003,"",0);
								retour = 2;
								break;
							}
						}
						afficherNomWifi(0);
						PA_3DSetSpriteXY(10,24,52);
					}
					else if (Pad.Newpress.B) {
						AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
						if (afficherFenetre3D(1,message[lang][45])) {
							envoiWifi(true,0x0003,"",20);
							PA_WaitForVBL();PA_WaitForVBL();PA_WaitForVBL();
							PA_16cClearZone(0,36,24,132,72);
							
							// Affichage du texte dans la barre de status
							afficherStatus(1,message[lang][38]);
							break;
						}
						afficherNomWifi(0);
						PA_3DSetSpriteXY(10,24,52);
					}
					
					PA_3DProcess();
					PA_WaitForVBL();
				}
				PA_3DSetSpriteY(10,256);
			}
			if (Pad.Newpress.B) {
				AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
				if (afficherFenetre3D(1,message[lang][46])) {
					retour = 1;
				}
				PA_3DSetSpriteY(10,256);
			}
			if (retour || !returnVal) {
				break;
			}
			PA_3DProcess();
			PA_WaitForVBL();
		}
		
		// On se tais en Wifi
		wifiOn = 0;
		LOBBY_SetRoomVisibility(0);
		LOBBY_LeaveRoom();
	}
	
	if (retour) {
		for (j=0;j<=(128/vitessePerso);j++) {
			if (retour == 2) {
				for (i=0;i<4;i++) {
					PA_SetSpriteX(1,i,PA_GetSpriteX(1,i)-vitessePerso);
				}
			}
			for (i=0;i<4;i++) {
				PA_SetSpriteX(1,i+5,PA_GetSpriteX(1,i+5)+vitessePerso);
			}
			
			PA_3DProcess();
			PA_WaitForVBL();
		}
		for (i=0;i<4;i++) {
			if (retour == 2) {
				PA_DeleteSprite(1,i);
			}
			PA_DeleteSprite(1,i+5);
		}
		PA_16cErase(1);
	}
	
	PA_3DProcess();
	PA_WaitForVBL();
	
	return returnVal;
}

bool initWifiRejoindre(u16 fenetre_gfx) {
	
	int i,j;
	int positionCurseur=0;
	int nombreRoomAffiche=0;
	int max;
	int retour=0;
	int nbFrame=0;
	int nombreRoomChecked=0;
	int reglesRoom[maxUserwifi][8];
	int persoRoom[maxUserwifi];
	int refRoomOk[maxUserwifi];
	bool multipage=false;
	bool effacementPerso=false;
	bool affichagePerso=false;
	
	afficherStatus(1,message[lang][47]);
	
	while (1) {
		max = LOBBY_GetNumberOfKnownRooms();
		for (i=nombreRoomChecked;i<max;i++) {
			if (LOBBY_GetRoomGameCode(LOBBY_GetRoomByID(i)) == 52863) {
				afficherStatus(1,message[lang][39]);
				sscanf(LOBBY_GetRoomName(LOBBY_GetRoomByID(i)),"%02d %01d %01d %01d %01d %01d %01d %01d %01d",&persoRoom[i],&reglesRoom[i][0],&reglesRoom[i][1],&reglesRoom[i][2],&reglesRoom[i][3],&reglesRoom[i][4],&reglesRoom[i][5],&reglesRoom[i][6],&reglesRoom[i][7]);
				refRoomOk[idUserWifi] = i;
				int nomWifiActuel=0;
				afficherNomWifiId=0;
				for (j=0;j<48;j++) {
					progressionWifi(nomWifiActuel);
					nomWifiActuel = afficherNomWifiId;
					LOBBY_SendToUser(LOBBY_GetRoomUserBySlot(LOBBY_GetRoomByID(i),0),0x0008,"",j);
					PA_WaitFor(nomWifiActuel != afficherNomWifiId);
				}
				progressionWifi(-1);
				idUserWifi++;
				AS_SoundDefaultPlay((void*)nouvelleCarte,60672,127,64,0,0);
			}
			nombreRoomChecked++;
		}
		
		// Si on a rien trouvé, bah on continu de chercher...
		if (idUserWifi > 0) {		// Si on a trouvé quelque chose...
			if (idUserWifi != nombreRoomAffiche) {		// Si on a un joueur en plus
				char affiche[64];
				if (nombreRoomAffiche == 0) {
					sprintf(affiche,"%s",message[lang][40]);
					afficherNomWifi(0);
					PA_3DSetSpriteXY(10,24,52);
					PA_16cTextAlign(ALIGN_LEFT);
					PA_16cText(1,8,2,256,192,message[lang][24],1,2,8);
					majRegles(reglesRoom[0]);
					effacementPerso = true;
				}
				else {
					sprintf(affiche,"%d %s",idUserWifi,message[lang][41]);
					if (!multipage) {
						PA_Load3DSpritePal(4, (void*)flecheMenu_Pal);
						PA_3DCreateSprite(3,(void*)flecheMenu_Texture,8,8,TEX_4COL,4,30,66);
						PA_3DCreateSprite(4,(void*)flecheMenu_Texture,8,8,TEX_4COL,4,138,66);
						PA_3DStartSpriteAnim(3,0,1,6);
						PA_3DStartSpriteAnim(4,2,3,6);
						PA_3DSetSpritePrio(3,2044);
						PA_3DSetSpritePrio(4,2045);
						PA_3DSetSpriteVisible(3,0);
						multipage = true;
					}
				}
				afficherStatus(1,affiche);
				nombreRoomAffiche = idUserWifi;
			}
			
			if (multipage) {
				// Navigation parmi les adversaires...
				if ((Pad.Newpress.Right || (Stylus.Held && PA_StylusInZone(139,65,144,72))) && (positionCurseur < idUserWifi-1)) {
					positionCurseur++;
					if (positionCurseur == idUserWifi-1) {
						PA_3DSetSpriteVisible(4,0);
					}
					if (positionCurseur == 1) {
						PA_3DSetSpriteVisible(3,1);
					}
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					afficherNomWifi(positionCurseur);
					majRegles(reglesRoom[positionCurseur]);
					effacementPerso = true;
				}
				if ((Pad.Newpress.Left || (Stylus.Held && PA_StylusInZone(25,65,30,72))) && (positionCurseur > 1)) {
					positionCurseur--;
					if (positionCurseur == 0) {
						PA_3DSetSpriteVisible(3,0);
					}
					if (positionCurseur == idUserWifi-2) {
						PA_3DSetSpriteVisible(4,1);
					}
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					afficherNomWifi(positionCurseur);
					majRegles(reglesRoom[positionCurseur]);
					effacementPerso = true;
				}
			}
			if (Pad.Newpress.A || (Stylus.Released && PA_StylusInZone(36,24,132,72))) {
				if (LOBBY_GetUsercountInRoom(LOBBY_GetRoomByID(refRoomOk[positionCurseur])) == 1) {
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					if (afficherFenetre3D(1,message[lang][49])) {
						afficherNomWifi(positionCurseur);
						PA_3DSetSpriteXY(10,24,52);
						afficherStatus(1,message[lang][50]);
						LOBBY_JoinRoom(LOBBY_GetRoomByID(refRoomOk[positionCurseur]));
						PA_WaitForVBL();PA_WaitForVBL();PA_WaitForVBL();
						
						while (!reponseWifi) {
							if (Pad.Newpress.B) {
								if (afficherFenetre3D(1,message[lang][48])) {
									LOBBY_LeaveRoom();
									PA_16cErase(0);
									break;
								}
								afficherNomWifi(positionCurseur);
								PA_3DSetSpriteXY(10,24,52);
							}
							PA_3DProcess();
							PA_WaitForVBL();
						}
						if (allowChoixPerso) {		// Si l'autre joueur a accepté...
							
							// Affichage de la fenetre
							PA_3DSetSpriteY(1,100);
							PA_3DSetSpriteY(2,25);
							
							persoAdvWifi = persoRoom[positionCurseur];
							
							attenteWifi();
							
							PA_WaitForVBL();PA_WaitForVBL();PA_WaitForVBL();PA_WaitForVBL();
							
							if (initChoixPersoWifi(true,true,fenetre_gfx)) {
								PA_16cErase(0);
								PA_3DSetSpriteY(1,292);
								PA_3DSetSpriteY(2,217);
								PA_3DSetSpriteY(10,256);
								PA_3DProcess();
								wifiOn = 2;
								initJeuWifi(false,reglesRoom[positionCurseur]);
								allowChoixPerso = false;
								reponseWifi = false;
								wifiOn = 0;
								LOBBY_LeaveRoom();
								return false;
							}
							allowChoixPerso = false;
							reponseWifi = false;
							wifiOn = 0;
							LOBBY_LeaveRoom();
						}
					}
				}
				else {
					AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
					afficherFenetre3D(0,message[lang][51]);
				}
				afficherNomWifi(positionCurseur);
				PA_3DSetSpriteXY(10,24,52);
			}
			else if (Pad.Newpress.B) {
				if (afficherFenetre3D(1,message[lang][22])) {
					retour = 2;
				}
				afficherNomWifi(positionCurseur);
				PA_3DSetSpriteXY(10,24,52);
			}
			if (effacementPerso) {
				if (nbFrame <= (128/vitessePerso)) {
					for (i=0;i<4;i++) {
						PA_SetSpriteX(1,i,PA_GetSpriteX(1,i)-vitessePerso);
					}
					nbFrame++;
				}
				else {
					for (i=0;i<4;i++) {
						PA_DeleteSprite(1,i);
					}
					PA_LoadSpritePal(1,0,(void*)perso_Pal[persoRoom[positionCurseur]]);
					PA_CreateSprite(1,0,(void*)perso_Sprite[persoRoom[positionCurseur]][0],OBJ_SIZE_32X64,1,0,-32,64);
					PA_CreateSprite(1,1,(void*)perso_Sprite[persoRoom[positionCurseur]][1],OBJ_SIZE_64X64,1,0,-96,64);
					PA_CreateSprite(1,2,(void*)perso_Sprite[persoRoom[positionCurseur]][2],OBJ_SIZE_32X64,1,0,-32,128);
					PA_CreateSprite(1,3,(void*)perso_Sprite[persoRoom[positionCurseur]][3],OBJ_SIZE_64X64,1,0,-96,128);
					PA_SetSpriteHflip(1,0,1);
					PA_SetSpriteHflip(1,1,1);
					PA_SetSpriteHflip(1,2,1);
					PA_SetSpriteHflip(1,3,1);
					affichagePerso = true;
					nbFrame=0;
					effacementPerso = false;
				}
			}
			if (affichagePerso) {
				for (i=0;i<4;i++) {
					PA_SetSpriteX(1,i,PA_GetSpriteX(1,i)+vitessePerso);
				}
				if (PA_GetSpriteX(1,1) == 0) {
					affichagePerso = false;
				}
			}
		}
		else if (Pad.Newpress.B) {
			if (afficherFenetre3D(1,message[lang][22])) {
				retour = 1;
			}
			PA_3DSetSpriteY(10,256);
		}
		if (retour) {
			if (retour == 2) {
				for (j=0;j<=(128/vitessePerso);j++) {
					for (i=0;i<4;i++) {
						PA_SetSpriteX(1,i,PA_GetSpriteX(1,i)-vitessePerso);
					}
					
					PA_3DProcess();
					PA_WaitForVBL();
				}
				for (i=0;i<4;i++) {
					PA_DeleteSprite(1,i);
				}
				PA_16cErase(1);
			}
			break;
		}
		PA_3DProcess();
		PA_WaitForVBL();
	}
	
	PA_3DProcess();
	PA_WaitForVBL();
	
	return true;
}

void afficherDecalageAventure(int sens) {
	int i,x=0;
	int vitesse=0;
	PA_SetSpriteX(0,0,256);
	while (x<256) {
		if (x < 128) {
			vitesse++;
		}
		else {
			vitesse--;
		}
		x += vitesse;
		for (i=4;i<19;i++) {
			PA_SetSpriteX(0,i,PA_GetSpriteX(0,i)-vitesse*sens);
		}
		PA_CheckLid();
		PA_WaitForVBL();
	}
}

void afficherInfosPerso(int adversaire) {
	int ligne=2;
	int i;
	bool aucune = true;
	
	PA_16cTextAlign(ALIGN_LEFT);
	PA_16cText(1,96,8,256,192,message[lang][24],1,2,8);
	
	for (i=0;i<8;i++) {
		if (regleAdv[adversaire][i]) {
			PA_16cText(1,112,10*(ligne++)-2,256,192,nomRegle[lang][i],1,2,strlen(nomRegle[lang][i]));
			aucune = false;
		}
	}
	if (aucune) {
		PA_16cText(1,112,10*(ligne++)-2,256,192,message[lang][17],1,2,6);
	}
	
	ligne++;
	
	PA_16cText(1,96,10*(ligne++)-2,256,192,message[lang][33],1,2,20);
	PA_16cText(1,112,10*ligne-2,256,192,nomRegleVainqueur[lang][regleAdv[adversaire][8]],1,2,strlen(nomRegleVainqueur[lang][regleAdv[adversaire][8]]));
	
	char victoireAffichage[16];
	
	sprintf(victoireAffichage,"%s : %d",message[lang][11],victoires[adversaire][0]);
	PA_16cText(1,121,154,256,192,victoireAffichage,1,2,16);
	
	sprintf(victoireAffichage,"%s : %d",message[lang][12],victoires[adversaire][1]);
	PA_16cText(1,125,164,256,192,victoireAffichage,1,2,16);
	
	sprintf(victoireAffichage,"%s : %d",message[lang][13],victoires[adversaire][2]);
	PA_16cText(1,127,174,256,192,victoireAffichage,1,2,16);
}

void initGameOver() {

	loadBg(0,"gameOver",false);
	
	playMusic("gameOver");
	
	fadeBlack(4,true,true,true,1);
	afficherFenetre(0,message[lang][52]);
	PA_WaitFor(Pad.Newpress.A || Pad.Newpress.B || Pad.Newpress.Start || Stylus.Newpress);
	fadeBlack(4,true,true,true,0);
	AS_MP3Stop();
	PA_WaitForVBL();
	AS_SetMP3Volume(127);
	
}

void initCredits() {
	
	int i;
	char nomFichier[16];
	
	PA_16cTextAlign(ALIGN_CENTER);
	PA_LoadPal16(PAL_SPRITE1,0,texteCredit_Pal);
	
	playMusic("jazz");
	
	PA_16cText(0,0,64,256,192,message[lang][53],1,5,128);
	loadBg(1,"creditPalib",false);
	
	if (lang == 1) {
		PA_CreateSprite(1,0,(void*)creditPalib10_Sprite,OBJ_SIZE_64X64,0,0,0,0);
		PA_CreateSprite(1,1,(void*)creditPalib11_Sprite,OBJ_SIZE_64X64,0,0,64,0);
		PA_CreateSprite(1,2,(void*)creditPalib12_Sprite,OBJ_SIZE_64X64,0,0,128,0);
		PA_CreateSprite(1,3,(void*)creditPalib13_Sprite,OBJ_SIZE_64X64,0,0,192,0);
	}
	else {
		PA_CreateSprite(1,0,(void*)creditPalib00_Sprite,OBJ_SIZE_64X64,0,0,0,0);
		PA_CreateSprite(1,1,(void*)creditPalib01_Sprite,OBJ_SIZE_64X64,0,0,64,0);
		PA_CreateSprite(1,2,(void*)creditPalib02_Sprite,OBJ_SIZE_64X64,0,0,128,0);
		PA_CreateSprite(1,3,(void*)creditPalib03_Sprite,OBJ_SIZE_64X64,0,0,192,0);
	}
	
	for (i=0;i<480;i++) {
		PA_CheckLid();
		PA_WaitForVBL();
	}
	
	fadeBlack(3,true,false,false,1);
	
	for (i=0;i<24;i++) {
		PA_CheckLid();
		PA_WaitForVBL();
	}
	
	fadeBlack(3,false,true,false,1);
	
	for (i=0;i<144;i++) {
		PA_CheckLid();
		PA_WaitForVBL();
	}
	
	fadeBlack(3,true,true,false,0);

	PA_16cErase(0);
	for (i=0;i<4;i++) {
		PA_DeleteSprite(1,i);
	}
	
	PA_16cText(0,0,64,256,192,message[lang][54],1,5,128);
	loadBg(1,"creditSquare",false);
	
	if (lang == 1) {
		PA_CreateSprite(1,0,(void*)creditSquare10_Sprite,OBJ_SIZE_64X64,0,0,64,0);
		PA_CreateSprite(1,1,(void*)creditSquare11_Sprite,OBJ_SIZE_64X64,0,0,128,0);
	}
	else {
		PA_CreateSprite(1,0,(void*)creditSquare00_Sprite,OBJ_SIZE_64X64,0,0,64,0);
		PA_CreateSprite(1,1,(void*)creditSquare01_Sprite,OBJ_SIZE_64X64,0,0,128,0);
	}
	
	for (i=0;i<24;i++) {
		PA_CheckLid();
		PA_WaitForVBL();
	}
	
	fadeBlack(3,true,false,false,1);
	
	for (i=0;i<24;i++) {
		PA_CheckLid();
		PA_WaitForVBL();
	}
	
	fadeBlack(3,false,true,false,1);
	
	for (i=0;i<144;i++) {
		PA_CheckLid();
		PA_WaitForVBL();
	}
	
	fadeBlack(3,true,true,false,0);

	PA_16cErase(0);
	for (i=0;i<4;i++) {
		PA_DeleteSprite(1,i);
	}
	
	PA_16cText(0,0,64,256,192,message[lang][55],1,5,128);
	loadBg(1,"creditFF8",false);
	
	for (i=0;i<24;i++) {
		PA_CheckLid();
		PA_WaitForVBL();
	}
	
	fadeBlack(3,true,false,false,1);
	
	for (i=0;i<24;i++) {
		PA_CheckLid();
		PA_WaitForVBL();
	}
	
	fadeBlack(3,false,true,false,1);
	
	for (i=0;i<144;i++) {
		PA_CheckLid();
		PA_WaitForVBL();
	}
	
	fadeBlack(3,true,true,false,0);
	
	
	PA_16cErase(0);
	loadBg(0,"theEnd",false);
	
	for (i=0;i<24;i++) {
		PA_CheckLid();
		PA_WaitForVBL();
	}
	
	fadeBlack(4,true,false,false,1);
	
	for (i=0;i<472;i++) {
		PA_CheckLid();
		PA_WaitForVBL();
	}
	
	AS_MP3Stop();
	
	PA_WaitFor(Pad.Newpress.A || Pad.Newpress.B || Pad.Newpress.Start || Stylus.Newpress);
	
	fadeBlack(5,true,false,false,0);
	
	for (i=0;i<40;i++) {
		PA_CheckLid();
		PA_WaitForVBL();
	}
	
	effacerEcran();
}

void initAventure() {
	
	bool retour = false;

	while (1) {

		PA_LoadPal16(PAL_SPRITE0,0,(void*)curseur_Pal);
		PA_CreateSprite(0,0,(void*)curseur_Sprite,OBJ_SIZE_32X16,0,0,256,192);
		
		if (getNombreCarte(1,1,10) < 5) {
			initGameOver();
			break;
		}
		
		char nomPersoDebloque[64];
		
		if (dernierAdversaire+1 == persoDebloque) {
			if (((conditionDebloquer[dernierAdversaire][0] > 0) && (victoires[dernierAdversaire][0] == conditionDebloquer[dernierAdversaire][0])) || (collection[conditionDebloquer[dernierAdversaire][1]] > 0)) {
				if (persoDebloque == 12) {		// Si on a fini le jeu...
					initCredits();
					PA_LoadPal16(PAL_SPRITE0,0,(void*)curseur_Pal);
					PA_CreateSprite(0,0,(void*)curseur_Sprite,OBJ_SIZE_32X16,0,0,256,192);
				}
				else {
					sprintf(nomPersoDebloque,"%s %s !",message[lang][56],nomAdv[lang][persoDebloque+1]);
					PA_SetBrightness(0,0);
					afficherFenetre(0,nomPersoDebloque);
					PA_SetBrightness(0,-31);
					dernierAdversaire++;
				}
				persoDebloque++;
				sauvegarder();
			}
		}
		
		// On commence par afficher le background et les sprites...
		loadBg(0,"backAventure",false);
		loadBg(1,"backPerso",false);
		afficherStatus(1,message[lang][57]);
		
		int positionCurseurX = 0;
		int positionCurseurY = 0;
		int decalage = 0;
		int decale = 0;
		
		if (persoDebloque > 6) {
			decalage = 1;
			
		}
		
		PA_LoadSpritePal(0,1,(void*)cadre_Pal[13]);
		
		int i;
		for (i=0;i<3;i++) {
			if (i < persoDebloque) {
				PA_LoadSpritePal(0,i+4,(void*)cadre_Pal[i]);
				if ((i == 2) && (lang == 1)) {
					PA_CreateSprite(0,i+4,(void*)persoc02b_Sprite,OBJ_SIZE_64X64,1,i+4,8+i*72,16);
				}
				else {
					PA_CreateSprite(0,i+4,(void*)cadre_Sprite[i],OBJ_SIZE_64X64,1,i+4,8+i*72,16);
				}
				PA_SetSpritePrio(0,i+4,3);
			}
			else {
				PA_CreateSprite(0,i+4,(void*)cadre_Sprite[13],OBJ_SIZE_64X64,1,1,8+i*72,16);
				PA_SetSpritePrio(0,i+4,3);
				//EFS_LoadCadre(i,13,8+i*72,16);
			}
		}
		for (i=0;i<3;i++) {
			if (i+3 < persoDebloque) {
				PA_LoadSpritePal(0,i+7,(void*)cadre_Pal[i+3]);
				PA_CreateSprite(0,i+7,(void*)cadre_Sprite[i+3],OBJ_SIZE_64X64,1,i+7,40+i*72,94);
				PA_SetSpritePrio(0,i+7,3);
				//EFS_LoadCadre(i+3,i+3,40+i*72,94);
			}
			else {
				PA_CreateSprite(0,i+7,(void*)cadre_Sprite[13],OBJ_SIZE_64X64,1,1,40+i*72,94);
				PA_SetSpritePrio(0,i+7,3);
				//EFS_LoadCadre(i+3,13,40+i*72,94);
			}
		}
		
		// Si on a débloqué la 2eme page...
		if (decalage) {
			// Affichage des 6 autres cadres...
			for (i=0;i<3;i++) {
				if (i+6 < persoDebloque) {
					PA_LoadSpritePal(0,i+10,(void*)cadre_Pal[i+6]);
					PA_CreateSprite(0,i+10,(void*)cadre_Sprite[i+6],OBJ_SIZE_64X64,1,i+10,264+i*72,16);
					PA_SetSpritePrio(0,i+10,3);
					//EFS_LoadCadre(i,i,8+i*72,16);
				}
				else {
					PA_CreateSprite(0,i+10,(void*)cadre_Sprite[13],OBJ_SIZE_64X64,1,1,264+i*72,16);
					PA_SetSpritePrio(0,i+10,3);
					//EFS_LoadCadre(i,13,8+i*72,16);
				}
			}
			for (i=0;i<3;i++) {
				if (i+9 < persoDebloque) {
					PA_LoadSpritePal(0,i+13,(void*)cadre_Pal[i+9]);
					PA_CreateSprite(0,i+13,(void*)cadre_Sprite[i+9],OBJ_SIZE_64X64,1,i+13,296+i*72,94);
					PA_SetSpritePrio(0,i+13,3);
					//EFS_LoadCadre(i+3,i+3,40+i*72,94);
				}
				else {
					PA_CreateSprite(0,i+13,(void*)cadre_Sprite[13],OBJ_SIZE_64X64,1,1,296+i*72,94);
					PA_SetSpritePrio(0,i+13,3);
					//EFS_LoadCadre(i+3,13,40+i*72,94);
				}
			}
			
			// Affichage des fleches
			PA_LoadPal16(PAL_SPRITE0,3,(void*)flecheAventure_Pal);
			PA_CreateSprite(0,18,(void*)flecheAventure_Sprite,OBJ_SIZE_32X32,0,3,220,32);
			PA_CreateSprite(0,17,(void*)flecheAventure_Sprite,OBJ_SIZE_32X32,0,3,260,110);
			PA_SetSpriteHflip(0,17,1);
			PA_SetSpritePrio(0,18,3);
			PA_SetSpritePrio(0,17,3);
		}
		
		if (dernierAdversaire > 5) {
			for (i=4;i<19;i++) {
				PA_SetSpriteX(0,i,PA_GetSpriteX(0,i)-256);
			}
			decale = 1;
		}
		positionCurseurX = (dernierAdversaire%6) % 3;
		positionCurseurY = (dernierAdversaire%6) / 3;
		
		PA_SetSpriteXY(0,0,2+72*positionCurseurX+32*positionCurseurY,42+78*positionCurseurY);
		
		// Affichage de l'écran supérieur
		PA_LoadSpritePal(1,0,(void*)perso_Pal[dernierAdversaire+1]);
		PA_CreateSprite(1,0,(void*)perso_Sprite[dernierAdversaire+1][0],OBJ_SIZE_32X64,1,0,64,64);
		PA_CreateSprite(1,1,(void*)perso_Sprite[dernierAdversaire+1][1],OBJ_SIZE_64X64,1,0,0,64);
		PA_CreateSprite(1,2,(void*)perso_Sprite[dernierAdversaire+1][2],OBJ_SIZE_32X64,1,0,64,128);
		PA_CreateSprite(1,3,(void*)perso_Sprite[dernierAdversaire+1][3],OBJ_SIZE_64X64,1,0,0,128);
		PA_SetSpriteHflip(1,0,1);
		PA_SetSpriteHflip(1,1,1);
		PA_SetSpriteHflip(1,2,1);
		PA_SetSpriteHflip(1,3,1);
		afficherInfosPerso(dernierAdversaire);
		
		// Puis on affiche l'écran
		fadeBlack(1,true,true,false,1);
		
		playMusic("bgu");
		
		int timer=0;
		int choixAdversaire;
		int affichageAdversaire=0;
		int nbFrame=0;
		
		bool effacementPerso = false;
		bool affichagePerso = false;
		bool selection = false;
		
		while (1) {
			if (effacementPerso) {
				if (nbFrame <= (128/vitessePerso)) {
					for (i=0;i<4;i++) {
						PA_SetSpriteX(1,i,PA_GetSpriteX(1,i)-vitessePerso);
					}
					nbFrame++;
				}
				else {
					affichageAdversaire = positionCurseurX + positionCurseurY*3 + decale*6;
					if (affichageAdversaire < persoDebloque) {
						for (i=0;i<4;i++) {
							PA_DeleteSprite(1,i);
						}
						PA_LoadSpritePal(1,0,(void*)perso_Pal[affichageAdversaire+1]);
						PA_CreateSprite(1,0,(void*)perso_Sprite[affichageAdversaire+1][0],OBJ_SIZE_32X64,1,0,-32,64);
						PA_CreateSprite(1,1,(void*)perso_Sprite[affichageAdversaire+1][1],OBJ_SIZE_64X64,1,0,-96,64);
						PA_CreateSprite(1,2,(void*)perso_Sprite[affichageAdversaire+1][2],OBJ_SIZE_32X64,1,0,-32,128);
						PA_CreateSprite(1,3,(void*)perso_Sprite[affichageAdversaire+1][3],OBJ_SIZE_64X64,1,0,-96,128);
						PA_SetSpriteHflip(1,0,1);
						PA_SetSpriteHflip(1,1,1);
						PA_SetSpriteHflip(1,2,1);
						PA_SetSpriteHflip(1,3,1);
						affichagePerso = true;
						effacementPerso = false;
						nbFrame=0;
					}
					else {
						PA_16cErase(1);
					}
					effacementPerso = false;
				}
			}
			if (affichagePerso) {
				for (i=0;i<4;i++) {
					PA_SetSpriteX(1,i,PA_GetSpriteX(1,i)+vitessePerso);
				}
				if (PA_GetSpriteX(1,1) == 0) {
					//PA_ClearTextBg(1);
					PA_16cErase(1);
					afficherInfosPerso(affichageAdversaire);
					affichagePerso = false;
				}
			}
			if ((Pad.Newpress.Down && (positionCurseurY == 0)) || (Pad.Newpress.Up && positionCurseurY)) {
				positionCurseurY += Pad.Newpress.Down - Pad.Newpress.Up;
				PA_SetSpriteXY(0,0,2+72*positionCurseurX+32*positionCurseurY,42+78*positionCurseurY);
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				effacementPerso = true;
			}
			if (Pad.Newpress.Right || Pad.Newpress.Left) {
				int increment = Pad.Newpress.Right - Pad.Newpress.Left;
				if (((increment == 1) && (positionCurseurX < (2+decalage-decale))) || ((increment == -1) && ((positionCurseurX > 0-decale)))) {
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					positionCurseurX += increment;
					if (positionCurseurX == 3) {
						afficherDecalageAventure(1);
						positionCurseurX = 0;
						decale = 1;
					}
					else if (positionCurseurX == -1) {
						afficherDecalageAventure(-1);
						positionCurseurX = 2;
						decale = 0;
					}
					PA_SetSpriteXY(0,0,2+72*positionCurseurX+32*positionCurseurY,42+78*positionCurseurY);
					effacementPerso = true;
					timer = 0;
				}
			}
			if ((Pad.Held.Right && (positionCurseurX < (2+decalage-decale))) || (Pad.Held.Left && ((positionCurseurX > 0-decale)))) {
				if (timer == timerCurseur1) {
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					positionCurseurX += Pad.Held.Right - Pad.Held.Left;
					if (positionCurseurX == 3) {
						afficherDecalageAventure(1);
						positionCurseurX = 0;
						decale = 1;
					}
					else if (positionCurseurX == -1) {
						afficherDecalageAventure(-1);
						positionCurseurX = 2;
						decale = 0;
					}
					PA_SetSpriteXY(0,0,2+72*positionCurseurX+32*positionCurseurY,42+78*positionCurseurY);
					effacementPerso = true;
					timer -= timerCurseur2;
				}
				else {
					timer++;
				}
			}
			else if (Pad.Newpress.R && (decale+decalage == 1)) {
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				afficherDecalageAventure(1);
				decale = 1;
				PA_SetSpriteXY(0,0,2+72*positionCurseurX+32*positionCurseurY,42+78*positionCurseurY);
				effacementPerso = true;
			}
			else if (Pad.Newpress.L && decale) {
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				afficherDecalageAventure(-1);
				decale = 0;
				PA_SetSpriteXY(0,0,2+72*positionCurseurX+32*positionCurseurY,42+78*positionCurseurY);
				effacementPerso = true;
			}
			else if (Pad.Newpress.A || (selection && !effacementPerso && !affichagePerso)) {
				if (effacementPerso || affichagePerso) {
					selection = true;
				}
				else {
					selection = false;
					choixAdversaire = positionCurseurX + positionCurseurY*3 + decale*6;
					// Si le perso est débloquer...
					if (choixAdversaire < persoDebloque) {
						AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
						char texte[32];
						sprintf(texte,"%s\n%s ?",message[lang][58],nomAdv[lang][choixAdversaire+1]);
						if (afficherFenetre(1,texte)) {
							dernierAdversaire = choixAdversaire;
							fadeBlack(1,true,true,true,0);
							AS_MP3Stop();
							PA_WaitForVBL();
							AS_SetMP3Volume(127);
							effacerEcran();
							initPartieSolo(choixAdversaire);
							break;
						}
					}
					else {
						AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
					}
				}
			}
			else if (Pad.Newpress.B) {
				AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
				if (afficherFenetre(1,message[lang][18])) {
					fadeBlack(1,true,true,true,0);
					AS_MP3Stop();
					PA_WaitForVBL();
					AS_SetMP3Volume(127);
					/*for (i=0;i<19;i++) {
						PA_DeleteSprite(0,i);
					}
					for (i=0;i<4;i++) {
						PA_DeleteSprite(1,i);
					}
					PA_Clear16bitBg(0);
					PA_Clear16bitBg(1);
					PA_16cErase(1);*/
					retour = true;
					break;
				}
			}
			if (Stylus.Newpress) {
				timer = 0;
			}
			if (Stylus.Newpress || Stylus.Held) {
				// 6 choix possibles...
				if (PA_StylusInZone(8,16,72,80) && !((positionCurseurX == 0) && (positionCurseurY == 0))) {
					positionCurseurX = 0;
					positionCurseurY = 0;
					PA_SetSpriteXY(0,0,2+72*positionCurseurX+32*positionCurseurY,42+78*positionCurseurY);
					effacementPerso = true;
				}
				else if (PA_StylusInZone(80,16,144,80) && !((positionCurseurX == 1) && (positionCurseurY == 0))) {
					positionCurseurX = 1;
					positionCurseurY = 0;
					PA_SetSpriteXY(0,0,2+72*positionCurseurX+32*positionCurseurY,42+78*positionCurseurY);
					effacementPerso = true;
				}
				else if (PA_StylusInZone(152,16,216,80) && !((positionCurseurX == 2) && (positionCurseurY == 0))) {
					positionCurseurX = 2;
					positionCurseurY = 0;
					PA_SetSpriteXY(0,0,2+72*positionCurseurX+32*positionCurseurY,42+78*positionCurseurY);
					effacementPerso = true;
				}
				else if (PA_StylusInZone(40,94,104,158) && !((positionCurseurX == 0) && (positionCurseurY == 1))) {
					positionCurseurX = 0;
					positionCurseurY = 1;
					PA_SetSpriteXY(0,0,2+72*positionCurseurX+32*positionCurseurY,42+78*positionCurseurY);
					effacementPerso = true;
				}
				else if (PA_StylusInZone(112,94,176,158) && !((positionCurseurX == 1) && (positionCurseurY == 1))) {
					positionCurseurX = 1;
					positionCurseurY = 1;
					PA_SetSpriteXY(0,0,2+72*positionCurseurX+32*positionCurseurY,42+78*positionCurseurY);
					effacementPerso = true;
				}
				else if (PA_StylusInZone(184,94,248,158) && !((positionCurseurX == 2) && (positionCurseurY == 1))) {
					positionCurseurX = 2;
					positionCurseurY = 1;
					PA_SetSpriteXY(0,0,2+72*positionCurseurX+32*positionCurseurY,42+78*positionCurseurY);
					effacementPerso = true;
				}
				else if (PA_StylusInZone(220,32,252,64) && (decale+decalage == 1)) {
					if (timer == timerCurseur1) {
						AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
						afficherDecalageAventure(1);
						decale = 1;
						PA_SetSpriteXY(0,0,2+72*positionCurseurX+32*positionCurseurY,42+78*positionCurseurY);
						effacementPerso = true;
						timer = 0;
					}
					else {
						timer++;
					}
				}
				else if (PA_StylusInZone(4,110,36,142) && decale) {
					if (timer == timerCurseur1) {
						AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
						afficherDecalageAventure(-1);
						decale = 0;
						PA_SetSpriteXY(0,0,2+72*positionCurseurX+32*positionCurseurY,42+78*positionCurseurY);
						effacementPerso = true;
						timer = 0;
					}
					else {
						timer++;
					}
				}
				else {
					timer = 0;
				}
			}
			if (Stylus.Released || (selection && !effacementPerso && !affichagePerso)) {
				if (effacementPerso || affichagePerso) {
					selection = true;
				}
				else {
					selection = false;
					// 8 choix possible
					if (PA_StylusInZone(8,16,72,80) || PA_StylusInZone(80,16,144,80) || PA_StylusInZone(152,16,216,80) || PA_StylusInZone(40,94,104,158) || PA_StylusInZone(112,94,176,158) || PA_StylusInZone(184,94,248,158)) {
						choixAdversaire = positionCurseurX + positionCurseurY*3 + decale*6;
						if (choixAdversaire < persoDebloque) {
							AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
							char texte[32];
							sprintf(texte,"%s\n%s ?",message[lang][58],nomAdv[lang][choixAdversaire+1]);
							if (afficherFenetre(1,texte)) {
								dernierAdversaire = choixAdversaire;
								fadeBlack(1,true,true,true,0);
								AS_MP3Stop();
								PA_WaitForVBL();
								AS_SetMP3Volume(127);
								effacerEcran();
								initPartieSolo(choixAdversaire);
								break;
							}
						}
						else {
							AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
						}
					}
					else if (PA_StylusInZone(220,32,252,64) && (decale+decalage == 1)) {
						AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
						afficherDecalageAventure(1);
						decale = 1;
						PA_SetSpriteXY(0,0,2+72*positionCurseurX+32*positionCurseurY,42+78*positionCurseurY);
						effacementPerso = true;
					}
					else if (PA_StylusInZone(4,110,36,142) && decale) {
						AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
						afficherDecalageAventure(-1);
						decale = 0;
						PA_SetSpriteXY(0,0,2+72*positionCurseurX+32*positionCurseurY,42+78*positionCurseurY);
						effacementPerso = true;
					}
				}
			}
			PA_CheckLid();
			PA_WaitForVBL();
		}
		if (retour) {
			break;
		}
	}
	
	effacerEcran();
}

void initWifi() {

	int i,j,k;
	int positionCurseur=0;
	bool retour=false;

	if (!initEcrireNom()) {
		retour2D();
		return;
	}
	
	sauvegarderBitmap(1);
	
	for (i=0;i<10;i++) {
		for (j=0;j<48;j++) {
			for (k=0;k<96;k++) {
				bitmapWifi[i][j][k] = '0';
			}
		}
	}
	
	wifiActive = true;

	// On commence par afficher le background et les sprites...
	PA_Init3D();
	PA_Reset3DSprites();
	PA_SetBgPrio(0,0,2);
	PA_Init16bitBg(0,3);
	//PA_Init8bitBg(0,1);
	PA_Init16cBg(0,1);
	
	loadBg(0,"backWifi",true);
	loadBg(1,"backVS",false);
	
	PA_LoadPal16(PAL_BG0,0,(void*)text_Pal);

	// Affichage du curseur
	u16 curseur_gfx = PA_3DCreateTex((void*)curseur3D_Texture, 32, 16, TEX_16COL);
	PA_Load3DSpritePal(0, (void*)curseur3D_Pal);
	PA_3DCreateSpriteFromTex(10,curseur_gfx,20,12,0,30,40);
	PA_3DSetSpritePrio(10,2048);
	
	// Affichage du choix
	u16 choix_gfx = (lang == 1) ? PA_3DCreateTex((void*)choixWifi1_Texture,128,64,TEX_16COL) : PA_3DCreateTex((void*)choixWifi0_Texture,128,64,TEX_16COL);
	PA_3DCreateSpriteFromTex(0,choix_gfx,128,64,0,84,48);
	PA_3DSetSpritePrio(0,2000);
	
	// Affichage de la fenetre
	u16 fenetre_gfx = PA_3DCreateTex((void*)fenetreListeCarte_Texture,128,256,TEX_256COL);
	PA_Load3DSpritePal(17, (void*)fenetreListeCarte_Pal);
	PA_3DCreateSpriteFromTex(1,fenetre_gfx,128,156,17,128,292);
	PA_3DSetSpritePrio(11,2041);
	
	// Affichage du numero de page
	u16 haut_gfx = PA_3DCreateTex((void*)hautFenetre3D_Texture,128,8,TEX_4COL);
	PA_Load3DSpritePal(2, (void*)hautListeCarte_Pal);
	PA_3DCreateSpriteFromTex(2,haut_gfx,128,6,2,128,217);
	PA_3DSetSpritePrio(2,2043);
	PA_3DSetSpriteFrame(2,1);
	
	// Affichage de la fenetre de confirmation
	u16 fenetre3D_gfx = PA_3DCreateTex((void*)fenetre3D_Texture,128,64,TEX_256COL);
	PA_Load3DSpritePal(3, (void*)fenetre3D_Pal);
	PA_3DCreateSpriteFromTex(15,fenetre3D_gfx,128,64,3,128,96);
	PA_3DSetSpritePrio(15,2046);
	
	// Affichage du haut de page
	u16 haut3D_gfx = PA_3DCreateTex((void*)hautFenetre3D_Texture,128,8,TEX_4COL);
	PA_3DCreateSpriteFromTex(16,haut3D_gfx,128,6,2,128,67);
	PA_3DSetSpritePrio(16,2047);
	PA_3DSetSpriteFrame(16,0);

	PA_3DSetSpriteY(15,288);
	PA_3DSetSpriteY(16,259);
	
	PA_3DProcess();
	PA_WaitForVBL();
	
	// Puis on affiche
	fadeBlack(1,true,true,false,1);
	
	playMusic("battle");
	PA_SetLedBlink(1,1);
	
	while (1) {
		PA_16cErase(0);
		PA_3DSetSpriteXY(10,30+2*positionCurseur,40+22*positionCurseur);
		PA_3DSetSpriteY(0,48);
		
		while (1) {
			if (((Pad.Newpress.Down || (Stylus.Held && PA_StylusInZone(38,47,132,71))) && (positionCurseur == 0)) || ((Pad.Newpress.Up || (Stylus.Held && PA_StylusInZone(36,25,111,46))) && (positionCurseur == 1))) {
				positionCurseur = 1-positionCurseur;
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				PA_3DSetSpriteXY(10,30+2*positionCurseur,40+22*positionCurseur);
			}
			if (Pad.Newpress.A || (Stylus.Released && PA_StylusInZone(36,25,132,71))) {
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				PA_3DSetSpriteY(0,-96);
				PA_3DSetSpriteY(10,-96);
				
				PA_3DProcess();
				PA_WaitForVBL();
				
				if (positionCurseur == 0) {
					if (!initWifiCreer(fenetre_gfx)) {
						retour2D();
						return;
					}
				}
				else {
					if (!initWifiRejoindre(fenetre_gfx)) {
						retour2D();
						return;
					}
				}
				break;
			}
			else if (Pad.Newpress.B) {
				AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
				if (afficherFenetre3D(1,message[lang][18])) {
					retour = true;
					break;
				}
				PA_3DSetSpriteXY(10,30+2*positionCurseur,40+22*positionCurseur);
			}
			PA_3DProcess();
			PA_WaitForVBL();
		}
		if (retour) {
			break;
		}
	}
	
	fadeBlack(1,true,true,true,0);
	
	AS_MP3Stop();
	PA_WaitForVBL();
	AS_SetMP3Volume(127);
	
	retour2D();
	
	wifiActive = false;
	PA_SetLedBlink(0,0);
}

void initCollection() {

	int i;
	int x;
	int timer=0;
	int positionCurseur=0;
	int page=0;
	int couleur;
	int ajoutPage;
	u16 mini_gfx[12];
	char affichage[16];
	
	// On commence par afficher le background et les sprites...
	PA_Init3D();
	PA_Reset3DSprites();
	PA_SetBgPrio(0,0,2);
	PA_Init16bitBg(0,3);
	PA_Init16cBg(0,1);
	
	loadBg(0,"backCollection",false);
	loadBg(1,"backCollectionInfo",false);
	
	PA_LoadPal16(PAL_BG0,0,(void*)text_Pal);
	
	PA_LoadSpritePal(1,0,(void*)perso_Pal[0]);
	PA_CreateSprite(1,0,(void*)perso_Sprite[0][0],OBJ_SIZE_32X64,1,0,160,64);
	PA_CreateSprite(1,1,(void*)perso_Sprite[0][1],OBJ_SIZE_64X64,1,0,192,64);
	PA_CreateSprite(1,2,(void*)perso_Sprite[0][2],OBJ_SIZE_32X64,1,0,160,128);
	PA_CreateSprite(1,3,(void*)perso_Sprite[0][3],OBJ_SIZE_64X64,1,0,192,128);
	
	PA_LoadSpritePal(1,3,(void*)carteG_Pal[0][0]);
	carteG_gfx = PA_CreateGfx(1,(void*)carteG_Sprite[0][0],OBJ_SIZE_64X64,1);
	PA_CreateSpriteFromGfx(1,4,carteG_gfx,OBJ_SIZE_64X64,1,3,64,122);
	
	// On affiche le background pour les miniatures
	/*PA_Load3DSpritePal(2,(void*)persoMiniBg_Pal);
	u16 persoMiniBg_gfx = PA_3DCreateTex((void*)persoMiniBg_Texture,192,16,TEX_256COL);
	PA_3DCreateSpriteFromTex(17,persoMiniBg_gfx,192,16,2,96,12);
	PA_3DSetSpritePrio(17,512);
	PA_3DSetSpriteAlpha(17,16);
	PA_3DSetSpritePolyID(17,19);*/
	
	// Chargement et affichage des miniatures
	PA_Load3DSpritePal(1,(void*)persoMini_Pal);
	for (i=0;i<persoDebloque;i++) {
		if (i < 12) {
			mini_gfx[i] = PA_3DCreateTex((void*)persoMini_Texture, 16, 16, TEX_256COL);
			PA_3DCreateSpriteFromTex(i+20,mini_gfx[i],16,16,1,8+16*i,-12);
			PA_3DSetSpriteFrame(i+20,i);
			/*PA_3DSetSpritePrio(i+20,1024+i);
			PA_3DSetSpriteAlpha(i+20,7);
			PA_3DSetSpritePolyID(i+20,i+20);*/
		}
	}
	
	// Affichage du curseur
	u16 curseur_gfx = PA_3DCreateTex((void*)curseur3D_Texture, 32, 16, TEX_16COL);
	PA_Load3DSpritePal(0, (void*)curseur3D_Pal);
	PA_3DCreateSpriteFromTex(10,curseur_gfx,20,12,0,26,40);
	PA_3DSetSpritePrio(10,2048);
	
	// Affichage des fleches clignotantes
	PA_Load3DSpritePal(3,(void*)flecheMenu_Pal);
	PA_3DCreateSprite(13,(void*)flecheMenu_Texture,8,8,TEX_4COL,3,37,164);
	PA_3DCreateSprite(14,(void*)flecheMenu_Texture,8,8,TEX_4COL,3,154,164);
	PA_3DStartSpriteAnim(13,0,1,6);
	PA_3DStartSpriteAnim(14,2,3,6);
	
	// Affichage du numero de page
	u16 haut_gfx = PA_3DCreateTex((void*)hautListeCarte_Texture,128,8,TEX_4COL);
	PA_Load3DSpritePal(5, (void*)hautListeCarte_Pal);
	PA_3DCreateSpriteFromTex(18,haut_gfx,128,6,5,96,28);
	PA_3DSetSpritePrio(18,2043);
	PA_3DSetSpriteFrame(18,0);
	
	// Chargement de la fenetre
	u16 fenetre_gfx = PA_3DCreateTex((void*)fenetreListeCarte_Texture,128,256,TEX_256COL);
	PA_Load3DSpritePal(6, (void*)fenetreListeCarte_Pal);
	
	// Affichage de la fenetre de confirmation
	u16 fenetre3D_gfx = PA_3DCreateTex((void*)fenetre3D_Texture,128,64,TEX_256COL);
	PA_Load3DSpritePal(4, (void*)fenetre3D_Pal);
	PA_3DCreateSpriteFromTex(15,fenetre3D_gfx,128,64,4,128,288);
	PA_3DSetSpritePrio(15,2046);
	
	// Affichage du haut de page
	u16 haut3D_gfx = PA_3DCreateTex((void*)hautFenetre3D_Texture,128,8,TEX_4COL);
	PA_3DCreateSpriteFromTex(16,haut3D_gfx,128,6,5,128,259);
	PA_3DSetSpritePrio(16,2047);
	PA_3DSetSpriteFrame(16,0);

	majInfoCollection();
	majListeCollection(0);
	majMiniature(1);
	majCarteG((collection[1] > 0),(historique[1] > 0));
	majNiveauCollection(0);
	
	PA_3DProcess();
	PA_WaitForVBL();
	
	// Puis on affiche l'écran
	fadeBlack(1,true,true,false,1);
	
	playMusic("bgu");
	
	while (1) {
		if (Pad.Newpress.Down || Pad.Newpress.Up) {
			positionCurseur += Pad.Newpress.Down - Pad.Newpress.Up;
			if (positionCurseur == -1) {
				positionCurseur = 10;
			}
			else if (positionCurseur == 11) {
				positionCurseur = 0;
			}
			PA_3DSetSpriteY(10,40+12*positionCurseur);
			AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
			
			timer = 0;
			
			majCarteG((collection[positionCurseur+11*page+1] > 0),((historique[positionCurseur+11*page+1]) ? positionCurseur+11*page+1 : 0));
			majMiniature(positionCurseur+11*page+1);
		}
		else if (Pad.Held.Down || Pad.Held.Up) {
			if (timer == timerCurseur1) {
				positionCurseur += Pad.Held.Down - Pad.Held.Up;
				if (positionCurseur == -1) {
					positionCurseur = 10;
				}
				else if (positionCurseur == 11) {
					positionCurseur = 0;
				}
				PA_3DSetSpriteY(10,40+12*positionCurseur);
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				timer -= timerCurseur2;
				majCarteG((collection[positionCurseur+11*page+1] > 0),((historique[positionCurseur+11*page+1]) ? positionCurseur+11*page+1 : 0));
				majMiniature(positionCurseur+11*page+1);
			}
			else {
				timer++;
			}
		}
		else if (Pad.Newpress.R || Pad.Held.Right || Pad.Newpress.L || Pad.Held.Left) {
			ajoutPage = (Pad.Newpress.R || Pad.Held.Right) - (Pad.Newpress.L || Pad.Held.Left);
			page += ajoutPage;
			if (page == -1) {
				page = 9;
			}
			else if (page == 10) {
				page = 0;
			}
			AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
			majCarteG((collection[positionCurseur+11*page+1] > 0),((historique[positionCurseur+11*page+1]) ? positionCurseur+11*page+1 : 0));
			majMiniature(positionCurseur+11*page+1);
			majNiveauCollection(page);
		}
		else if ((Pad.Newpress.A || Pad.Newpress.X) && historique[positionCurseur+11*page+1]) {
			if (collection[positionCurseur+11*page+1] > 0) {
				if ((positionCurseur+11*page+1) > 77) {
					AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
					afficherFenetre3D(0,message[lang][59]);
				}
				else if (getNombreCarte(1,1,10) == 5) {
					AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
					afficherFenetre3D(0,message[lang][60]);
				}
				else {
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					if (afficherFenetre3D(1,message[lang][61])) {
						collection[positionCurseur+11*page+1]--;
						majInfoCollection();
						sauvegarder();
					}
				}
				PA_3DSetSpriteXY(10,26,40+12*positionCurseur);
				majListeCollection(page);
				majCarteG((collection[positionCurseur+11*page+1] > 0),((historique[positionCurseur+11*page+1]) ? positionCurseur+11*page+1 : 0));
			}
			else {
				AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
			}
		}
		else if (Pad.Newpress.B) {
			AS_SoundDefaultPlay((void*)annuler,8596,127,64,0,0);
			if (afficherFenetre3D(1,message[lang][18])) {
				break;
			}
			PA_3DSetSpriteXY(10,26,40+12*positionCurseur);
			majListeCollection(page);
		}
		if (Stylus.Newpress || Stylus.Held) {
			for (i=0;i<11;i++) {
				if (PA_StylusInZone(36,31+12*i,150,43+12*i)) {
					positionCurseur = i;
					PA_3DSetSpriteY(10,40+12*positionCurseur);
					majCarteG((collection[positionCurseur+11*page+1] > 0),((historique[positionCurseur+11*page+1]) ? positionCurseur+11*page+1 : 0));
					majMiniature(positionCurseur+11*page+1);
					break;
				}
			}
			if (PA_StylusInZone(32,163,37,170)) {
				page--;
				if (page == -1) {
					page = 9;
				}
				ajoutPage = -1;
				majCarteG((collection[positionCurseur+11*page+1] > 0),((historique[positionCurseur+11*page+1]) ? positionCurseur+11*page+1 : 0));
				majMiniature(positionCurseur+11*page+1);
				majNiveauCollection(page);
			}
			else if (PA_StylusInZone(155,163,160,170)) {
				page++;
				if (page == 10) {
					page = 0;
				}
				ajoutPage = 1;
				majCarteG((collection[positionCurseur+11*page+1] > 0),((historique[positionCurseur+11*page+1]) ? positionCurseur+11*page+1 : 0));
				majMiniature(positionCurseur+11*page+1);
				majNiveauCollection(page);
			}
		}
		if (Stylus.Released && PA_StylusInZone(36,31,150,163) && historique[positionCurseur+11*page+1]) {
			if (collection[positionCurseur+11*page+1] > 0) {
				if ((positionCurseur+11*page+1) > 77) {
					AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
					afficherFenetre3D(0,message[lang][59]);
				}
				else if (getNombreCarte(1,1,10) == 5) {
					AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
					afficherFenetre3D(0,message[lang][60]);
				}
				else {
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					if (afficherFenetre3D(1,message[lang][61])) {
						collection[positionCurseur+11*page+1]--;
						majInfoCollection();
						sauvegarder();
					}
				}
				PA_3DSetSpriteXY(10,26,40+12*positionCurseur);
				majListeCollection(page);
				majCarteG((collection[positionCurseur+11*page+1] > 0),((historique[positionCurseur+11*page+1]) ? positionCurseur+11*page+1 : 0));
			}
			else {
				AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
			}
		}
		if (ajoutPage != 0) {
			x=0;
			PA_3DSetSpriteFrame(18,page);
			PA_3DCreateSpriteFromTex(19,fenetre_gfx,128,156,6,96,103);
			PA_3DSetSpritePrio(18,2042);
			if (ajoutPage == 1) {	// Page suivante
				PA_3DSetSpriteTopRight(19,-1,0);
				PA_3DSetSpriteBottomRight(19,-1,0);
				PA_3DSetSpriteTopLeft(19,128,0);
				PA_3DSetSpriteBottomLeft(19,128,0);
				while (x < 128) {
					x += ((128-x)/2)+1;
					if (x > 128) {
						x = 128;
					}
					PA_3DSetSpriteTopLeft(19,128-x,0);
					PA_3DSetSpriteBottomLeft(19,128-x,0);
					PA_16cClearZone(0,160-x,0,256,174);
					
					// On affiche la page suivante...
					for (i=0;i<11;i++) {
						couleur = -1;
						if (collection[i+11*page+1] > 0) {
							couleur = 1;
						}
						else if (historique[i+11*page+1]) {
							couleur = 3;
						}
						if (couleur > 0) {
							PA_16cTextAlign(ALIGN_LEFT);
							sprintf(affichage,"%s",nomCarte[lang][i+11*page+1]);
							PA_16cText(0,166-x,31+12*i,280-x,174,affichage,couleur,5,16);
							
							PA_16cTextAlign(ALIGN_RIGHT);
							sprintf(affichage,"%d",collection[i+11*page+1]);
							PA_16cText(0,166-x,31+12*i,280-x,174,affichage,couleur,5,3);
						}
					}
					// Qu'on coupe pour pas qu'elle dépasse :)
					PA_16cClearZone(0,159,0,256,174);
					
					PA_CheckLid();
					PA_3DProcess();
					PA_WaitForVBL();
				}
			}
			else {	// Page précédente
				PA_3DSetSpriteTopRight(19,-127,0);
				PA_3DSetSpriteBottomRight(19,-127,0);
				while (x < 128) {
					x += ((128-x)/2)+1;
					if (x > 128) {
						x = 128;
					}
					PA_3DSetSpriteTopRight(19,x-129,0);
					PA_3DSetSpriteBottomRight(19,x-129,0);
					
					PA_16cClearZone(0,0,0,32+x,174);
					
					// On affiche la page suivante...
					for (i=0;i<11;i++) {
						couleur = -1;
						if (collection[i+11*page+1] > 0) {
							couleur = 1;
						}
						else if (historique[i+11*page+1]) {
							couleur = 3;
						}
						if (couleur > 0) {
							PA_16cTextAlign(ALIGN_LEFT);
							sprintf(affichage,"%s",nomCarte[lang][i+11*page+1]);
							PA_16cText(0,x-90,31+12*i,24+x,174,affichage,couleur,5,16);
							
							PA_16cTextAlign(ALIGN_RIGHT);
							sprintf(affichage,"%d",collection[i+11*page+1]);
							PA_16cText(0,x-90,31+12*i,24+x,174,affichage,couleur,5,3);
						}
					}
					// Qu'on coupe pour pas qu'elle dépasse :)
					PA_16cClearZone(0,0,0,38,174);
					PA_16cClearZone(0,159,0,256,174);
					
					PA_CheckLid();
					PA_3DProcess();
					PA_WaitForVBL();
				}
			}
			PA_3DDeleteSprite(19);
			ajoutPage = 0;
			PA_WaitForVBL();
		}
		
		PA_CheckLid();
		PA_3DProcess();
		PA_WaitForVBL();
	}
	
	fadeBlack(1,true,true,true,0);
	AS_MP3Stop();
	PA_WaitForVBL();
	AS_SetMP3Volume(127);
	
	// Et on sort
	PA_Reset3DSprites();
	PA_Init2D();
	
	PA_Init16bitBg(0,3);
	PA_Init16bitBg(1,3);
	PA_Init16cBg(0,1);
	PA_Init16cBg(1,1);
	
	effacerEcran();
}

void MyVBLFunction() {
	if (wifiActive) {
		IPC_RcvCompleteCheck();
		LOBBY_Update();
	}
	if (AS_GetMP3Status() == MP3ST_DECODE_ERROR) {
		AS_MP3Stop();
		playMusic(id_music);
	}
	
	//AS_SoundVBL();
	/*if (musique && !IPC_Sound->chan[0].busy) {
		EFS_PlayBgm(numeroMusique,1);
	}*/
}

void ReceptionConfirm(unsigned char *data, int length, LPLOBBY_USER from) {
	if (wifiActive) {
		if (length == 555) {		// On quitte ! Cette option passe par dessus toute les autres
			// Affichage de la fenetre
			u16 fenetre_gfx = PA_3DCreateTex((void*)fenetreListeCarte_Texture,128,256,TEX_256COL);
			PA_Load3DSpritePal(11, (void*)fenetreListeCarte_Pal);
			PA_3DCreateSpriteFromTex(11,fenetre_gfx,128,156,11,128,100);
			PA_3DSetSpritePrio(11,2041);
			
			// Affichage du numero de page
			u16 haut_gfx = PA_3DCreateTex((void*)hautListeCarte_Texture,128,8,TEX_4COL);
			PA_Load3DSpritePal(12, (void*)hautListeCarte_Pal);
			PA_3DCreateSpriteFromTex(12,haut_gfx,128,6,12,128,25);
			PA_3DSetSpritePrio(12,2043);
			PA_3DSetSpriteFrame(12,0);
			
			afficherFenetre3D(0,message[lang][62]);
			afficherFenetre3D(0,message[lang][63]);
			while (1) {
				PA_3DProcess();
				PA_WaitForVBL();
			}
		}
		if (length < 20) {		// Affichage du perso de l'adversaire
			persoAdvWifi = length;
		}
		else {		// Demande de jouer
			if (length == 20) {		// Si l'autre a refusé, on quitte la room
				LOBBY_LeaveRoom();
				afficherFenetre3D(0,message[lang][64]);
			}
			else if (length == 21) {		// Si c'est bon, on choisis le perso
				allowChoixPerso = true;
			}
			reponseWifi = true;
			//LOBBY_GetUserName(from);
		}
	}
}

void ReceptionJeu(unsigned char *data, int length, LPLOBBY_USER from) {
	if (wifiActive) {
		if (length > 99) {		// Tour joueur
			tourWifi = length-100;
		}
		else {			// Carte et zone
			carteWifi = length/10;
			zoneWifi = length%10;
			carteJoueeWifi = true;
		}
	}
}

void ReceptionEtape(unsigned char *data, int length, LPLOBBY_USER from) {
	if (wifiActive) {
		if (length == 555) {
			envoiWifi(false,0x0005,"",etape);
		}
		else {
			etapeWifi = length;
		}
	}
}

void ReceptionChoixFin(unsigned char *data, int length, LPLOBBY_USER from) {
	if (wifiActive) {
		if (length > 9) {		// Déplacement de la carte séléctionnée dans la main
			int i;
			
			length -= 10;
			
			for (i=0;i<5;i++) {
				if (i == length) {
					PA_3DSetSpriteX(i,27);
				}
				else if (!carteJouee[0][i]) {
					PA_3DSetSpriteX(i,25);
				}
			}
		}
		else {
			choixFinWifi = length;
		}
	}
}

void ReceptionChoixCarte(unsigned char *data, int length, LPLOBBY_USER from) {
	if (wifiActive) {
		if (length == 24) {		// Main aléatoire
			sscanf(data,"%d %d %d %d %d ",&mainJoueur1[0][0],&mainJoueur1[0][1],&mainJoueur1[0][2],&mainJoueur1[0][3],&mainJoueur1[0][4]);
		}
		else if (length == 1) {
			nombreCarteAfficheWifi--;
			enleverCarteWifi[nombreCarteAfficheWifi] = true;
		}
		else if (length == 3) {
			int carte;
			sscanf(data,"%d ",&carte);
			//loadCarteMem(arf,0,0,carte);
			ajouterCarteWifi[nombreCarteAfficheWifi] = true;
			mainJoueur1[0][nombreCarteAfficheWifi] = carte;
			nombreCarteAfficheWifi++;
		}
	}
}

void ReceptionDemandeBitmap(unsigned char *data, int length, LPLOBBY_USER from) {
	if (wifiActive) {
		LOBBY_SendToUser(from,0x0009,bitmap[length],96);
		//PA_WaitFor(LOBBY_UserIsAllSent(from));
	}
}

void ReceptionEnvoiBitmap(unsigned char *data, int length, LPLOBBY_USER from) {
	if (wifiActive) {
		/*int i;
		PA_16cClearZone(0,36,24+afficherNomWifiId,132,24+afficherNomWifiId);
		for (i=0;i<96;i++) {
			if (data[i] == '1') {
				PA_16cPutPixel(0,36+i,24+afficherNomWifiId,6);
			}
		}
		*/
		int i;
		for (i=0;i<96;i++) {
			bitmapWifi[idUserWifi][afficherNomWifiId][i] = data[i];
		}
		afficherNomWifiId++;
	}
}

void ReceptionElements(unsigned char *data, int length, LPLOBBY_USER from) {
	if (wifiActive) {
		if (length == 8) {		// Envoi des règles
			sscanf(data,"%01d%01d%01d%01d%01d%01d%01d%01d",&regleWifi[0],&regleWifi[1],&regleWifi[2],&regleWifi[3],&regleWifi[4],&regleWifi[5],&regleWifi[6],&regleWifi[7]);
			majRegles(regleWifi);
		}
		else if (length == 9) {		// Envoi des éléments
			sscanf(data,"%01d%01d%01d%01d%01d%01d%01d%01d%01d",&elementPlateau[1][1],&elementPlateau[2][1],&elementPlateau[3][1],&elementPlateau[1][2],&elementPlateau[2][2],&elementPlateau[3][2],&elementPlateau[1][3],&elementPlateau[2][3],&elementPlateau[3][3]);
			int i,j;
			for (i=0;i<3;i++) {
				for (j=0;j<3;j++) {
					if (elementPlateau[j+1][i+1] > 0) {
						element_gfx[3*i+j] = PA_3DCreateTex(element_Texture[elementPlateau[j+1][i+1]],16,16,TEX_256COL);
						bonus_gfx[3*i+j] = PA_3DCreateTex((void*)bonusCarte_Texture,32,32,TEX_4COL);
						PA_3DCreateSpriteFromTex(12+3*i+j,element_gfx[3*i+j],16,16,12,78+50*j,39+50*i);
						PA_3DSetSpritePrio(12+3*i+j,524+3*i+j);
						PA_3DStartSpriteAnim(12+3*i+j,0,3,16);
						PA_3DSetSpriteAlpha(12+3*i+j,7);
						PA_3DSetSpritePolyID(12+3*i+j,12+3*i+j);
					}
				}
			}
		}
	}
}

// Function: main()
int main(int argc, char ** argv) {
	PA_Init();    // Initializes PA_Lib
	PA_InitVBL(); // Initializes a standard VBL
	
	fatInitDefault();
	nitfoFSInit();
	
	PA_VBLFunctionInit(MyVBLFunction);
	IPC_Init();
	IPC_SetChannelCallback(0, &LWIFI_IPC_Callback);
	LOBBY_Init();
	PA_WaitForVBL();PA_WaitForVBL();PA_WaitForVBL();
	LOBBY_SetStreamHandler(0x0003, &ReceptionConfirm);
	LOBBY_SetStreamHandler(0x0004, &ReceptionJeu);
	LOBBY_SetStreamHandler(0x0005, &ReceptionEtape);
	LOBBY_SetStreamHandler(0x0006, &ReceptionChoixFin);
	LOBBY_SetStreamHandler(0x0007, &ReceptionChoixCarte);
	LOBBY_SetStreamHandler(0x0008, &ReceptionDemandeBitmap);
	LOBBY_SetStreamHandler(0x0009, &ReceptionEnvoiBitmap);
	LOBBY_SetStreamHandler(0x0010, &ReceptionElements);
	
	//PA_InitASLibForSounds(AS_MODE_SURROUND | AS_MODE_16CH);
	PA_InitASLibForMP3(AS_MODE_MP3 | AS_MODE_SURROUND | AS_MODE_16CH);
	PA_VBLFunctionInit(MyVBLFunction);
	AS_SetDefaultSettings(AS_PCM_16BIT, 44100, AS_NO_DELAY);
	AS_SetMP3Volume(127);
	AS_SetMP3Loop(1);
	
	//PA_InitSound();	
	PA_InitRand();
	
	lang = (PA_UserInfo.Language == 2) ? 0 : 1;
	
	PA_16cCustomFont(5,font);
	PA_LoadPal16(PAL_BG0,0,(void*)text_Pal);
	PA_LoadPal16(PAL_BG1,0,(void*)text_Pal);
	
	PA_Init16bitBg(0,3);
	PA_Init16bitBg(1,3);
	PA_Init16cBg(0,1);
	PA_Init16cBg(1,1);
	
	PA_LoadPal16(PAL_SPRITE0,0,(void*)curseur_Pal);
	PA_CreateSprite(0,0,(void*)curseur_Sprite,OBJ_SIZE_32X16,0,0,256,192);
	PA_SetSpritePrio(0,0,0);
	
	if (!charger()) {
		sauvegarde = false;
		nouvelleSauv();
	
		afficherFenetre(0,message[lang][65]);
	}
	PA_SetBrightness(0,-31);
	
	majHistorique();
	
	int positionCurseur=0;
	
	while (1) {
		loadBg(0,"menu",true);
		
		PA_LoadPal16(PAL_SPRITE0,0,(void*)curseur_Pal);
		PA_CreateSprite(0,0,(void*)curseur_Sprite,OBJ_SIZE_32X16,0,0,46,112+18*positionCurseur);
		PA_SetSpritePrio(0,0,0);
		
		// On choisi la position du curseur et on l'affiche
		int timer=0;
		bool sortieBoucle = false;
		
		fadeBlack(1,true,true,false,1);
		
		// Infinite loop to keep the program running
		while (1) {
			if (positionCurseur > 4) {
				positionCurseur = 0;
			}
			if (Pad.Newpress.Down || Pad.Newpress.Up) {
				positionCurseur += Pad.Newpress.Down - Pad.Newpress.Up;
				positionCurseur &= 3;
				PA_SetSpriteY(0,0,112+18*positionCurseur);
				AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
				
				timer = 0;
			}
			if (Pad.Held.Down || Pad.Held.Up) {
				if (timer == timerCurseur1) {
					positionCurseur += Pad.Held.Down - Pad.Held.Up;
					positionCurseur &= 3;
					PA_SetSpriteY(0,0,112+18*positionCurseur);
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					timer -= timerCurseur2;
				}
				else {
					timer++;
				}
			}
			if (Pad.Newpress.A) {
				switch (positionCurseur) {
					case 0:
					AS_SoundDefaultPlay((void*)ouvrir,171340,127,64,0,0);
					fadeBlack(1,true,true,false,0);
					effacerEcran();
					initAventure();
					sortieBoucle = true;
					break;
					
					case 1:
					if (getNombreCarte(1,1,10) > 4) {
						AS_SoundDefaultPlay((void*)ouvrir,171340,127,64,0,0);
						fadeBlack(1,true,true,false,0);
						effacerEcran();
						initWifi();
						sortieBoucle = true;
					}
					else {
						AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
						afficherFenetre(0,message[lang][52]);
					}
					break;
					
					case 2:
					AS_SoundDefaultPlay((void*)ouvrir,171340,127,64,0,0);
					fadeBlack(1,true,true,false,0);
					effacerEcran();
					initCollection();
					sortieBoucle = true;
					break;
					
					case 3:
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					if (afficherFenetre(1,message[lang][66])) {
						nouvelleSauv();
						sauvegarder();
						sauvegarderBitmap(0);
						afficherFenetre(0,message[lang][67]);
					}
					break;
					
					default:
					break;
				}
			}
			if (Stylus.Newpress || Stylus.Held) {
				// 4 choix possible
				if (PA_StylusInZone(66,109,190,125) && (positionCurseur != 0)) {
					positionCurseur = 0;
					PA_SetSpriteY(0,0,112+18*positionCurseur);
				}
				else if (PA_StylusInZone(65,127,191,143) && (positionCurseur != 1)) {
					positionCurseur = 1;
					PA_SetSpriteY(0,0,112+18*positionCurseur);
				}
				else if (PA_StylusInZone(65,145,191,161) && (positionCurseur != 2)) {
					positionCurseur = 2;
					PA_SetSpriteY(0,0,112+18*positionCurseur);
				}
				else if (PA_StylusInZone(65,163,191,179) && (positionCurseur != 3)) {
					positionCurseur = 3;
					PA_SetSpriteY(0,0,112+18*positionCurseur);
				}
			}
			if (Stylus.Released) {
				// 4 choix possible
				if (PA_StylusInZone(66,109,190,125)) {
					AS_SoundDefaultPlay((void*)ouvrir,171340,127,64,0,0);
					fadeBlack(1,true,true,false,0);
					effacerEcran();
					initAventure();
					break;
				}
				else if (PA_StylusInZone(65,127,191,143)) {
					if (getNombreCarte(1,1,10) > 4) {
						AS_SoundDefaultPlay((void*)ouvrir,171340,127,64,0,0);
						fadeBlack(1,true,true,false,0);
						effacerEcran();
						initWifi();
						sortieBoucle = true;
					}
					else {
						AS_SoundDefaultPlay((void*)erreur,43404,127,64,0,0);
						afficherFenetre(0,message[lang][52]);
					}
				}
				else if (PA_StylusInZone(65,145,191,161)) {
					AS_SoundDefaultPlay((void*)ouvrir,171340,127,64,0,0);
					fadeBlack(1,true,true,false,0);
					effacerEcran();
					initCollection();
					sortieBoucle = true;
				}
				else if (PA_StylusInZone(65,163,191,179)) {
					AS_SoundDefaultPlay((void*)choix,15984,127,64,0,0);
					if (afficherFenetre(1,message[lang][66])) {
						nouvelleSauv();
						sauvegarder();
						sauvegarderBitmap(0);
						afficherFenetre(0,message[lang][67]);
					}
				}
			}
			if (sortieBoucle) {
				break;
			}
			PA_CheckLid();
			PA_WaitForVBL();
		}
	}
}
