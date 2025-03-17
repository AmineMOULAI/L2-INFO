var film_info = prompt("Entrer les informations du film"),
array = film_info.split(' ');

var film = {};
film.titre = array[0];
film.realisateur = array[1];
film.annee = new Date(array[2]);

alert("Le film " + film.titre + " a été réalisé en " + film.annee.getFullYear() + " par " + film.realisateur);
