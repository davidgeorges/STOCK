//Declaration variable et Initialisation
var vote =false;
var secretVote=false;
var nb1=0;
var nb2=0;
var nb3=0;
var save = " ";

//Debut fonction Pour
function bouton1(){
    console.log("pour");
    if(vote){
        nb1++;
        var myElement = document.getElementById("b1");
        myElement.innerHTML = nb1;
        // on écrit a la balise b1 la valeur de nb1
    }
}
//Fin fonction

//Debut fonction contre
function bouton2(){
    console.log("contre");
    if(vote){
        nb2++;
        var myElement = document.getElementById("b2");
        myElement.innerHTML = nb2;
        // on écrit a la balise b2 la valeur de nb2
    }
}
//Fin fonction

//Debut fonction absentention
function bouton3 (){
    console.log("absentention");
    if(vote){
        nb3++;
        var myElement = document.getElementById("b3");
        myElement.innerHTML = nb3;
        // on écrit a la balise b3 la valeur de nb3
     }
}
//Fin fonction

//Debut fonction ouvert
function stop1(){
    console.log("ouvert");
    vote = true;
    var myElement = document.getElementById("v1");
    myElement.innerHTML = "-vote en cours-";
    var myElement2 = document.getElementById("v2");
    myElement2.innerHTML = "-vote en cours-";
}
//Fin fonction

//Debut fonction fermé
function stop2 (){
    console.log("fermé");
    vote = false;
    var myElement = document.getElementById("v1");
    myElement.innerHTML = "-vote fermé-";
    var myElement2 = document.getElementById("v2");
    myElement2.innerHTML = "-vote fermé-";
}
//Fin fonction

//Debut fonction vote  hand
function hand(){
  
   if(secretVote){
    var myElement = document.getElementById("sp1");
    myElement.innerHTML = save;
    secretVote = false;
    }
}
//Fin fonctionZ

//Debut fonction vote secret
function secret() {
    
    if(secretVote == false){
        save = document.getElementById("sp1").innerHTML;
        var myElement = document.getElementById("sp1");
        myElement.innerHTML = "<i class='fas fa-mask'></i> Vote secret <i class='fas fa-mask'></i> "
        console.log("save");
    }
    secretVote=true;    
}
//Fin fonction
