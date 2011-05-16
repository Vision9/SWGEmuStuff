/*
 *	server/zone/objects/tangible/terminal/bank/BankTerminal.cpp generated by engine3 IDL compiler 0.60
 */

#include "BankTerminal.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/player/sui/banktransferbox/SuiBankTransferBox.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/Zone.h"


// Imported class dependencies

#include "server/zone/objects/cell/CellObject.h"

#include "engine/service/proto/BasePacket.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"

#include "system/io/ObjectOutputStream.h"

#include "server/zone/ZonePacketHandler.h"

#include "engine/service/DatagramServiceThread.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/managers/mission/MissionManager.h"

#include "engine/util/Facade.h"

#include "engine/util/u3d/Coordinate.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/managers/player/PlayerManager.h"

#include "system/thread/atomic/AtomicInteger.h"

#include "server/chat/room/ChatRoom.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "engine/util/Observable.h"

#include "engine/util/u3d/Quaternion.h"

#include "server/zone/objects/draftschematic/DraftSchematic.h"

#include "engine/service/Message.h"

#include "server/zone/managers/radial/RadialManager.h"

#include "server/login/account/Account.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/chat/ChatManager.h"

#include "server/zone/managers/minigames/ForageManager.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "server/zone/objects/player/sui/SuiCallback.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "system/io/ObjectInputStream.h"

#include "engine/util/ObserverEventMap.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "server/zone/managers/resource/ResourceManager.h"

#include "engine/util/u3d/QuadTreeNode.h"

#include "server/zone/objects/manufactureschematic/IngredientSlots.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "engine/core/Task.h"

#include "server/zone/managers/guild/GuildManager.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/managers/city/CityManager.h"

#include "engine/util/Observer.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/ZoneHandler.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

#include "engine/core/ManagedObject.h"

#include "server/zone/ZoneProcessServer.h"

#include "engine/service/proto/BasePacketHandler.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/managers/minigames/GamblingManager.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/managers/creature/CreatureTemplateManager.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "server/zone/managers/minigames/FishingManager.h"

#include "system/lang/Exception.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "server/zone/packets/ui/SuiCreatePageMessage.h"

#include "system/lang/Time.h"

#include "server/zone/ZoneClientSession.h"

#include "engine/util/u3d/QuadTree.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "system/net/Packet.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "engine/stm/TransactionalReference.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "system/net/SocketAddress.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "server/zone/managers/auction/AuctionManager.h"

#include "server/zone/managers/loot/LootManager.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/managers/professions/ProfessionManager.h"

#include "system/util/VectorMap.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

#include "server/zone/managers/planet/PlanetManager.h"

#include "server/zone/managers/stringid/StringIdManager.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "server/zone/managers/crafting/CraftingManager.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "system/net/Socket.h"

#include "system/util/Vector.h"

/*
 *	BankTerminalStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6,RPC_FILLOBJECTMENURESPONSE__OBJECTMENURESPONSE_PLAYERCREATURE_,RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_};

BankTerminal::BankTerminal() : Terminal(DummyConstructorParameter::instance()) {
	BankTerminalImplementation* _implementation = new BankTerminalImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

BankTerminal::BankTerminal(DummyConstructorParameter* param) : Terminal(param) {
}

BankTerminal::~BankTerminal() {
}


void BankTerminal::initializeTransientMembers() {
	BankTerminalImplementation* _implementation = (BankTerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

void BankTerminal::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player) {
	BankTerminalImplementation* _implementation = (BankTerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_FILLOBJECTMENURESPONSE__OBJECTMENURESPONSE_PLAYERCREATURE_);
		method.addObjectParameter(menuResponse);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->fillObjectMenuResponse(menuResponse, player);
}

int BankTerminal::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	BankTerminalImplementation* _implementation = (BankTerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->handleObjectMenuSelect(player, selectedID);
}

DistributedObjectServant* BankTerminal::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void BankTerminal::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<BankTerminalImplementation*>(servant));
}

/*
 *	BankTerminalImplementation
 */

BankTerminalImplementation::BankTerminalImplementation(DummyConstructorParameter* param) : TerminalImplementation(param) {
	_initializeImplementation();
}


BankTerminalImplementation::~BankTerminalImplementation() {
}


void BankTerminalImplementation::finalize() {
}

