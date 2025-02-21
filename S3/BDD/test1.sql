create database td2;

show databases;

use td2;

create table etudiant(
			numEtu int not null primary key auto_increment,
            nom varchar(50),
            prenom varchar(50)
            );
            
create table enseignant(
			numProf int not null primary key auto_increment,
            nom varchar(50),
            prenom varchar(50),
            age int,
            ville varchar(50)
            );
            
create table UE(
			codeUE int not null primary key auto_increment,
            libelle varchar(50),
            nb_heures int
            );

create table participe(
			numEtu int not null,
            codeUE int not null,
			noteCC float,
            noteexam float,
            primary key(numEtu, codeUE),
            foreign key(numEtu) references etudiant(numEtu),
            foreign key(codeUE) references UE(codeUE)
			);
            
alter table ue 
add numProf int;

alter table ue
add constraint numProf
foreign key(numProf) references enseignant(numProf)
on delete set null;

alter table enseignant modify ville varchar(55);

alter table etudiant 
add date_naissance date;

show create table participe;

alter table participe drop foreign key numEtu;

describe participe;

alter table enseignant drop age;

describe enseignant;

show create table ue;

alter table ue drop numProf;

drop table enseignant;

show tables;

show create table participe;





