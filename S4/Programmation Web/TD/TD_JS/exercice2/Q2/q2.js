function moyenne(tab)
{
    var m = 0.0;
    for (let i = 0; i < tab.length; i++) m += tab[i];

    return(m / tab.length);
}

function ecart_type(tab)
{
    var m = moyenne(tab);
    var e = 0.0;
    alert(m.toFixed(2));

    for (let i = 0; i < tab.length; i++) {
        e += (tab[i] - m)*(tab[i] - m);
    }
    e = Math.sqrt(e / tab.length);
    return(e);
}

var t = [12.0, 14.0, 18.0, 12.0, 9.0, 23.5, 18.7];

var ecart = ecart_type(t);
alert(ecart.toFixed(2));