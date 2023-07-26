#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3


#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2


#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
* struct liststr - list
* @num: the nufield
* @str: ang
* @next: points node
*/
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
* struct passinfo - contains pseudo-arction
* @arg: a string generated froments
* @argv: an array rom arg
* @path: a string pathmmand
* @argc: the aennt
* @line_count: tt
* @err_num: the errorxit()s
* @linecount_flag: if on count t
* @fname: the progrme
* @env: liron
* @environ: custom modified copv
* @history: the ode
* @alias: the e
* @env_changed: on if ed
* @status: the return sta
* @cmd_buf: address of poinon if chaining
* @cmd_buf_type: CMD_ ||, &&, ;
* @readfd: the fd froh to
* @histcount: the history l
*/
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} io_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
* struct builtin - contains ction
* @type: the builtin com
* @func: the fun
*/
typedef struct builtin
{
	char *type;
	int (*func)(io_t *);
} builtin_table;


/* _shellloop.c */
int hsh(io_t *io, char **v);
int fnd_builtin(io_t *io);
void find_cmd(io_t *io);
void fork_cmd(io_t *io);

/* par_ser.c */
int _iscmd(io_t *io, char *pth);
char *_dupchars(char *pthstr, int star, int stp);
char *_findpath(io_t *io, char *pthstr, char *cmd);

/* loophsh.c */
int loophsh(char **);

/* error.c */
void eputting(char *str);
int putting_charact(char k);
int put_fd(char k, int cod);
int puts_fd(char *str, int cod);

/* string.c */
int str_len(char *x);
int str_comp(char *x1, char *x2);
char *starts_with(const char *hatack, const char *nele);
char *str_cat(char *dest, char *src);

/* string_1.c */
char *str_cpy(char *dest, char *src);
char *str_dup(const char *str);
void putter(char *str);
int _putchar(char k);

/*exiting.c */
char *strn_cpy(char *det, char *srct, int u);
char *strn_cat(char *det, char *srct, int u);
char *str_chr(char *x, char k);

/* token_izer.c */
char **str_tow(char *str, char *p);
char **str_tow2(char *str, char p);

/* re_alloc.c */
char *_memset(char *x, char p, unsigned int u);
void ffree(char **bb);
void *_realloc(void *ptr, unsigned int _oldsize, unsigned int _newsize);

/* mem_ory.c */
int bfree(void **ptr);

/* interactive_test.c */
int intive(io_t *io);
int delimiter(char k, char *limit);
int alphabet(int k);
int strtoint(char *x);

/* errors1.c */
int errant(char *x);
void printed_errors(io_t *io, char *easter);
int _printed(int in, int cod);
char *conv_numb(long int numb, int bas, int flags);
void rem_comm(char *buff);

/*building.c */
int exiting_shell(io_t *io);
int changing_directory(io_t *io);
int changing_help(io_t *io);

/* building.c */
int his_tory(io_t *io);
int my_alias(io_t *io);

/*get_line.c */
ssize_t get_inp(io_t *io);
int _getline(io_t *io, char **ptrd, size_t *lent);
void sigint_Handler(int sign_num);

/* get_info.c */
void cl_info(io_t *io);
void s_info(io_t *io, char **ev);
void fr_info(io_t *io, int al);

/* environment.c */
char *get_envr(io_t *io, const char *nam);
int my_env(io_t *io);
int my_set_env(io_t *io);
int my_unset_env(io_t *io);
int popu_envr_list(io_t *io);

/* get_env.c */
char **get_envir(io_t *io);
int un_set_env(io_t *io, char *var);
int set_env(io_t *io, char *var, char *val);

/* his_tory.c */
char *get_his_tory_file(io_t *io);
int write_his_tory(io_t *io);
int read_his_tory(io_t *io);
int build_hist_list(io_t *io, char *buf, int line_count);
int re_number_history(io_t *io);

/* list_S.c */
list_t *_addnode(list_t **hed, const char *str, int numb);
list_t *add_node_ended(list_t **hed, const char *str, int numb);
size_t print_list_str(const list_t *n);
int delete_index(list_t **hed, unsigned int ind);
void fr_list(list_t **hed_ptr);

/* list_1.c */
size_t _listlen(const list_t *n);
char **list_to_strings(list_t *hed);
size_t print_list(const list_t *n);
list_t *node_startswith(list_t *nod, char *pref, char k);
ssize_t get_node(list_t *hed, list_t *nod);

/*_var_s.c */
int is_chin(io_t *io, char *buf, size_t *b);
void chk_chain(io_t *io, char *buf, size_t *b, size_t w, size_t len);
int replace_ali_as(io_t *io);
int rep_lace_vars(io_t *io);
int replace_string(char **od, char *nw);

#endif
