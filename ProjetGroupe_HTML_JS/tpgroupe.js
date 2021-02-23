var mode = "";/*Pour recuperer la chaine passe a la fonction (si on appel la fonction pour le candidat ,l'examinateur  ou pour stoper l'epreuve)*/
var secondeCandi = 0;/*Compteur des seconde pour le candidat*/
var secondeExam = 0;/*Compteur des seconde pour l'examinateur*/
var secondeTotal = 0;/*Compteur des seconde total de l'épreuve*/
var minuteCandi = 0;/*Compteur des minutes pour le candidat*/
var minuteExam  = 0;/*Compteur des minutes pour l'examinateur*/
var minuteTotal = 0;/*Compteur des minutes total de l'épreuve*/
var myVar;
var myVar2;





/*Fonction qui va appeler la fonction correspondant au parametre (pour candi et exam la fonction va s'appeler tout les 1 secondes ) */
function typeOral(chaine) {

    /*on sauvergarde la chaine qu'ont a recu ( si c'est un candidat ou un examinateur ou si on arrete l'epreuve)*/
    mode = chaine;
    if(chaine == 'candi'){
        myVar = setInterval(comptCandi,1000);/*appel en tout les 1 seconde de la fonction compteCandi*/
    }

    if(chaine == "exam"){
        clearInterval(myVar);
        myVar2 = setInterval(comptExam,1000);/*appel en tout les 1 seconde de la fonction compteExam*/
    }

    /*Si on clique sur Stop Epreuve , nous arretons l'epreuve et affichons dans la console la durée total de l'épreuve*/
    if(chaine == "stop"){

        clearInterval(myVar2);
        console.log("Arret de l'examen , temps total : "+minuteTotal+" minute et "+secondeTotal+" seconde.");
    }

    /*pour faciliter la lecture et voir le fonctionnement on écrit ce bout de code*/
    console.log("Passage en mode : " +mode );
}



/*Fonction pour le compteur Candidat/
/* on ne compte pas le temps total , sachant que le candidat passe toujours en, premier le temps total est egal a celui du candidat seulement pour le passage du candidat*/
function comptCandi(){
    if(mode == 'candi' && minuteCandi <15){

        /*on recupere les id*/
        element = document.getElementById("comptCandi");
        element2 = document.getElementById("comptTotal");

        /*incrementation du compteur seconde pour le candidat*/
        secondeCandi++;

        /* Block ------------------------------------------------------ */

         /*toute les minutes on increment minuteCandi de 1 et on remet les secondeCandi a 0*/
        if(secondeCandi%60 ==0){
            minuteCandi ++
            secondeCandi =0;

            /*En commentaire pour le projet final car ceci sont des aides pour voir le bon  déroulement du code*/
            //console.log("Passage minute et remise seconde a zero pour le candidat");
        }

         /*si minutes supérieur a 0 on affiche la même chose dans la section du stage par candidtat et durée total de l'épreuve*/
        if(minuteCandi >0){
            element.innerHTML= minuteCandi+" min et "+secondeCandi+"s"/*on affiche les minute et seconde pour le candi*/
            element2.innerHTML= minuteCandi +" min et "+secondeCandi+"s"/*on affiche les minute et seconde pour le temps total*/
        }else{/*si minutes pas supérieur a 0 on affiche seulement les seconde pour le candidat et la durée total de l'épreuve*/
            element.innerHTML= secondeCandi+"s"/*on affiche les secondes pour le candi*/
            element2.innerHTML= secondeCandi+"s"/*on affiche  les seconde pour le temps total

        /* Block ------------------------------------------------------ */
        }
        
        /*ici on récupère les minute du candidat et les seconde pour afficher correctement la durée total de l'épreuve lors du passage de l'examinateur*/
        minuteTotal=minuteCandi;
        secondeTotal=secondeCandi;
        
    }else{
        console.log("Erreur de parametre ou le candidat est deja passé ou le temps passé du candidat est supérieur a 15 minutes.");
    }
       

    

}


/*Fonction pour le compteur Examen*/
/*compte les minutes et seconde pour l'examen et le temps total (minute candidat + minute examinateur et seconde candidat et seconde examinateur)*/
function comptExam(){
    if(mode == 'exam' && minuteExam <15){

        /*on recupere les id*/
        element = document.getElementById("comptExam");
        element2 = document.getElementById("comptTotal");

        /*incrementation du compteur seconde pour l'examinateur*/
        secondeExam++;
    
        
        /*Calcul du temps total*/
        secondeTotal=secondeCandi+secondeExam;

        /*Calcul de la minute si seconde ==60 */
        if(secondeTotal%60 ==0){
            minuteTotal++;
            secondeTotal=0;

            /*En commentaire pour le projet final car ceci sont des aides pour voir le bon  déroulement du code*/
            //console.log("Passage minute et remise seconde a zero pour le temps total");
        }else{
            secondeTotal = secondeTotal%60;
        }
        
        /* Block ------------------------------------------------------ */

        /*toute les minutes*/
        if(secondeExam%60 ==0){
            minuteExam ++
            secondeExam =0;
            
            /*En commentaire pour le projet final car ceci sont des aides pour voir le bon  déroulement du code*/
            //console.log("Passage minute et remise seconde a zero pour l'examinateur");
        }
        
        /*si minutes supérieur a 0*/
        if(minuteExam>0){
            element.innerHTML= minuteExam +" min et "+secondeExam+"s"/*on affiche seulement la minute et seconde pour l'exam*/
        }else{
            element.innerHTML= secondeExam+"s"/*on affiche seulement les secondes pour l'exam*/
        }

        element2.innerHTML= minuteTotal+" min et "+secondeTotal+"s";//affichage total

        /* Block ------------------------------------------------------ */

        

    }else{
        console.log("Erreur de parametre ou l'examinateur est deja passé ou  le temps passé de l'examinateur est supérieur a 15 minutes.");
    }
}

function afficheZero(nombre){
    return nombre <10 ? '0' + nombre : nombre;
}

function Heure(){
    const infos = new Date();
    document.getElementById('heure_exacte').innerHTML = ' ' + afficheZero(infos.getHours()) + ':' + afficheZero(infos.getMinutes());

    window.onload = function(){
       setInterval("Heure()",100);
    }
}

