TARGET = bin/main.exe  # Définir la cible (le fichier exécutable)
CC = gcc	# Définir la varibale pour la compilation
CFLAGS = -Wall -g -Wextra	# Définir les options de compilation

#Définir les variables contenant les repertoires 

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.c) # Récuperer tous les fichiers .c du dossier SRC
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS)) # Transformer la liste .c en .o et les stocker dans le repetoire build

all : $(TARGET) # Exécuter make par défaut 

$(TARGET) : $(OBJS) | $(BIN_DIR) # Création de l'exécutable et du repertoire bin s'il n'existe pas 
	$(CC) $(CFLAGS) -o $@ $^ 

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c | $(BUILD_DIR) # Génération des .o et du repertoire build s'il n'existe pas
	$(CC) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR) :	#Creation du build
	mkdir -p $(BUILD_DIR)

$(BIN_DIR) : #Creation du bin 
	mkdir -p $(BIN_DIR)

clean :	# Supprimer les fichiers .o et l'executable
	rm -f $(BUILD_DIR)/*.o $(TARGET)
