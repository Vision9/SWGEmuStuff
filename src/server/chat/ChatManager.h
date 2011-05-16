/*
 *	server/chat/ChatManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef CHATMANAGER_H_
#define CHATMANAGER_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class ZoneServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace chat {
namespace room {

class ChatRoom;

} // namespace room
} // namespace chat
} // namespace server

using namespace server::chat::room;

namespace server {
namespace chat {
namespace room {

class ChatRoomMap;

} // namespace room
} // namespace chat
} // namespace server

using namespace server::chat::room;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreature;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

namespace server {
namespace zone {
namespace managers {
namespace player {

class PlayerMap;

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;

namespace server {
namespace zone {
namespace managers {
namespace player {

class PlayerManager;

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatRoomList;

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatInstantMessageToCharacter;

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;

namespace server {
namespace zone {
namespace managers {
namespace objectcontroller {

class ObjectController;

} // namespace objectcontroller
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::objectcontroller;

namespace server {
namespace zone {
namespace objects {
namespace waypoint {

class WaypointObject;

} // namespace waypoint
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::waypoint;

#include "server/chat/StringIdChatParameter.h"

#include "server/chat/WaypointChatParameter.h"

#include "server/chat/StringIdChatParameterVector.h"

#include "server/chat/WaypointChatParameterVector.h"

#include "engine/core/ManagedService.h"

#include "engine/service/proto/BaseMessage.h"

#include "system/util/VectorMap.h"

#include "system/util/HashTable.h"

#include "engine/log/Logger.h"

namespace server {
namespace chat {

class ChatManager : public ManagedService {
public:
	static const int IM_SUCCESS = 0x00;

	static const int IM_OFFLINE = 0x04;

	static const int IM_IGNORED = 0x09;

	static const int IM_TOOLONG = 0x16;

	static const int IM_MAXSIZE = 255;

	static const int PM_MAXSIZE = 4000;

	ChatManager(ZoneServer* serv, int initsize);

	void initiateRooms();

	void destroyRooms();

	ChatRoom* createRoom(const String& roomName, ChatRoom* parent = NULL);

	void addRoom(ChatRoom* channel);

	void removeRoom(ChatRoom* channel);

	void populateRoomListMessage(ChatRoom* channel, ChatRoomList* msg);

	void sendRoomList(PlayerCreature* player);

	void addPlayer(PlayerCreature* player);

	PlayerCreature* getPlayer(const String& name);

	PlayerCreature* removePlayer(const String& name);

	void broadcastMessage(BaseMessage* message);

	void broadcastMessage(CreatureObject* player, const UnicodeString& message, unsigned long long target = 0, unsigned int moodid = 0, unsigned int mood2 = 0);

	void handleSpatialChatInternalMessage(PlayerCreature* player, const UnicodeString& args);

	void handleGroupChat(PlayerCreature* player, const UnicodeString& message);

	ChatRoom* createRoomByFullPath(const String& path);

	ChatRoom* getChatRoomByFullPath(const String& path);

	ChatRoom* getChatRoomByGamePath(ChatRoom* game, const String& path);

	void handleChatRoomMessage(PlayerCreature* sender, const UnicodeString& message, unsigned int roomID, unsigned int counter);

	void handleChatEnterRoomById(PlayerCreature* player, unsigned int counter, unsigned int roomID);

	void handleSocialInternalMessage(CreatureObject* sender, const UnicodeString& arguments);

	void handleChatInstantMessageToCharacter(ChatInstantMessageToCharacter* message);

	void destroyRoom(ChatRoom* room);

	ChatRoom* createGroupRoom(unsigned long long groupID, PlayerCreature* creator);

	void loadMail(PlayerCreature* player);

	void sendMail(const String& sendername, const UnicodeString& header, const UnicodeString& body, const String& name);

	int sendMail(const String& sendername, const UnicodeString& subject, StringIdChatParameter& body, const String& recipientName, WaypointObject* waypoint = NULL);

	int sendMail(const String& sendername, const UnicodeString& subject, const UnicodeString& body, const String& recipientName, StringIdChatParameterVector* stringIdParameters, WaypointChatParameterVector* waypointParameters);

	void handleRequestPersistentMsg(PlayerCreature* player, unsigned int mailID);

	void deletePersistentMessage(PlayerCreature* player, unsigned int mailID);

	void broadcastGalaxy(PlayerCreature* player, const String& message);

	void setPlayerManager(PlayerManager* manager);

	ChatRoom* getChatRoom(unsigned int id);

	ChatRoom* getGameRoom(const String& game);

	unsigned int getNextRoomID();

	int getPlayerCount();

	PlayerMap* getPlayerMap();

	ChatRoom* getGuildRoom();

	ChatRoom* getGroupRoom();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	ChatManager(DummyConstructorParameter* param);

	virtual ~ChatManager();

	friend class ChatManagerHelper;
};

} // namespace chat
} // namespace server

using namespace server::chat;

namespace server {
namespace chat {

class ChatManagerImplementation : public ManagedServiceImplementation, public Logger {
	ManagedWeakReference<ZoneServer* > server;

	ManagedWeakReference<PlayerManager* > playerManager;

	Reference<PlayerMap* > playerMap;

	VectorMap<String, ManagedReference<ChatRoom* > > gameRooms;

	ManagedReference<ChatRoom* > groupRoom;

	ManagedReference<ChatRoom* > guildRoom;

	Reference<ChatRoomMap* > roomMap;

	unsigned int roomID;

	bool mute;

public:
	static const int IM_SUCCESS = 0x00;

	static const int IM_OFFLINE = 0x04;

	static const int IM_IGNORED = 0x09;

	static const int IM_TOOLONG = 0x16;

	static const int IM_MAXSIZE = 255;

	static const int PM_MAXSIZE = 4000;

	ChatManagerImplementation(ZoneServer* serv, int initsize);

	ChatManagerImplementation(DummyConstructorParameter* param);

	void finalize();

	void initiateRooms();

	void destroyRooms();

	ChatRoom* createRoom(const String& roomName, ChatRoom* parent = NULL);

	void addRoom(ChatRoom* channel);

	void removeRoom(ChatRoom* channel);

	void populateRoomListMessage(ChatRoom* channel, ChatRoomList* msg);

	void sendRoomList(PlayerCreature* player);

	void addPlayer(PlayerCreature* player);

	PlayerCreature* getPlayer(const String& name);

	PlayerCreature* removePlayer(const String& name);

	void broadcastMessage(BaseMessage* message);

	void broadcastMessage(CreatureObject* player, const UnicodeString& message, unsigned long long target = 0, unsigned int moodid = 0, unsigned int mood2 = 0);

	void handleSpatialChatInternalMessage(PlayerCreature* player, const UnicodeString& args);

	void handleGroupChat(PlayerCreature* player, const UnicodeString& message);

	ChatRoom* createRoomByFullPath(const String& path);

	ChatRoom* getChatRoomByFullPath(const String& path);

	ChatRoom* getChatRoomByGamePath(ChatRoom* game, const String& path);

	void handleChatRoomMessage(PlayerCreature* sender, const UnicodeString& message, unsigned int roomID, unsigned int counter);

	void handleChatEnterRoomById(PlayerCreature* player, unsigned int counter, unsigned int roomID);

	void handleSocialInternalMessage(CreatureObject* sender, const UnicodeString& arguments);

	void handleChatInstantMessageToCharacter(ChatInstantMessageToCharacter* message);

	void destroyRoom(ChatRoom* room);

	ChatRoom* createGroupRoom(unsigned long long groupID, PlayerCreature* creator);

	void loadMail(PlayerCreature* player);

	void sendMail(const String& sendername, const UnicodeString& header, const UnicodeString& body, const String& name);

	int sendMail(const String& sendername, const UnicodeString& subject, StringIdChatParameter& body, const String& recipientName, WaypointObject* waypoint = NULL);

	int sendMail(const String& sendername, const UnicodeString& subject, const UnicodeString& body, const String& recipientName, StringIdChatParameterVector* stringIdParameters, WaypointChatParameterVector* waypointParameters);

	void handleRequestPersistentMsg(PlayerCreature* player, unsigned int mailID);

	void deletePersistentMessage(PlayerCreature* player, unsigned int mailID);

	void broadcastGalaxy(PlayerCreature* player, const String& message);

	void setPlayerManager(PlayerManager* manager);

	ChatRoom* getChatRoom(unsigned int id);

	ChatRoom* getGameRoom(const String& game);

	unsigned int getNextRoomID();

	int getPlayerCount();

	PlayerMap* getPlayerMap();

	ChatRoom* getGuildRoom();

	ChatRoom* getGroupRoom();

	ChatManager* _this;

	operator const ChatManager*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~ChatManagerImplementation();

	Object* clone();

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

	friend class ChatManager;
	friend class TransactionalObjectHandle<ChatManagerImplementation*>;
};

class ChatManagerAdapter : public ManagedServiceAdapter {
public:
	ChatManagerAdapter(ChatManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void finalize();

	void initiateRooms();

	void destroyRooms();

	ChatRoom* createRoom(const String& roomName, ChatRoom* parent);

	void addRoom(ChatRoom* channel);

	void removeRoom(ChatRoom* channel);

	void populateRoomListMessage(ChatRoom* channel, ChatRoomList* msg);

	void sendRoomList(PlayerCreature* player);

	void addPlayer(PlayerCreature* player);

	PlayerCreature* getPlayer(const String& name);

	PlayerCreature* removePlayer(const String& name);

	void broadcastMessage(BaseMessage* message);

	void broadcastMessage(CreatureObject* player, const UnicodeString& message, unsigned long long target, unsigned int moodid, unsigned int mood2);

	void handleSpatialChatInternalMessage(PlayerCreature* player, const UnicodeString& args);

	void handleGroupChat(PlayerCreature* player, const UnicodeString& message);

	ChatRoom* createRoomByFullPath(const String& path);

	ChatRoom* getChatRoomByFullPath(const String& path);

	ChatRoom* getChatRoomByGamePath(ChatRoom* game, const String& path);

	void handleChatRoomMessage(PlayerCreature* sender, const UnicodeString& message, unsigned int roomID, unsigned int counter);

	void handleChatEnterRoomById(PlayerCreature* player, unsigned int counter, unsigned int roomID);

	void handleSocialInternalMessage(CreatureObject* sender, const UnicodeString& arguments);

	void destroyRoom(ChatRoom* room);

	ChatRoom* createGroupRoom(unsigned long long groupID, PlayerCreature* creator);

	void loadMail(PlayerCreature* player);

	void sendMail(const String& sendername, const UnicodeString& header, const UnicodeString& body, const String& name);

	void handleRequestPersistentMsg(PlayerCreature* player, unsigned int mailID);

	void deletePersistentMessage(PlayerCreature* player, unsigned int mailID);

	void broadcastGalaxy(PlayerCreature* player, const String& message);

	void setPlayerManager(PlayerManager* manager);

	ChatRoom* getChatRoom(unsigned int id);

	ChatRoom* getGameRoom(const String& game);

	unsigned int getNextRoomID();

	int getPlayerCount();

	ChatRoom* getGuildRoom();

	ChatRoom* getGroupRoom();

protected:
	String _param0_createRoom__String_ChatRoom_;
	String _param0_getPlayer__String_;
	String _param0_removePlayer__String_;
	UnicodeString _param1_broadcastMessage__CreatureObject_UnicodeString_long_int_int_;
	UnicodeString _param1_handleSpatialChatInternalMessage__PlayerCreature_UnicodeString_;
	UnicodeString _param1_handleGroupChat__PlayerCreature_UnicodeString_;
	String _param0_createRoomByFullPath__String_;
	String _param0_getChatRoomByFullPath__String_;
	String _param1_getChatRoomByGamePath__ChatRoom_String_;
	UnicodeString _param1_handleChatRoomMessage__PlayerCreature_UnicodeString_int_int_;
	UnicodeString _param1_handleSocialInternalMessage__CreatureObject_UnicodeString_;
	String _param0_sendMail__String_UnicodeString_UnicodeString_String_;
	UnicodeString _param1_sendMail__String_UnicodeString_UnicodeString_String_;
	UnicodeString _param2_sendMail__String_UnicodeString_UnicodeString_String_;
	String _param3_sendMail__String_UnicodeString_UnicodeString_String_;
	String _param1_broadcastGalaxy__PlayerCreature_String_;
	String _param0_getGameRoom__String_;
};

class ChatManagerHelper : public DistributedObjectClassHelper, public Singleton<ChatManagerHelper> {
	static ChatManagerHelper* staticInitializer;

public:
	ChatManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<ChatManagerHelper>;
};

} // namespace chat
} // namespace server

using namespace server::chat;

#endif /*CHATMANAGER_H_*/
