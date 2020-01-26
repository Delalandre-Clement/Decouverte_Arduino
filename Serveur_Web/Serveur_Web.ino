
// Elements pour la connection ethernet (serveur web)
#include "SPI.h"
#include "Ethernet.h"
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 200); // Adresse IP du serveur web de l'arduino sur le réseau local
EthernetServer local_server(80);  // creation d'un serveur web sur le port standard 80

void setup() 
{
    Ethernet.begin(mac, ip);  // Initialize l'arduino comme un élément du réseau local
    local_server.begin();     // Se met à l'écoute des communications client (browser web)
}

void loop() 
{
    respond_local_server();
}

void respond_local_server()
{
    EthernetClient local_client = local_server.available();

    if (local_client) 
    {  
        boolean currentLineIsBlank = true;
        while (local_client.connected()) // tant qu'un client est connecté
        {
            if (local_client.available()) // Si un client a envoyé une requête
            {   
                char c = local_client.read(); // lire un caractère du client
                if (c == '\n' && currentLineIsBlank) // Quand la dernière ligne envoyée par le client est vide et suivi de \n on va lui répondre
                {
                    // On envoie un entête http standard en réponse
                    local_client.println("HTTP/1.1 200 OK");
                    local_client.println("Access-Control-Allow-Origin: *");
                    local_client.println("Content-Type: application/json");
                    local_client.println("Connection: close");
                    local_client.println();
                    
                    char sPostData[150] = "Coucou";
                    local_client.println(sPostData);

                    break;
                }
                
                // every line of text received from the client ends with \r\n
                if (c == '\n') // Si le caractère reçu est \n on positionne la variable currentLineIsBlank à vrai
                    currentLineIsBlank = true;
                else 
                    if (c != '\r') // Si le caractère reçu est \r on positionne la variable currentLineIsBlank à faux
                        currentLineIsBlank = false;
            } 
        } 
        
        delay(1000);      // On laisse 1s au browser pour récupérer les données qu'on a envoyées
        local_client.stop(); // ferme la connection
    }
}
