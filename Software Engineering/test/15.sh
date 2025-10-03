se2415 logout
read -p "Press any key to resume ..."

se2415 login --username admin --passw freepasses4all
read -p "Press any key to resume ..."

se2415 healthcheck
read -p "Press any key to resume ..."

se2415 resetpasses
read -p "Press any key to resume ..."

se2415 healthcheck
read -p "Press any key to resume ..."

se2415 resetstations
read -p "Press any key to resume ..."

se2415 healthcheck
read -p "Press any key to resume ..."

se2415 admin --addpasses --source passes15.csv
read -p "Press any key to resume ..."

se2415 healthcheck
read -p "Press any key to resume ..."

se2415 tollstationpasses --station AM08 --from 20220329 --to 20220412 --format json
read -p "Press any key to resume ..."

se2415 tollstationpasses --station NAO04 --from 20220329 --to 20220412 --format csv
read -p "Press any key to resume ..."

se2415 tollstationpasses --station NO01 --from 20220329 --to 20220412 --format csv
read -p "Press any key to resume ..."

se2415 tollstationpasses --station OO03 --from 20220329 --to 20220412 --format csv
read -p "Press any key to resume ..."

se2415 tollstationpasses --station XXX --from 20220329 --to 20220412 --format csv
read -p "Press any key to resume ..."

se2415 tollstationpasses --station OO03 --from 20220329 --to 20220412 --format YYY
read -p "Press any key to resume ..."

se2415 errorparam --station OO03 --from 20220329 --to 20220412 --format csv
read -p "Press any key to resume ..."

se2415 tollstationpasses --station AM08 --from 20220330 --to 20220410 --format json
read -p "Press any key to resume ..."

se2415 tollstationpasses --station NAO04 --from 20220330 --to 20220410 --format csv
read -p "Press any key to resume ..."

se2415 tollstationpasses --station NO01 --from 20220330 --to 20220410 --format csv
read -p "Press any key to resume ..."

se2415 tollstationpasses --station OO03 --from 20220330 --to 20220410 --format csv
read -p "Press any key to resume ..."

se2415 tollstationpasses --station XXX --from 20220330 --to 20220410 --format csv
read -p "Press any key to resume ..."

se2415 tollstationpasses --station OO03 --from 20220330 --to 20220410 --format YYY
read -p "Press any key to resume ..."

se2415 passanalysis --stationop AM --tagop NAO --from 20220329 --to 20220412 --format json
read -p "Press any key to resume ..."

se2415 passanalysis --stationop NAO --tagop AM --from 20220329 --to 20220412 --format csv
read -p "Press any key to resume ..."

se2415 passanalysis --stationop NO --tagop OO --from 20220329 --to 20220412 --format csv
read -p "Press any key to resume ..."

se2415 passanalysis --stationop OO --tagop KO --from 20220329 --to 20220412 --format csv
read -p "Press any key to resume ..."

se2415 passanalysis --stationop XXX --tagop KO --from 20220329 --to 20220412 --format csv
read -p "Press any key to resume ..."

se2415 passanalysis --stationop AM --tagop NAO --from 20220330 --to 20220410 --format json
read -p "Press any key to resume ..."

se2415 passanalysis --stationop NAO --tagop AM --from 20220330 --to 20220410 --format csv
read -p "Press any key to resume ..."

se2415 passanalysis --stationop NO --tagop OO --from 20220330 --to 20220410 --format csv
read -p "Press any key to resume ..."

se2415 passanalysis --stationop OO --tagop KO --from 20220330 --to 20220410 --format csv
read -p "Press any key to resume ..."

se2415 passanalysis --stationop XXX --tagop KO --from 20220330 --to 20220410 --format csv
read -p "Press any key to resume ..."

se2415 passescost --stationop AM --tagop NAO --from 20220329 --to 20220412 --format json
read -p "Press any key to resume ..."

se2415 passescost --stationop NAO --tagop AM --from 20220329 --to 20220412 --format csv
read -p "Press any key to resume ..."

se2415 passescost --stationop NO --tagop OO --from 20220329 --to 20220412 --format csv
read -p "Press any key to resume ..."

se2415 passescost --stationop OO --tagop KO --from 20220329 --to 20220412 --format csv
read -p "Press any key to resume ..."

se2415 passescost --stationop XXX --tagop KO --from 20220329 --to 20220412 --format csv
read -p "Press any key to resume ..."

se2415 passescost --stationop AM --tagop NAO --from 20220330 --to 20220410 --format json
read -p "Press any key to resume ..."

se2415 passescost --stationop NAO --tagop AM --from 20220330 --to 20220410 --format csv
read -p "Press any key to resume ..."

se2415 passescost --stationop NO --tagop OO --from 20220330 --to 20220410 --format csv
read -p "Press any key to resume ..."

se2415 passescost --stationop OO --tagop KO --from 20220330 --to 20220410 --format csv
read -p "Press any key to resume ..."

se2415 passescost --stationop XXX --tagop KO --from 20220330 --to 20220410 --format csv
read -p "Press any key to resume ..."

se2415 chargesby --opid NAO --from 20220329 --to 20220412 --format json
read -p "Press any key to resume ..."

se2415 chargesby --opid GE --from 20220329 --to 20220412 --format csv
read -p "Press any key to resume ..."

se2415 chargesby --opid OO --from 20220329 --to 20220412 --format csv
read -p "Press any key to resume ..."

se2415 chargesby --opid KO --from 20220329 --to 20220412 --format csv
read -p "Press any key to resume ..."

se2415 chargesby --opid NO --from 20220329 --to 20220412 --format csv
read -p "Press any key to resume ..."

se2415 chargesby --opid NAO --from 20220330 --to 20220410 --format json
read -p "Press any key to resume ..."

se2415 chargesby --opid GE --from 20220330 --to 20220410 --format csv
read -p "Press any key to resume ..."

se2415 chargesby --opid OO --from 20220330 --to 20220410 --format csv
read -p "Press any key to resume ..."

se2415 chargesby --opid KO --from 20220330 --to 20220410 --format csv
read -p "Press any key to resume ..."

se2415 chargesby --opid NO --from 20220330 --to 20220410 --format csv