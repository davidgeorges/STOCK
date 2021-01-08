

//Debut fonction danger
function danger(){
    var myElement = document.getElementById("message");
    myElement.innerHTML = "<div class='alert alert-danger'><strong>Attention</strong>  danger ! </div>" 
}

//Debut fonction warning
function warning(){
    var myElement = document.getElementById("message");
    myElement.innerHTML = "<div class='alert alert-warning'> <strong >Danger</strong> potentiel, soyez prudent </div>"
}


//Debut fonction success
function success(){
    var myElement = document.getElementById("message");
    myElement.innerHTML = "<div class='alert alert-success'> <strong >Succès</strong>, tout va bien </div>"
}

//Debut fonction primary
function primary(){
    var myElement = document.getElementById("message");
    myElement.innerHTML = "<div class='alert alert-info'> <strong >Information</strong>, veuillez-vous rapporter à la documentation </div>"
}


//Debut fonction normal (et par default on appel cette fonction)
function normal(){  
    var myElement = document.getElementById("message");
    myElement.innerHTML = "<div class='well'>Aucune information particulière </div>"
}


