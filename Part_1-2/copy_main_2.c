/*
 * Copy this code in the main to get the log.txt file(s)  (THEY ALREADY EXISTS)
 * Then exploit the data on Matlab (.mlx file included in the the directory)

int main() {

    lvl_list *list;
    FILE *log_file = fopen("log.txt", "w");
    char format[] = "%d\t%s\t%s\n";
    int level, nbsearches = 100000;
    char *time_lvl0;
    char *time_all_levels;
    for(level=7; level<16; level++) {
        // List building
        list = build_test_list(level);
        int nbvals = powint(2, level)-1;
        // Record for search_zero
        startTimer();
        for(int i=0; i<nbsearches; i++) {
            search_zero(*list, rand()%nbvals+1);
        }
        stopTimer();
        time_lvl0 = getTimeAsString();
        // Record for search_lvls
        startTimer();
        for(int i=0; i<nbsearches; i++) {
            search_lvls(*list, rand()%nbvals+1);
        }
        stopTimer();
        time_all_levels = getTimeAsString();
        // Print the line on the .txt file
        fprintf(log_file,format,level,time_lvl0, time_all_levels);
    }
    fclose(log_file);


    return 0;
}

 */