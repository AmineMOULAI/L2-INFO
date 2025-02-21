DROP DATABASE IF EXISTS TD2;

CREATE DATABASE TD2;

USE TD2;

-- table Étudiant
CREATE TABLE Etudiant( 
numEtu INT PRIMARY KEY, 
nom VARCHAR(50) NOT NULL, 
prenom VARCHAR(50) NOT NULL
);

-- table UE
CREATE TABLE UE( 
codeUE CHAR(10) PRIMARY KEY, 
libelle VARCHAR(100) NOT NULL, 
nb_heures INT
);

-- table Enseignant
CREATE TABLE Enseignant( 
numProf INT PRIMARY KEY, 
nom VARCHAR(50) NOT NULL, 
prenom VARCHAR(50) NOT NULL, 
age INT, 
ville VARCHAR(50)
);

-- table Participe
CREATE TABLE Participe(
numEtu INT, 
codeUE CHAR(10), 
noteCC FLOAT DEFAULT 0, 
noteExam FLOAT DEFAULT 0, 
FOREIGN KEY(numEtu) REFERENCES Etudiant(numEtu), 
FOREIGN KEY(codeUE) REFERENCES UE(codeUE), 
PRIMARY KEY(numEtu, codeUE)
);

show tables;

insert into etudiant(numEtu, nom, prenom) values (1001, "nom1", "prénom1");
select * from etudiant;

insert into enseignant values (1, "Zucca", "Vincent", 32, "Perpignan");
select * from enseignant;

insert into ue values (2001, "Bases de données", 32);
select * from ue;

insert into participe values (1001, 2001, 10, 11);
select * from participe;

insert into etudiant(numEtu, nom, prenom) values (1002, "nom2", "prénom2");
select * from etudiant;

delete from etudiant 
where numEtu = 1002;

select * from etudiant;

show create table participe;
alter table participe drop foreign key participe_ibfk_1;

alter table participe 
add constraint fk_numEtu
foreign key (numEtu) references etudiant(numEtu)
on delete cascade;

show create table participe;



