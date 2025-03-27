function print(p)
{
    var t = document.getElementsByTagName("*");
    for(let i = 0;i < p;i++)
        document.writeln(t[i].nodeName)
    document.write("<br><br>")
}

function print_row(p)
{
    var t = document.getElementsByTagName("*");
    for(let i = 0;i < p;i++)
        document.writeln("Balise" + i + " " +t[i].nodeName, "<br>")
}
var p = 4;
print(p)
print_row(p)