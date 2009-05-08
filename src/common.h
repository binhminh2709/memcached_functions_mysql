/* Common definitions for all functions */
#include <libmemcached/memcached.h>
#define VERSION_STRING "0.9"
#define VERSION_STRING_LENGTH 3 
#define MEMC_UDF_MAX_SIZE 256*256
#define ERRMSG_SIZE 1000

int memc_get_servers(memcached_st *memc);
memcached_st *memc_get_master();
int memc_master_lock();
int memc_master_unlock();

typedef struct memc_function_st memc_function_st;
struct memc_function_st {
  unsigned int offset;
  time_t expiration;
  memcached_st memc;
  memcached_result_st results;
  memcached_string_st *stats_string;

};
memc_function_st *prepare_args(UDF_ARGS *args,
                  char *message, int func_name,
                  uint min_args, uint max_args);

#define ERR_MSG "At least %d arguments must be specified: %s ";

typedef enum {
  MEMC_GET,
  MEMC_GET_BY_KEY,
  MEMC_SET,
  MEMC_SET_BY_KEY,
  MEMC_ADD,
  MEMC_ADD_BY_KEY,
  MEMC_REPLACE,
  MEMC_REPLACE_BY_KEY,
  MEMC_DELETE,
  MEMC_DELETE_BY_KEY,
  MEMC_APPEND,
  MEMC_APPEND_BY_KEY,
  MEMC_CAS,
  MEMC_CAS_BY_KEY,
  MEMC_PREPEND,
  MEMC_PREPEND_BY_KEY,
  MEMC_STATS,
  MEMC_STATS_GET_KEYS,
  MEMC_STATS_GET_VALUE,
  MEMC_LIST_BEHAVIORS,
  MEMC_SERVERS_SET,
  MEMC_SERVERS_COUNT,
  MEMC_SERVERS_BEHAVIOR_SET,
  MEMC_INCREMENT,
  MEMC_DECREMENT,
  MEMC_PREFIX_SET,
  MEMC_PREFIX_GET,
} memcached_udf_function;


/*
  I would like some dynamic way of doing this - obtaining this from libmemcached
*/
#define BEHAVIORS_STRING "\nMEMCACHED SERVER BEHAVIORS\nMEMCACHED_BEHAVIOR_SUPPORT_CAS\nMEMCACHED_BEHAVIOR_NO_BLOCK\nMEMCACHED_BEHAVIOR_TCP_NODELAY\nMEMCACHED_BEHAVIOR_HASH\nMEMCACHED_BEHAVIOR_CACHE_LOOKUPS\nMEMCACHED_BEHAVIOR_SOCKET_SEND_SIZE\nMEMCACHED_BEHAVIOR_SOCKET_RECV_SIZE\nMEMCACHED_BEHAVIOR_BUFFER_REQUESTS\nMEMCACHED_BEHAVIOR_KETAMA\nMEMCACHED_BEHAVIOR_POLL_TIMEOUT\nMEMCACHED_BEHAVIOR_RETRY_TIMEOUT\nMEMCACHED_BEHAVIOR_DISTRIBUTION\nMEMCACHED_BEHAVIOR_BUFFER_REQUESTS\nMEMCACHED_BEHAVIOR_USER_DATA\nMEMCACHED_BEHAVIOR_SORT_HOSTS\nMEMCACHED_BEHAVIOR_VERIFY_KEY\nMEMCACHED_BEHAVIOR_CONNECT_TIMEOUT\nMEMCACHED_BEHAVIOR_KETAMA_WEIGHTED\nMEMCACHED_BEHAVIOR_KETAMA_HASH\nMEMCACHED_BEHAVIOR_BINARY_PROTOCOL\nMEMCACHED_BEHAVIOR_SND_TIMEOUT\nMEMCACHED_BEHAVIOR_RCV_TIMEOUT\nMEMCACHED_BEHAVIOR_SERVER_FAILURE_LIMIT\nMEMCACHED_BEHAVIOR_IO_MSG_WATERMARK\nMEMCACHED_BEHAVIOR_IO_BYTES_WATERMARK\n"
#define BEHAVIORS_STRING_LENGTH 895 

#define DISTRIBUTION_TYPES_STRING "\nMEMACHED_DISTRIBUTION_MODULA\nMEMCACHED_DISTRIBUTION_CONSISTENT\nMEMCACHED_DISTRIBUTION_KETAMA"

#define DISTRIBUTION_TYPES_STRING_LENGTH 96

#define HASH_TYPES_STRING "\nMEMCACHED_HASH_DEFAULT\nMEMCACHED_HASH_MD5\nMEMCACHED_HASH_CRC\nMEMCACHED_HASH_FNV1_64\nMEMCACHED_HASH_FNV1A_64\nMEMCACHED_HASH_FNV1_32\nMEMCACHED_HASH_FNV1A_32\nMEMCACHED_HASH_JENKINS\nMEMCACHED_HASH_HSIEH\nMEMCACHED_HASH_MURMUR"

#define HASH_TYPES_STRING_LENGTH 196

