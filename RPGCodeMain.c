#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct Node {
    char description[1500];
    struct Node* option1;
    struct Node* option2;
    struct Node* option3;
    int isDeath;
    int isCheckpoint; // Flag to indicate if this node is a checkpoint
    int isGameOver;
} Node;

// Function to create a new node
Node* createNode(const char* description, int isDeath, int isCheckpoint,int isGameOver) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->description,description,sizeof(newNode->description) - 1);
    newNode->description[sizeof(newNode->description) - 1] = '\0';
    newNode->option1 = NULL;
    newNode->option2 = NULL;
    newNode->option3 = NULL;
    newNode->isDeath = isDeath;
    newNode->isCheckpoint = isCheckpoint;
    newNode->isGameOver = isGameOver;
    return newNode;
}

// Function to add options to a node
void addOptions(Node* parent, Node* option1, Node* option2, Node* option3) {
    parent->option1 = option1;
    parent->option2 = option2;
    parent->option3 = option3;
}

Node* lastCheckpoint = NULL;

// Function to build the game tree
Node* buildGameTree() {
    // Create nodes
   Node* start = createNode("Caught in a fatal car crash, Vesemir blinked only to find himself in a realm where dragons roared and magic thrived.\n With a mysterious artifact in his hand, he realized he was destined to save this fantastical world.\nVesemir stood amidst the smoldering remains of a dense forest, the air thick with the scent of burnt wood and magic.\nThe ground trembled as a colossal dragon soared overhead, its roar echoing through the valley.\n Clutching the glowing artifact, Vesemir could feel its ancient power coursing through his veins.\n In the distance, a shadowy figure emerged from the trees, their eyes glinting with a mixture of curiosity and caution.\n\n1. Approach the shadowy figure and demand answers about the artifact.\n\n2. Explore the charred forest to search for clues about your new surroundings.\n\n3. Scream very loud holding the artifact.", 0, 1, 0);
Node* A = createNode("Vesemir faced a cloaked figure in the charred forest, clutching the glowing artifact. The figure's eyes gleamed. \"You hold the key to this world's fate. What will you do with it?\"\n\n1. Ask about the artifact's origins.\n\n2. Give the artifact back to the shadowy figure\n\n3. Propose an alliance to understand the artifact's power", 0, 0, 0);
Node* B = createNode("Vesemir wandered through the charred forest, the artifact glowing softly in his hand. Among the ashes, he spotted a hidden path leading deeper into the woods.\n\n1. Follow the hidden path\n\n2. Point the artifact to the hidden path.\n\n3. Climb a nearby tree to get a better view of the area", 0, 0, 0); 
Node* C = createNode("Vesemir screams very loudly, making the birds fly and the forest echo. But….nothing happened.", 1, 0, 0); // Death
Node* A1 = createNode("The cloaked figure's eyes gleamed. \"This artifact was forged by ancient mages to awaken the Guardians, protectors of our realm. Beware, dark forces seek its power.\"\n\n1. Teach Me Ancient Magic To Control This Artifact.\n\n2. Show Me To The Guardians\n\n3. Leave The Figure To Find The Dark Forces He Mentioned", 0, 1, 0);
Node* A2 = createNode("As Vesemir handed over the artifact, a sense of trust washed over him. But as the figure took it, Vesemir's vision blurred, and he collapsed. It was then he realized the artifact was keeping him alive.", 1, 0, 0); // Death
Node* A3 = createNode("Vesemir cautiously approached the figure, artifact in hand. \"What if we join forces to understand its power?\" The figure nodded in agreement. \"Together, we may Reawaken The Guardians to Stop The Drakkar.\"\n\n1) Follow The Figure To a Temple\n\n2) Ask the Figure to follow You To a Town\n\n3) Ask The Figure To Fight The Drakkar First", 0, 0, 0);
Node* B1 = createNode("As he stepped into the hidden path, the roads behind him got engulfed by trees and vines tied around his neck and he was strangled to death.", 1, 0, 0); // Death
Node* B2 = createNode("Vesemir gets spooked by a shadowy figure flying right at him. The shadowy figure touches the artifact and points into the hidden path. The artifact glows and embeds itself into the arm of Vesemir and the shadowy figure follows Vesemir.\n\n1. Rub the artifact gently\n\n2. Walk into the hidden path\n\n3. Try to get rid of the artifact", 0, 0, 0);
Node* B3 = createNode("Vesemir climbs a tree to spot a temple in the distance which can be reached through the hidden path.\n\n1. Walk around the hidden path towards the temple.\n\n2. Point the artifact to the hidden path.\n\n3. Throw the artifact into the hidden path.", 0, 0, 0);
Node* A1_1 = createNode("The cloaked figure placed a hand on Vesemir's forehead. \"Hold still,\" they whispered. Ancient magic surged into Vesemir, filling his mind with the artifact's secrets and the Guardians' power. Staggering back, Vesemir gasped, \"I understand now.\"\n\n1. Use The Power Of The Artifact On The Shadowy Figure\n\n2. Take Me To The Guardians\n\n3. Go to The Town Of Drakonis To Challenge The Dark Forces", 0, 0, 0); 
Node* A1_2 = createNode("Temple Comes alive And Eats You", 1, 0, 0); // Death
Node* A1_3 = createNode("Vesimir Dies In The Forest Trying To Find The Dark Forces Due To Dehydration", 1, 0, 0); // Death
Node* A3_1 = createNode("Temple Comes alive And Eats You", 1, 0, 0); // Death
Node* A3_2 = createNode("Vesemir turned to the figure. \"Follow me to the nearby town.\" In the dense forest, vines suddenly ensnared them. The living plants tightened their grip, pulling them into darkness. Vesemir struggled, but it was too late. The forest consumed them both.", 1, 0, 0); // Death
Node* A3_3 = createNode("Vesemir, filled with newfound knowledge, turned to the figure. \"Let's fight the Drakkar first.\" The figure nodded. \"Follow me.\" They arrived at the city-state of Drakonis, its towering walls and vigilant guards Protecting The City. Inside, the figure gestured to three paths.\n\n1. Scout Out The Drakkar Headquarters\n\n2. Sneak Into The Armoury Of Drakonis\n\n3. Contact The City Guards To Help Apprehend The Drakkar\n", 0, 1, 0);
Node* A1_1_1 = createNode("Vesimir, raises the artifact. Light erupts, blinding. He charges, aiming for the figures' heart. But the artifact… feeds it. The figure swells, monstrous. \nVesimir stumbles back, horror etched on his face. A scream, a lunge, silence. \nOnly ragged breaths, then stillness. The power he sought, his demise", 1, 0, 0); // Death
Node* A1_1_2 = createNode("Temple Comes alive And Eats You", 1, 0, 0); // Death
Node* A1_1_3 = createNode("Vesemir, filled with newfound knowledge, turned to the figure. \"Let's fight the Drakkar first.\" The figure nodded. \"Follow me.\" They arrived at the city-state of Drakonis, its towering walls and vigilant guards Protecting The City. Inside, the figure gestured to three paths.\n\n1. Scout Out The Drakkar Headquarters\n\n2. Sneak Into The Armoury Of Drakonis\n\n3. Contact The City Guards To Help Apprehend The Drakkar\n", 0, 0, 0);
Node* A3_3_1 = createNode("In Drakonis, Vesemir scouted the Drakkar headquarters. Hidden, he learned about the four head executives and their boss, the sorcerer Radovid. Armed with this intel, Vesemir planned his next move.\n\n1. Confront Radovid\n\n2. Attack The Executives\n\n3. Give The Info To The Guards\n", 0, 1, 0); // Checkpoint
Node* A3_3_2 = createNode("Under the cover of night, Vesemir sneaked into Drakonis' armory. He found two swords and a set of wolven fur armor.\n\n1. Try enchanting The Equipment Using Ancient Magic\n\n2. Go Confront The Drakkar\n\n3. Fight The Executive Of The Drakkar\n", 0, 1, 0); // Checkpoint
Node* A3_3_3 = createNode("The Gleaming guards, bastions of order Bring Vesemir To The Side And Their Stoic Expression shift into predatory smiles. \n Metal hands tighten on weapons. Vesimir's hand instinctively flies to his sword hilt, a futile gesture against the inevitable. Steel descends. Silence.", 1, 0, 0); // Death
Node* A3_3_1_1 = createNode("Stained glass sun splashed on the opulent hall. Radovid, the cruel leader of The Drakkar, sat under an iron crown. \nVesimir, challenged him. Laughter cut him short. Radovid, a blur, plunged a dagger into Vesimir's back.\n With The executives Following They Put 4 Swords Into vesemir's heart.", 1, 0, 0); // Death
Node* A3_3_1_2 = createNode("The chamber crumbles, choked by obsidian dust. The Executives lie still, victims of Vesimir's Ancient magic. Radovid awaits Behind The Blood Soaked Doors Of The Drakkar.\n\n1. Use Magic Against Radovid\n\n2. Run Away From Radovid\n\n3. Get The Shadowy Figure to Distract Radovid and Use Magic On Him\n", 0, 0, 0); 
Node* A3_3_1_3 = createNode("The Gleaming guards, bastions of order Bring Vesemir To The Side And Their Stoic Expression shift into predatory smiles.\n Metal hands tighten on weapons. Vesimir's hand instinctively flies to his sword hilt, a futile gesture against the inevitable. Steel descends. Silence.", 1, 0, 0); // Death
Node* A3_3_2_1 = createNode("Vesimir, a sword in hand, faced the inscription: \"Power for a Price.\" Ignoring the dread, he pricked his finger, blood dripping onto the blade. \nLaughter echoed, warping into promises of power. The blade writhed, pain lancing through Vesimir. He wasn't enchanting it, it was feeding. Panic.\n A scream swallowed by the wind. The blade, a hungry light, drained him. Silence. The price of power: his life.", 1, 0, 0); // Death
Node* A3_3_2_2 = createNode("Stained glass sun splashed on the opulent hall. Radovid, the cruel leader of The Drakkar, sat under an iron crown. Vesimir, challenged him. \nLaughter cut him short. Radovid, a blur, plunged a dagger into Vesimir's back. With The executives Following They Put 4 Swords Into Vesemir's heart.", 1, 0, 0); // Death
Node* A3_3_2_3 = createNode("In a dimly lit chamber, the player faces the imposing Executive of the Drakkar. Armed with two swords and Wolven Armor, they engage in a fierce battle. With swift strikes and deft maneuvers, the player overcomes the Executive's relentless assault, emerging victorious. With the Executive defeated, the player sets their sights on Radovid, the mastermind behind the Drakkar.\n\n1. Use Your witcher Training Against Radovid\n\n2. Run Away From Radovid\n\n3. Get The Shadowy Figure to Distract Radovid and Use Witcher Training On Him\n", 0, 0, 0);
Node* A3_3_1_2_1 = createNode("As Vesemir weaves ancient magic against Radovid, the sorcerer counters with his dark powers. In a fierce clash, Radovid's malevolent magic overwhelms Vesemir's ancient spells, ultimately leading to Vesemir's defeat and demise.\n\nThe chamber falls silent as Radovid stands victorious, his dark power reigning supreme over the fallen hero.", 1, 0, 0); // Death
Node* A3_3_1_2_2 = createNode("As Radovid's menacing presence draws near, the figure and the player sprint through corridors, with Radovid's dark magic close on their heels. Despite their best efforts, they find themselves cornered, the sorcerer's spell sealing their fate. \n\nThe figure and the player meet their tragic end at the hands of Radovid, their escape cut short by the sorcerer's relentless pursuit. Darkness descends as Radovid's laughter echoes through the chamber, marking a grim and final chapter.", 1, 0, 0); // Death
Node* A3_3_1_2_3 = createNode("The shadowy figure distracts Radovid as Vesemir engages the sorcerer with powerful magic. Despite Vesemir's fall in battle, the figure emerges to deliver a fatal blow to Radovid, ending his reign of darkness. \n\nVesemir's sacrifice is avenged, marking a significant turning point.", 0, 0, 1);//Game Over
Node* A3_3_2_3_1 = createNode("Empowered by his Witcher training, Vesemir confronts the malevolent sorcerer Radovid. Their clash of swords and dark magic fills the chamber with intense battle energy. \n\nIn a moment of courage, Vesemir stood against Radovid's overwhelming power. But Ultimately Fails To Withstand Radovid’s Magic.", 1, 0, 0); // Death
Node* A3_3_2_3_2 = createNode("As Radovid's menacing presence draws near, the figure and the player sprint through corridors, with Radovid's dark magic close on their heels. Despite their best efforts, they find themselves cornered, the sorcerer's spell sealing their fate. \n\nThe figure and the player meet their tragic end at the hands of Radovid, their escape cut short by the sorcerer's relentless pursuit. Darkness descends as Radovid's laughter echoes through the chamber, marking a grim and final chapter.", 1, 0, 0); // Death
Node* A3_3_2_3_3 = createNode("As Radovid faces off against Vesemir, the shadowy figure distracts the sorcerer, allowing Vesemir to unleash his Witcher training in a fierce duel. Despite Vesemir's sacrifice in the battle, the shadowy figure intervenes, ultimately dealing the fatal blow to Radovid, ending his tyranny. \n\n With Radovid defeated at the hands of the shadowy figure, Vesemir's legacy is avenged, marking a heroic moment in the chamber's history.", 0, 0, 1);//gameOver

    // Link nodes
    addOptions(start, A, B, C);
    addOptions(A, A1, A2, A3);
    addOptions(B, B1, B2, B3);
    addOptions(A1, A1_1, A1_2, A1_3);
    addOptions(A1_1, A1_1_1, A1_1_2, A1_1_3);
    addOptions(A1_1_3, A3_3_1, A3_3_2, A3_3_3);
    addOptions(A3, A3_1, A3_2, A3_3);
    addOptions(A3_3, A3_3_1, A3_3_2, A3_3_3);
    addOptions(A3_3_2, A3_3_2_1, A3_3_2_2, A3_3_2_3);
    addOptions(A3_3_1, A3_3_1_1, A3_3_1_2, A3_3_1_3);
    addOptions(A3_3_1_2, A3_3_1_2_1, A3_3_1_2_2, A3_3_1_2_3);
    addOptions(A3_3_2_3, A3_3_2_3_1, A3_3_2_3_2, A3_3_2_3_3);
    return start;
}

