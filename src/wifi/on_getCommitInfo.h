String on_getCommitInfo(){
    String answertoSend;
    answertoSend = "BuildDate= " + String(__DATE__) + " "  + String(__TIME__);
    answertoSend += ", - Commitpoint= " + String(AUTO_COMMITPT);
    return answertoSend;
}