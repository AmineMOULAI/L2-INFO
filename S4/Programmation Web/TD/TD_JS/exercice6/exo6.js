var tab = ["poire", "orange", "raisin", "fruit"];

p = document.getElementById("enum");
pinv = document.getElementById("enum_inv");
l = document.getElementById("list");
display()
a = document.getElementById("push");
a.addEventListener("click", (event) =>{
    w = prompt("Entrer un fruit : ");
    tab.push(w);
    display()
})


b = document.getElementById("pop");
b.addEventListener("click", (event) =>{
    tab.pop();
    display()
})

c = document.getElementById("shift");
c.addEventListener("click", (event) =>{
    tab.shift();
    display()
})

d = document.getElementById("reverse");
d.addEventListener("click", (event) =>{
    tab.reverse();
    display()
})

function display()
{
    p.innerText = ""
    p.innerText = tab.join(" ");
    pinv.innerText = "" 
   
    pinv.innerText =[...tab].reverse().join(" ")
    l.innerHTML = ""
    tab.forEach(element =>{
        let new_li = document.createElement("li");
        new_li.innerText = element; 
        l.appendChild(new_li);
    });
}