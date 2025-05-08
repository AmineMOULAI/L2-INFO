const canvas = document.getElementById("canvas");
const contexte = canvas.getContext('2d');
const Cx = canvas.height / 2;
const Cy = canvas.width / 2;

function dessine_aiguille(longueur, angle, thick)
{
    contexte.lineWidth = thick;
    contexte.beginPath();
    contexte.moveTo(Cx, Cy);

    const Px = Cx + longueur * Math.cos(angle * (Math.PI / 180)); 
    const Py = Cy + longueur * Math.sin(angle * (Math.PI / 180));
    
    contexte.lineTo(Px, Py)
    contexte.stroke()

}

function dessine_trait(longueur, angle, thick)
{
    contexte.lineWidth = thick;
    contexte.beginPath();

    const Px1 = Cx + (longueur - 20)  * Math.cos(angle * (Math.PI / 180)); 
    const Py1 = Cy + (longueur - 20)* Math.sin(angle * (Math.PI / 180));
    const Px = Cy + longueur * Math.cos(angle * (Math.PI / 180));
    const Py = Cy + longueur * Math.sin(angle * (Math.PI / 180));
    
    contexte.moveTo(Px, Py);
    contexte.lineTo(Px1, Py1)

    contexte.stroke()
    contexte.closePath();
}

function dessine_horloge() 
{
    contexte.lineWidth = 10;
    contexte.beginPath();
    contexte.arc(Cx, Cy, Cx - 10, 0, 2 * Math.PI, false);
    contexte.closePath();
    contexte.stroke()
    for (let i = 0; i < 360; i += 30) {
        dessine_trait(Cx - 20, i, 5);
    }

    const time = new Date();
    const h = time.getHours();
    const m = time.getMinutes();
    const s = time.getSeconds();
    const sec = (s * 6) - 90;
    const min = (m * 6) - 90;
    const hr = ((h % 12) * 30) - 90 ; 

    dessine_aiguille(Cx - 50, min, 10);
    dessine_aiguille(Cx - 80, hr, 10);
    dessine_aiguille(Cx - 20, sec, 3);
}


setInterval(() =>{
    contexte.clearRect(0, 0, canvas.width, canvas.height);
    dessine_horloge();
})



