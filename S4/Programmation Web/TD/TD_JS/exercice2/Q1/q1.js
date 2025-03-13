function moyenne(tab)
{
    var m = 0.0;
    for (let i = 0; i < tab.length; i++) m += tab[i];

    return(m / tab.length);
}

var t = [12.0, 14.0, 18.0, 12.0, 9.0];
let moy = moyenne(t);
alert(moy.toFixed(2));