// Function to play the game
void playGame(Node* currentNode) {
    lastCheckpoint = currentNode; // Start at the first node, which is also the first checkpoint

    while (currentNode != NULL) {
        printf("%s\n", currentNode->description);
        if (currentNode->isDeath) {
            printf("\nYou have died. Game over.\n\n");
            printf("Restarting from the last checkpoint...\n\n");
            currentNode = lastCheckpoint;
            continue; // Restart the loop from the last checkpoint
        }

        if (currentNode->isCheckpoint) {
            lastCheckpoint = currentNode;
        }
        if (currentNode->isGameOver){
            printf("\nIn his final moments, Vesemir faced Radovid with unwavering determination. The battle was fierce, but Vesemir's sacrifice allowed the city of Drakonis to be saved. As Radovid fell, Vesemir succumbed to his wounds, knowing he had protected the city one last time.\n");
            printf("\nGame Over \n\nYou Reached The End\n\n");
            break;
        }
        printf("Choose an option:\n");
        printf("1. Option 1\n");
        printf("2. Option 2\n");
        printf("3. Option 3\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("clear");
                currentNode = currentNode->option1;
                break;
            case 2:
                system("clear");
                currentNode = currentNode->option2;
                break;
            case 3:
                system("clear");
                currentNode = currentNode->option3;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to free the memory allocated for the tree
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->option1);
    freeTree(root->option2);
    freeTree(root->option3);
    free(root);
}

// Main function 8=============D
int main() {
    Node* gameTree = buildGameTree();
    playGame(gameTree);
    freeTree(gameTree);
    return 0;
}