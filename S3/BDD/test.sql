-- Création de la base de données
CREATE DATABASE agence_voyage;
USE agence_voyage;

-- Table CLIENT
CREATE TABLE CLIENT (
    NumCli INT AUTO_INCREMENT PRIMARY KEY,
    Nom VARCHAR(50) NOT NULL,
    Prénom VARCHAR(50) NOT NULL,
    e_mail VARCHAR(50) NOT NULL,
    NumCB VARCHAR(20)
);

-- Table VOYAGE
CREATE TABLE VOYAGE (
    CodeVoyage INT AUTO_INCREMENT PRIMARY KEY,
    Destination VARCHAR(50) NOT NULL,
    Durée INT NOT NULL,
    Prix DECIMAL(10, 2) NOT NULL
);

-- Table RESERVATION
CREATE TABLE RESERVATION (
    NumCli INT NOT NULL,
    CodeVoyage INT NOT NULL,
    DateRes DATE NOT NULL,
    PRIMARY KEY (NumCli, CodeVoyage),
    FOREIGN KEY (NumCli) REFERENCES CLIENT(NumCli) ON DELETE CASCADE,
    FOREIGN KEY (CodeVoyage) REFERENCES VOYAGE(CodeVoyage) ON DELETE CASCADE
);

-- Table CLIENT
INSERT INTO CLIENT (NumCli, Nom, Prénom, e_mail, NumCB) VALUES
(1, 'Dupont', 'Jean', 'jean.dupont@example.com', '1234567890123456'),
(2, 'Martin', 'Sophie', 'sophie.martin@example.com', '2345678901234567'),
(3, 'Durand', 'Paul', 'paul.durand@example.com', '3456789012345678'),
(4, 'Leroy', 'Alice', 'alice.leroy@example.com', '4567890123456789'),
(5, 'Bernard', 'Claire', 'claire.bernard@example.com', '5678901234567890'),
(6, 'Rousseau', 'Emma', 'emma.rousseau@example.com', '6789012345678901'),
(7, 'Petit', 'Lucas', 'lucas.petit@example.com', '7890123456789012'),
(8, 'Morel', 'Elodie', 'elodie.morel@example.com', '8901234567890123'),
(9, 'Simon', 'Maxime', 'maxime.simon@example.com', '9012345678901234'),
(10, 'Fabre', 'Manon', 'manon.fabre@example.com', '0123456789012345');

-- Table VOYAGE
INSERT INTO VOYAGE (CodeVoyage, Destination, Durée, Prix) VALUES
(1, 'Paris', 3, 150.00),
(2, 'Londres', 5, 300.00),
(3, 'Tokyo', 10, 1200.00),
(4, 'New York', 7, 1000.00),
(5, 'Rome', 4, 250.00),
(6, 'Berlin', 3, 200.00),
(7, 'Madrid', 4, 220.00),
(8, 'Sydney', 12, 1800.00),
(9, 'Bangkok', 8, 900.00),
(10, 'Dubai', 6, 800.00);

-- Table RESERVATION
INSERT INTO RESERVATION (NumCli, CodeVoyage, DateRes) VALUES
(1, 1, '2024-11-25'), -- Réservation en cours
(2, 2, '2024-12-01'), -- Réservation en cours
(3, 3, '2024-11-28'), -- Réservation en cours
(4, 4, '2023-11-15'), -- Ancienne réservation
(5, 5, '2023-10-01'), -- Ancienne réservation
(6, 6, '2024-11-30'), -- Réservation en cours
(7, 7, '2023-12-15'), -- Ancienne réservation
(8, 8, '2024-01-01'), -- Réservation future
(9, 9, '2024-11-26'), -- Réservation en cours
(10, 10, '2023-09-01'); -- Ancienne réservation


select Nom, Prénom, e_mail 
from CLIENT, RESERVATION
where DateRes >= curdate();

select Nom, Prénom, e_mail
from CLIENT 
where not exists ( select Numcli from RESERVATION 
						  where RESERVATION.NumCli = CLIENT.NumCli
                          and DateRes >= curdate());
                          
select Nom, Prénom, e_mail, Destination 
from Client as c, RESERVATION as r, VOYAGE as v
where c.NumCli = r.NumCli
and v.CodeVoyage = r.CodeVoyage
and v.Durée > 10
and v.Prix < 200;

select * from CLIENT;
select * from RESERVATION;
select * from VOYAGE;



