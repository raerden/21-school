mv door_management_fi door_management_files
cd door_management_files
mkdir door_configuration door_map door_logs
mv *.conf door_configuration
mv *.log door_logs
mv door_map_1.1 door_map
cd ..
chmod 777 ai_door_control.sh
bash ai_door_management_module.sh

