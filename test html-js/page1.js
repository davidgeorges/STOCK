//Declaration variable et Initialisation
var vote =false;
var nb1=0;
var nb2=0;
var nb3=0;

var bouton1 = () =>{
    console.log("pour");
    if(vote){
        nb1++;
        document.querySelector('#b1').innerText = `${nb1}`
        // on écrit a la balise b1 la valeur de nb1
    }
}

var bouton2 = () =>{
    console.log("contre");
    if(vote){
        nb2++;
        document.querySelector('#b2').innerText = `${nb2}`
        // on écrit a la balise b2 la valeur de nb2
    }
}

var bouton3 = () =>{
    console.log("absentention");
    if(vote){
        nb3++;
        document.querySelector('#b3').innerText = `${nb3}`
        // on écrit a la balise b3 la valeur de nb3
     }
}

var stp1 = () =>{
    console.log("ouvert");
    vote = true;
    document.querySelector('#v1').innerText = `-vote en cours-`
    document.querySelector('#v2').innerText = `-vote en cours-`
}

var stp2 = () =>{
    console.log("fermé");
    vote = false;
    document.querySelector('#v1').innerText = `-vote fermé-`
    document.querySelector('#v2').innerText = `-vote fermé-`
}

/*
// si vote = false on ecrit vote fermé  
if(vote == 0){
    //écrire²   
    document.querySelector('#v1').innerText = "-vote fermé -";
    document.querySelector('#v2').innerText = "-vote fermé -";
}

// Fonctioner voter qui prend la fonction onclick et qui fait un code selon le bouton cliquer
let voter= () =>{
    // des qu'on clique sur (pour)
    document.getElementById('bt1').onclick = () => {
        if(vote){
            nb1++;
            document.querySelector('#b1').innerText = `${nb1}`
            // on écrit a la balise b1 la valeur de nb1
        }
     };
     
     // des qu'on clique sur (contre)
     document.getElementById('bt2').onclick = () => {
        if(vote){
            nb2++;
            document.querySelector('#b2').innerText = `${nb2}`
            // on écrit a la balise b2 la valeur de nb2
        }
    
     };
     
     // des qu'on clique sur (blanc)
     document.getElementById('bt3').onclick = () => {
        if(vote){
        nb3++;
            document.querySelector('#b3').innerText = `${nb3}`
            // on écrit a la balise b3 la valeur de nb3
        }
     };
     
     // si vote = true on ecrit vote ouvert
     document.getElementById('stp1').onclick = () => {
        vote = true;
        document.querySelector('#v1').innerText = `-vote en cours -`
        document.querySelector('#v2').innerText = `-vote en cours -`
        // on écrit a la balise v1 et v2 la valeur vote en cours
        
     };
    
     // si vote = false on ecrit vote fermé
     document.getElementById('stp2').onclick = () => {
        vote = false;
        document.querySelector('#v1').innerText = `-vote fermé -`
        document.querySelector('#v2').innerText = `-vote fermé -`
        // on écrit a la balise v1 et v2 la valeur vote fermé
     };
    };



voter();// appel de la fonction
*/