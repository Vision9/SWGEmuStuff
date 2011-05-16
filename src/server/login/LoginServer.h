/*
 *	server/login/LoginServer.h generated by engine3 IDL compiler 0.60
 */

#ifndef LOGINSERVER_H_
#define LOGINSERVER_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace conf {

class ConfigManager;

} // namespace conf
} // namespace server

using namespace server::conf;

namespace server {
namespace login {

class LoginClient;

} // namespace login
} // namespace server

using namespace server::login;

namespace server {
namespace login {

class LoginProcessServerImplementation;

} // namespace login
} // namespace server

using namespace server::login;

namespace server {
namespace login {

class LoginHandler;

} // namespace login
} // namespace server

using namespace server::login;

namespace server {
namespace login {
namespace account {

class Account;

} // namespace account
} // namespace login
} // namespace server

using namespace server::login::account;

namespace server {
namespace login {
namespace account {

class AccountManager;

} // namespace account
} // namespace login
} // namespace server

using namespace server::login::account;

namespace server {
namespace login {
namespace packets {

class LoginClusterStatus;

} // namespace packets
} // namespace login
} // namespace server

using namespace server::login::packets;

namespace server {
namespace login {
namespace packets {

class LoginEnumCluster;

} // namespace packets
} // namespace login
} // namespace server

using namespace server::login::packets;

#include "engine/service/proto/BasePacketHandler.h"

#include "engine/service/DatagramServiceThread.h"

#include "engine/service/ServiceHandler.h"

#include "engine/service/ServiceClient.h"

#include "engine/core/ManagedService.h"

#include "engine/service/Message.h"

#include "engine/log/Logger.h"

#include "system/lang/Exception.h"

#include "system/lang/ref/Reference.h"

#include "system/net/Socket.h"

#include "system/net/SocketAddress.h"

#include "system/net/Packet.h"

namespace server {
namespace login {

class LoginServer : public ManagedService {
public:
	LoginServer(ConfigManager* config);

	void initializeTransientMembers();

	LoginClient* createConnection(Socket* sock, SocketAddress& addr);

	void initialize();

	void shutdown();

	void startManagers();

	void stopManagers();

	void start(int p, int mconn = 10);

	void stop();

	void handleMessage(LoginClient* client, Packet* message);

	void processMessage(Message* message);

	bool handleError(ServiceClient* client, Exception& e);

	void printInfo();

	void populateGalaxyList();

	AccountManager* getAccountManager();

	Account* getAccount(unsigned int accountID);

	LoginClient* getLoginClient(ServiceClient* session);

	LoginEnumCluster* getLoginEnumClusterMessage();

	LoginClusterStatus* getLoginClusterStatusMessage();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	LoginServer(DummyConstructorParameter* param);

	virtual ~LoginServer();

	friend class LoginServerHelper;
};

} // namespace login
} // namespace server

using namespace server::login;

namespace server {
namespace login {

class LoginServerImplementation : public ManagedServiceImplementation, public Logger {
	Reference<DatagramServiceThread* > datagramService;

	Reference<BasePacketHandler* > phandler;

	Reference<LoginHandler* > loginHandler;

	Reference<LoginProcessServerImplementation* > processor;

	Reference<ConfigManager* > configManager;

	Reference<LoginEnumCluster* > enumClusterMessage;

	Reference<LoginClusterStatus* > clusterStatusMessage;

	Reference<AccountManager* > accountManager;

public:
	LoginServerImplementation(ConfigManager* config);

	LoginServerImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	LoginClient* createConnection(Socket* sock, SocketAddress& addr);

	void initialize();

	void shutdown();

	void startManagers();

	void stopManagers();

	void start(int p, int mconn = 10);

	void stop();

	void handleMessage(LoginClient* client, Packet* message);

	void processMessage(Message* message);

	bool handleError(ServiceClient* client, Exception& e);

	void printInfo();

	void populateGalaxyList();

	AccountManager* getAccountManager();

	Account* getAccount(unsigned int accountID);

	LoginClient* getLoginClient(ServiceClient* session);

	LoginEnumCluster* getLoginEnumClusterMessage();

	LoginClusterStatus* getLoginClusterStatusMessage();

	LoginServer* _this;

	operator const LoginServer*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~LoginServerImplementation();

	Object* clone();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class LoginServer;
	friend class TransactionalObjectHandle<LoginServerImplementation*>;
};

class LoginServerAdapter : public ManagedServiceAdapter {
public:
	LoginServerAdapter(LoginServerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	void initialize();

	void shutdown();

	void startManagers();

	void stopManagers();

	void start(int p, int mconn);

	void stop();

	void printInfo();

	void populateGalaxyList();

	Account* getAccount(unsigned int accountID);

	LoginEnumCluster* getLoginEnumClusterMessage();

	LoginClusterStatus* getLoginClusterStatusMessage();

};

class LoginServerHelper : public DistributedObjectClassHelper, public Singleton<LoginServerHelper> {
	static LoginServerHelper* staticInitializer;

public:
	LoginServerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<LoginServerHelper>;
};

} // namespace login
} // namespace server

using namespace server::login;

#endif /*LOGINSERVER_H_*/
