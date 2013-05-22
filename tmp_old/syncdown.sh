#!/bin/bash
rsync -avz --progress --partial csam4616@zid-gpl.uibk.ac.at:/afs/zid1.uibk.ac.at/home/csam/csam4616/Bachelorarbeit/thesis/* /u3/g/kell3040/Studying/Bachelor-thesis/thesis/
rsync -avz --progress --partial csam4616@zid-gpl.uibk.ac.at:/afs/zid1.uibk.ac.at/home/csam/csam4616/Bachelorarbeit/final-presentation/* /u3/g/kell3040/Studying/Bachelor-thesis/final-presentation/
chmod -R 755 /u3/g/kell3040/Studying/Bachelor-thesis/*
chown -R kell3040:users /u3/g/kell3040/Studying/Bachelor-thesis/*
