var m1 = document.querySelector("#container1");
var m2 = document.querySelector("#container2");
var sm1 = document.querySelector("#sous-menu1");
var sm2 = document.querySelector("#sous-menu2");

var a1 = document.querySelector("#select-lapin");
var a2 = document.querySelector("#select-pomme");
var a3 = document.querySelector("#select-blabla");
var a4 = document.querySelector("#select-blibli");
var a5 = document.querySelector("#select-bloblo");

var article1 = document.querySelector("#lapin");
var article2 = document.querySelector("#pomme");
var article3 = document.querySelector("#blabla");
var article4 = document.querySelector("#blibli");
var article5 = document.querySelector("#bloblo");

var allArticles = document.querySelectorAll(".articles")


function hideMenu()
{
    sm1.style.display = 'none';
    sm2.style.display = 'none';
}

function showMenu(menu)
{
    menu.style.display = 'flex';
}

function hideArticles()
{
    allArticles.forEach(article => {
        article.style.display = 'none';
    })
}

function showArticle(article)
{
    article.style.display = 'block';
}

hideMenu();

m1.addEventListener("mouseover", () => {
    showMenu(sm1);
});


m1.addEventListener("mouseleave", () => {
    hideMenu(sm1);
});

m2.addEventListener("mouseover", () => {
    showMenu(sm2);
});


m2.addEventListener("mouseleave", () => {
    hideMenu(sm2);
});

a1.addEventListener("click", () => {
    hideArticles();
    showArticle(article1);
})

a2.addEventListener("click", () => {
    hideArticles();
    showArticle(article2);
})

a3.addEventListener("click", () => {
    hideArticles();
    showArticle(article3);
})

a4.addEventListener("click", () => {
    hideArticles();
    showArticle(article4);
})

a5.addEventListener("click", () => {
    hideArticles();
    showArticle(article5);
})