void BankTerminalImplementation::_initializeImplementation() {
	_setClassHelper(BankTerminalHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void BankTerminalImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (BankTerminal*) stub;
	TerminalImplementation::_setStub(stub);
}

DistributedObjectStub* BankTerminalImplementation::_getStub() {
	return _this;
}

BankTerminalImplementation::operator const BankTerminal*() {
	return _this;
}

Object* BankTerminalImplementation::clone() {
	return dynamic_cast<Object*>(new BankTerminalImplementation(*this));
}


void BankTerminalImplementation::lock(bool doLock) {
}

void BankTerminalImplementation::lock(ManagedObject* obj) {
}

void BankTerminalImplementation::rlock(bool doLock) {
}

void BankTerminalImplementation::wlock(bool doLock) {
}

void BankTerminalImplementation::wlock(ManagedObject* obj) {
}

void BankTerminalImplementation::unlock(bool doLock) {
}

void BankTerminalImplementation::runlock(bool doLock) {
}

void BankTerminalImplementation::_serializationHelperMethod() {
	TerminalImplementation::_serializationHelperMethod();

	_setClassName("BankTerminal");

}

void BankTerminalImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(BankTerminalImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool BankTerminalImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TerminalImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void BankTerminalImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = BankTerminalImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int BankTerminalImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + TerminalImplementation::writeObjectMembers(stream);
}

BankTerminalImplementation::BankTerminalImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/terminal/bank/BankTerminal.idl():  		Logger.setLoggingName("BankTerminal");
	Logger::setLoggingName("BankTerminal");
}

void BankTerminalImplementation::initializeTransientMembers() {
	// server/zone/objects/tangible/terminal/bank/BankTerminal.idl():  		super.initializeTransientMembers();
	TerminalImplementation::initializeTransientMembers();
	// server/zone/objects/tangible/terminal/bank/BankTerminal.idl():  		Logger.setLoggingName("BankTerminal");
	Logger::setLoggingName("BankTerminal");
}

void BankTerminalImplementation::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player) {
	// server/zone/objects/tangible/terminal/bank/BankTerminal.idl():  		menuResponse.addRadialMenuItem(245, 3, "@sui:bank_items");
	menuResponse->addRadialMenuItem(245, 3, "@sui:bank_items");
}

int BankTerminalImplementation::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	// server/zone/objects/tangible/terminal/bank/BankTerminal.idl():  			return 1;
	if (selectedID == 245){
	// server/zone/objects/tangible/terminal/bank/BankTerminal.idl():  			SceneObject bank = player.getSlottedObject("bank");
	SceneObject* bank = player->getSlottedObject("bank");
	// server/zone/objects/tangible/terminal/bank/BankTerminal.idl():  			bank.openContainerTo(player);
	bank->openContainerTo(player);
}

	else 	// server/zone/objects/tangible/terminal/bank/BankTerminal.idl():  			return 1;
	if (selectedID == 20){
	ManagedReference<SuiBankTransferBox*> _ref0;
	// server/zone/objects/tangible/terminal/bank/BankTerminal.idl():  			SuiBankTransferBox sui = new SuiBankTransferBox(this, player, SuiWindowType.BANK_TRANSFER);
	SuiBankTransferBox* sui = _ref0 = new SuiBankTransferBox(_this, player, SuiWindowType::BANK_TRANSFER);
	// server/zone/objects/tangible/terminal/bank/BankTerminal.idl():  			sui.addCash(player.getCashCredits());
	sui->addCash(player->getCashCredits());
	// server/zone/objects/tangible/terminal/bank/BankTerminal.idl():  			sui.addBank(player.getBankCredits());
	sui->addBank(player->getBankCredits());
	// server/zone/objects/tangible/terminal/bank/BankTerminal.idl():  			player.addSuiBox(sui);
	player->addSuiBox(sui);
	// server/zone/objects/tangible/terminal/bank/BankTerminal.idl():  			player.sendMessage(sui.generateMessage());
	player->sendMessage(sui->generateMessage());
}

	else 	// server/zone/objects/tangible/terminal/bank/BankTerminal.idl():  			return 1;
	return 1;
	// server/zone/objects/tangible/terminal/bank/BankTerminal.idl():  		return 0;
	return 0;
}

/*
 *	BankTerminalAdapter
 */

BankTerminalAdapter::BankTerminalAdapter(BankTerminalImplementation* obj) : TerminalAdapter(obj) {
}

Packet* BankTerminalAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		initializeTransientMembers();
		break;
	case RPC_FILLOBJECTMENURESPONSE__OBJECTMENURESPONSE_PLAYERCREATURE_:
		fillObjectMenuResponse((ObjectMenuResponse*) inv->getObjectParameter(), (PlayerCreature*) inv->getObjectParameter());
		break;
	case RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

void BankTerminalAdapter::initializeTransientMembers() {
	((BankTerminalImplementation*) impl)->initializeTransientMembers();
}

void BankTerminalAdapter::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player) {
	((BankTerminalImplementation*) impl)->fillObjectMenuResponse(menuResponse, player);
}

int BankTerminalAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((BankTerminalImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

/*
 *	BankTerminalHelper
 */

BankTerminalHelper* BankTerminalHelper::staticInitializer = BankTerminalHelper::instance();

BankTerminalHelper::BankTerminalHelper() {
	className = "BankTerminal";

	Core::getObjectBroker()->registerClass(className, this);
}

void BankTerminalHelper::finalizeHelper() {
	BankTerminalHelper::finalize();
}

DistributedObject* BankTerminalHelper::instantiateObject() {
	return new BankTerminal(DummyConstructorParameter::instance());
}

DistributedObjectServant* BankTerminalHelper::instantiateServant() {
	return new BankTerminalImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* BankTerminalHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new BankTerminalAdapter((BankTerminalImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

